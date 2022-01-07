#include <iostream>
#include <algorithm>

using namespace std;

int arr[10000001];

int check(int i, int x)
{
	if (i <= x)
	{
		if (i % 6 == 0)
		{
			arr[i] = min(min(arr[i / 3], arr[i / 2]), arr[i - 1]) + 1;
		}
		else if (i % 3 == 0)
		{
			arr[i] = min(arr[i / 3], arr[i - 1]) + 1;
		}
		else if (i % 2 == 0)
		{
			arr[i] = min(arr[i / 2], arr[i - 1]) + 1;
		}
		else
		{
			arr[i] = arr[i - 1] + 1;
		}
		check(i + 1, x);
	}
	if (i == 2) return arr[x];

}

int main()
{
	int N;
	cin >> N;
	if (N == 1)
		arr[1] = 0;
	else
		check(2, N);
	cout << arr[N] << endl;
	return 0;

}

