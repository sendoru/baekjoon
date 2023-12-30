#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int n, x;
	cin >> n >> x;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int costSum = 0;
	for (int i = 1; i <= n; i++)
	{
		costSum += a[i];
		if (i % 2 == 0)
		{
			costSum--;
		}
	}
	if (x >= costSum)
	{
		cout << "Yes" << '\n';
	}
	else
	{
		cout << "No" << '\n';
	}
	return 0;
}