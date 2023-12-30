#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
constexpr ll MOD = 1e9 + 7;

vector<vector<ll>> eye(ll n)
{
	vector<vector<ll>> ret(n, vector<ll>(n));
	for (int i = 0; i < n; i++)
		ret[i][i] = 1;
	return ret;
}

vector<vector<ll>> matMul(vector<vector<ll>> a, vector<vector<ll>> b)
{
	if (a.size() == 0 || a[0].size() != b.size())
	{
		return { {} };
	}
	vector<vector<ll>> ret(a.size(), vector<ll>(b[0].size()));
	ll rCnt = a.size(), cCnt = b.size();
	// a에서 몇번째 행인가?
	for (int i = 0; i < a.size(); i++)
	{
		// b에서 몇번째 열인가?
		for (int j = 0; j < b[0].size(); j++)
		{
			for (int k = 0; k < a[i].size(); k++)
			{
				ret[i][j] += a[i][k] * b[k][j];
				ret[i][j] %= MOD;
			}
		}
	}

	return ret;
}

vector<vector<ll>> matPow(vector<vector<ll>> base, ll pow)
{
	if (pow == 0)
		return eye(base.size());
	if (pow == 1)
		return base;

	auto half = matPow(base, pow / 2);

	if (pow % 2 == 0)
		return matMul(half, half);
	else
		return matMul(base, matMul(half, half));
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll t, n, d;
	cin >> t >> n >> d;
	vector<vector<vector<ll>>> adjMat(t, vector<vector<ll>>(n, vector<ll>(n)));
	for (int i = 0; i < t; i++)
	{
		ll m;
		cin >> m;
		for (int j = 0; j < m; j++)
		{
			ll s, e, cnt;
			cin >> s >> e >> cnt;
			s--;
			e--;

			adjMat[i][s][e] = cnt;
		}
	}

	vector<vector<ll>> allProd = eye(n);
	for (int i = 0; i < t; i++)
		allProd = matMul(allProd, adjMat[i]);

	vector<vector<ll>> ans = matPow(allProd, d / t);
	for (int i = 0; i < d % t; i++)
		ans = matMul(ans, adjMat[i]);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
