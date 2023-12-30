#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
typedef long double ld;
typedef long long ll;
const ld INF = 1e9;
using namespace std;

int main(void)
{
	ll x, a, d, n;
	cin >> x >> a >> d >> n;

	// 수열 S: a가 초항, d가 공차, n이 항 갯수
	// x가 S의 원소여야 함
	// S의 마지막 항: a + (n - 1) * d

	if (d == 0)
	{
		cout << abs(x - a);
		return 0;
	}

	if (d < 0)
	{
		ll newA = a + (n - 1) * d;
		ll newD = -d;

		a = newA;
		d = newD;
	}

	// 이제 S는 무조건 증가수열이다
	if (x < a)
		cout << abs(x - a);

	else if (x > a + (n - 1) * d)
		cout << abs(x - (a + (n - 1) * d));

	// x가 S의 최솟값과 최댓값 사이인 경우
	else
	{
		x -= a;
		a = 0;
		ll ans = x % d;
		ans = min(ans, d - ans);
		cout << ans;
	}
	return 0;
}