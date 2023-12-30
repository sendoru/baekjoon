#include <iostream>
#include <vector>
#include <string>
#define MOD 1000003
using namespace std;
typedef long long ll;

vector<vector<ll>> mulMatrix(vector<vector<ll>> matrix1, vector<vector<ll>> matrix2, ll mod)
{
	int n = matrix1.size();
	vector<vector<ll>> ret(n, vector<ll>(n));

	for (int r = 0; r < n; r++)
		for (int c = 0; c < n; c++)
			for (int i = 0; i < n; i++)
			{
				ret[r][c] += matrix1[r][i] * matrix2[i][c];
				ret[r][c] %= mod;
			}

	return ret;
}

vector<vector<ll>> modPowMatrix(vector<vector<ll>>& matrix, ll exp, ll mod)
{
	if (exp == 1) return matrix;
	vector<vector<ll>> partial = modPowMatrix(matrix, exp / 2, mod);
	if (exp & 1) return mulMatrix(mulMatrix(partial, partial, mod), matrix, mod);
	return mulMatrix(partial, partial, mod);
}

int main(void)
{
	ll n, s, e, t;
	cin >> n >> s >> e >> t;
	vector<vector<ll>> adjList(5 * n + 1);
	for (int i = 1; i <= n; i++)
	{
		string tmp;
		cin >> tmp;
		adjList[i].push_back(n + 1 + 4 * (i - 1));
		for (int j = 0; j < 3; j++)
		{
			adjList[n + 1 + 4 * (i - 1) + j].push_back(n + 1 + 4 * (i - 1) + j + 1);
		}
		for (int j = 1; j <= n; j++)
		{
			if (tmp[j - 1] - '0' == 1)
			{
				adjList[i].push_back(j);
			}
			else if (tmp[j - 1] - '0' > 1)
			{
				adjList[n + 1 + 4 * (i - 1) + tmp[j - 1] - '0' - 2].push_back(j);
			}
		}
	}

	vector<vector<ll>> adjMatrix(5 * n + 1, vector<ll>(5 * n + 1, 0));
	for (int i = 0; i < 5 * n + 1; i++)
	{
		for (ll elem : adjList[i])
		{
			adjMatrix[i][elem] = 1;
		}
	}

	vector<vector<ll>> ans = modPowMatrix(adjMatrix, t, MOD);
	cout << ans[s][e] % MOD;

	return 0;
}