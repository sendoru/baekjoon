#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, ans = 0;
	cin >> n;

	priority_queue<pair<int, int> > assignments;
	vector<bool> v(1001);

	for (int i = 0; i < n; i++)
	{
		// v[i].second := 점수
		// v[i].first := 마감일
		pair<int, int> temp;
		cin >> temp.second >> temp.first;
		assignments.push(temp);
	}
	
	while (!assignments.empty())
	{
		int score = assignments.top().first, date = assignments.top().second;
		for (int i = date; i >= 1; i--)
		{
			if (!v[i])
			{
				v[i] = true;
				ans += score;
				break;
			}
		}
		assignments.pop();
	}

	cout << ans << '\n';

	return 0;


}