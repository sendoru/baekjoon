#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int n, a, b;
		cin >> n >> a >> b;
		if (abs(a - b) > 1 || (a + b) > n - 2)
		{
			cout << "-1\n";
			continue;
		}
		vector<pair<int, int>> ans;
		// case 1: 극대 >= 극소
		// 0부터 시작해서 +2, -1, +2, -1 반복
		int diff = 2, cur = 0;
		for (int i = 0; i < a + b + 1; i++)
		{
			ans.push_back({ cur, i });
			cur += diff;
			diff = (diff == 2 ? -1 : 2);
		}

		if (diff == 2)
		{
			for (int i = a + b + 1; i < n; i++)
			{
				ans.push_back({ -i, i });
			}
		}
		else
		{
			for (int i = a + b + 1; i < n; i++)
			{
				ans.push_back({ i + 1000000, i });
			}
		}

		// case 2: 극대 < 극소
		// 그냥 위에서 했던 거 부호만 다 바꿔주면 됨
		if (a < b)
		{
			for (int i = 0; i < ans.size(); i++)
			{
				ans[i].first = -ans[i].first;
			}
		}

		// 정렬 후 좌표압축
		sort(ans.begin(), ans.end());
		for (int i = 0; i < n; i++)
		{
			ans[i].first = i + 1;
		}
		// 원래 순서로 복구
		sort(ans.begin(), ans.end(), [](pair<int, int> a, pair<int, int> b) { return a.second < b.second; });

		for (int i = 0; i < ans.size(); i++)
		{
			cout << ans[i].first << ' ';
		}
		cout << '\n';
	}

	return 0;
}