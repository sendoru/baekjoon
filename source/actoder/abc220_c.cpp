#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	ll x;
	cin >> x;
	vector<ll> aSum(n);
	aSum[0] = a[0];
	for (int i = 1; i < n; i++) aSum[i] = aSum[i - 1] + a[i];

	ll ans = 0;
	ans += a.size() * (x / aSum.back());
	ll curSum = (x / aSum.back()) * aSum.back();
	ll idx = 0;
	while (curSum <= x)
	{
		curSum += a[idx];
		idx++;
		ans++;
	}
	cout << ans;
	return 0;
}