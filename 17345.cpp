#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
#define MAX 500005

using namespace std;
typedef long long ll;

void makeSparseTable(vector<vector<int>>& sparseTable, vector<int>& f)
{
	for (int i = 0; i < f.size(); i++)
	{
		sparseTable[0][i] = f[i];
	}
	for (int i = 1; i < sparseTable.size(); i++)
	{
		for (int j = 0; j < sparseTable[i].size(); j++)
		{
			sparseTable[i][j] = sparseTable[i - 1][sparseTable[i - 1][j]];
		}
	}
}

int main(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int m;
	cin >> m;
	vector<int> f(m + 1);
	vector<vector<int>> sparseTable((int)(ceil(log2(MAX))), vector<int>(m + 1));
	for (int i = 1; i <= m; i++)
	{
		cin >> f[i];
	}

	makeSparseTable(sparseTable, f);

	int q;
	cin >> q;
	while (q--)
	{
		int n, x;
		cin >> n >> x;
		for (int i = 0; i < (int)(ceil(log2(MAX))); i++)
		{
			if (n & (1 << i))
			{
				x = sparseTable[i][x];
			}
		}
		cout << x << '\n';
	}

	return 0;
}