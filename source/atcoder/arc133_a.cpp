#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
typedef long long ll;
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int removed = a.back();
	// O(N)이면 풀수는 있음
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] > a[i + 1])
		{
			removed = a[i];
			break;
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (a[i] != removed)
		{
			cout << a[i] << ' ';
		}
	}

	return 0;
}