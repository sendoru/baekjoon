#include <iostream>

using namespace std;

int main(void)
{
	int a, b, c;
	cin >> a >> b >> c;
	if (a == b)
	{
		cout << c << '\n';
	}
	else if (a == c)
	{
		cout << b << '\n';
	}
	else if (b == c)
	{
		cout << a << '\n';
	}
	else
	{
		cout << 0 << '\n';
	}
	return 0;
}