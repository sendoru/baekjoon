#include <iostream>
using namespace std;

int main(void)
{
	int a, b, n, w;
	cin >> a >> b >> n >> w;
	int ans1 = 0, ans2 = 0;
	if (a - b != 0)
	{
		if ((w - a * n) % (b - a) == 0 && (w - a * n) / (b - a) >= 1 && (b * n - w) % (b - a) == 0 && (b * n - w) / (b - a) >= 1)
		{
			ans1 = (b * n - w) / (b - a);
			ans2 = (w - a * n) / (b - a);
		}
	}
	else
	{
		if (w % a == 0 && w / a == 2 && n == 2)
		{
			ans1 = 1;
			ans2 = 1;
		}
	}
	if (ans1 == 0)
	{
		cout << -1;
	}
	else
	{
		cout << ans1 << ' ' << ans2;
	}
	return 0;
}