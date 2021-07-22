#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

vector<ll> expandByP(ll n, ll p)
{
	vector<ll> ret;
	while (n > 0)
	{
		ret.push_back(n % p);
		n /= p;
	}
	return ret;
}

int main(void)
{
	ll n, k, p;
	cin >> n >> k >> p;
	vector<vector<ll>> combinations(p + 1, vector<ll>(p + 1));
	combinations[0][0] = 0;
	for (int i = 0; i <= p; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
			{
				combinations[i][0] = 1;
			}
			else
			{
				combinations[i][j] = (combinations[i - 1][j - 1] + combinations[i - 1][j]) % p;
			}
		}
	}

	vector<ll> nExp = expandByP(n, p);
	vector<ll> kExp = expandByP(k, p);
	
	ll ans = 1;
	for (int i = 0; i < min(nExp.size(), kExp.size()); i++)
	{
		ans *= combinations[nExp[i]][kExp[i]];
		ans %= p;
	}

	cout << ans << '\n';

	return 0;
}