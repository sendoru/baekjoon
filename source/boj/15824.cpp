#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007ll
#define MAX 300000ll

using namespace std;
typedef long long ll;
// mods[i] := (2**i - 1) % MOD
ll mods[MAX + 1];

ll modPow(ll base, ll exp)
{
	ll ret = 1;
	while (exp > 0)
	{
		if (exp % 2 == 1)
		{
			ret *= base;
			ret %= MOD;
		}
		base *= base;
		base %= MOD;
		exp /= 2;
	}
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	mods[0] = 0;
	for (int i = 1; i <= MAX; i++)
	{
		mods[i] = (mods[i - 1] * 2 + 1) % MOD;
	}

	ll n, ans = 0;
	cin >> n;
	vector<ll> menu(n);
	
	for (int i = 0; i < n; i++)
	{
		cin >> menu[i];
	}
	sort(menu.begin(), menu.end());
	for (int i = 0; i < n; i++)
	{
		ans += MOD - (menu[i] * mods[n - 1 - i]) % MOD;
		ans += (menu[i] * mods[i]) % MOD;
		ans %= MOD;
	}
	cout << ans << '\n';
	return 0;
}