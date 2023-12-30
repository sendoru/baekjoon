#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

int main(void)
{
	ll n;
	cin >> n;
	vector<int> a(n);
	for (int& elem : a)
		cin >> elem;

	vector<int> square(4);
	int p = 0;
	for (int i = 0; i < n; i++)
	{
		square[0]++;
		for (int j = 3; j >= 0; j--)
		{
			if (j + a[i] >= 4)
			{
				p += square[j];
				square[j] = 0;
			}
			else
			{
				square[j + a[i]] += square[j];
				square[j] = 0;
			}
		}
	}

	cout << p;
	return 0;
}