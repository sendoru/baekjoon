#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	// a: 만족도, b: 지불 비용
	// (a[i] - b[i])의 합을 최대화
	vector<ll> a(n), b(m);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
	}


	sort(a.begin(), a.end(), greater<ll>());
	sort(b.begin(), b.end());

	ll ans = 0;
	for (int i = 0; i < min(n, m); i++)
	{
		if (a[i] - b[i] < 0)
			break;
		ans += a[i] - b[i];
	}

	cout << ans;
	return 0;
}