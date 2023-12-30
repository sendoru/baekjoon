#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int w, n;
	cin >> w >> n;
	vector<int> a(n);
	vector<bool> cache(w + 1, false);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int wSum = a[i] + a[j];
			if (wSum <= w && cache[w - wSum])
			{
				cout << "YES";
				return 0;
			}
		}
		for (int j = i - 1; j >= 0; j--)
		{
			int wSum = a[i] + a[j];
			if (wSum <= w)
				cache[wSum] = true;
		}
	}
	cout << "NO";
	return 0;
}