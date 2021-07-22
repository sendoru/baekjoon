#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;
typedef long long ll;

void dfs(vector<ll>& a, int curIndex, int remaining, ll& ans)
{
	if (curIndex == 1 && remaining > 0)
	{
		ans++;
		ans %= MOD;
		return;
	}
	else if (curIndex == 1 || remaining == 0 || remaining < curIndex)
	{
		return;
	}
	ll bkSum = 0;
	while (remaining >= curIndex)
	{
		bkSum += a[remaining];
		bkSum %= curIndex;
		remaining--;
		if (bkSum == 0)
		{
			dfs(a, curIndex - 1, remaining, ans);
		}
	}
	return;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<ll> a(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	ll ans = 1;
	for (int i = 2; i <= n; i++)
	{
		dfs(a, i, n, ans);
	}
	cout << ans << '\n';
	return 0;
}