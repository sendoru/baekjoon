#include <iostream>
using namespace std;

int main(void)
{
	int a, b;
	cin >> a >> b;
	if (a > b)
	{
		cout << 0 << '\n';
	}
	else
	{
		cout << b - a + 1 << '\n';
	}
	return 0;
}