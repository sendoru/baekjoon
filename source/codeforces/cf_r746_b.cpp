#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		int n, x;
		cin >> n >> x;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];

		// 처음부터 정렬되어 있는 경우
		bool ans = true;
		for (int i = 1; i < n; i++)
		{
			if (a[i - 1] > a[i])
			{
				ans = false;
				break;
			}
		}

		if (x <= n / 2) ans = true;
		if (ans)
		{
			cout << "YES\n";
			continue;
		}

		ans = true;
		vector<int> sorted(n);

		for (int i = 0; i < n; i++) sorted[i] = a[i];
		sort(sorted.begin(), sorted.end());
		for (int i = n - x; i < x; i++)
		{
			if (a[i] != sorted[i])
			{
				ans = false;
				break;
			}
		}

		cout << (ans ? "YES" : "NO") << '\n';
	}
	return 0;
}