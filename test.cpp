#include <iostream>

using namespace std;

int main(void)
{
	for (int i = 0; i < 100; i++)
	{
		cout << i << " = " << i / -3 << " * (-3) + " << i % -3 << '\n';
	}

	return 0;
}