#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

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
		vector<int> a(1);
		vector<vector<int>> ans;
		cin >> a[0];
		for (int i = 1; i < n; i++)
		{
			int temp;
			cin >> temp;
			if (temp < a[i - 1])
			{
				auto iter = upper_bound(a.begin(), a.end(), temp);
				ans.push_back({ (int)(iter - a.begin() + 1), i + 1, (int)(a.end() - iter) });
				a.push_back(temp);
				sort(a.begin(), a.end());
			}
			else
			{
				a.push_back(temp);
			}
		}
		cout << ans.size() << '\n';
		for (auto elem : ans) cout << elem[0] << ' ' << elem[1] << ' ' << elem[2] << '\n';
	}
	return 0;
}