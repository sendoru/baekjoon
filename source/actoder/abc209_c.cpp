#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> c(n);
	for (int i = 0; i < n; i++)
	{
		cin >> c[i];
	}
	sort(c.begin(), c.end());
	ll ans = 1;
	for (int i = 0; i < n; i++)
	{
		if (c[i] - i <= 0)
		{
			ans = 0;
			break;
		}
		ans *= c[i] - i;
		ans %= MOD;
	}
	cout << ans << '\n';
	return 0;
}