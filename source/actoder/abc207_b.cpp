#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (b / c >= d)
	{
		cout << -1 << '\n';
		return 0;
	}
	if (a % (c * d - b) == 0)
	{
		cout << a / (c * d - b) << '\n';
	}
	else
	{
		cout << a / (c * d - b) + 1 << '\n';
	}
	return 0;
}