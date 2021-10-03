#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		int m, n, x, y;
		cin >> m >> n >> x >> y;
		x--; y--;
		int ans = -2;
		for (int i = 0; m * i + x <= m * n; i++)
		{
			if ((m * i + x - y) % n == 0)
			{
				ans = m * i + x;
				break;
			}
		}
		cout << ans + 1 << '\n';
	}

	return 0;
}