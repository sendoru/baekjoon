#include <iostream>

using namespace std;

int main(void)
{
	int n, m, ans = 0;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			ans += 100 * i + j;
		}
	}
	cout << ans << '\n';
	return 0;
}