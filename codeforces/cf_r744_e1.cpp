#include <iostream>
#include <queue>
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
		int n;
		cin >> n;
		vector<int> a(n);
		deque<int> ans;
		for (int i = 0; i < n; i++) cin >> a[i];
		ans.push_back(a[0]);
		for (int i = 1; i < n; i++)
		{
			if (ans.front() < a[i])
			{
				ans.push_back(a[i]);
			}
			else
			{
				ans.push_front(a[i]);
			}
		}
		for (auto elem : ans) cout << elem << ' ';
		cout << '\n';
	}
	return 0;
}