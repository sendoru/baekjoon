#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100010;

int main(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> a(n), aSorted(n);
		vector<vector<int>> pos(MAX, vector<int>(2)), posSorted(MAX, vector<int>(2));
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			pos[a[i]][i % 2]++;
		}
		aSorted = a;
		sort(aSorted.begin(), aSorted.end());
		for (int i = 0; i < n; i++)
		{
			posSorted[aSorted[i]][i % 2]++;
		}
		bool possible = true;

		for (int i = 1; i < MAX; i++)
		{
			if (pos[i][0] != posSorted[i][0] || pos[i][1] != posSorted[i][1])
			{
				possible = false;
				break;
			}
		}
		if (possible)
		{
			cout << "YES" << '\n';
		}
		else
		{
			cout << "NO" << '\n';
		}
	}
	return 0;
}