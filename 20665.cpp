#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
constexpr int OPEN = 9 * 60, CLOSE = 21 * 60, INF = 0x3fffffff;

using namespace std;

int main(void)
{
	int n, t, p;
	cin >> n >> t >> p;
	vector<pair<int, int>> events;
	for (int i = 0; i < t; i++)
	{
		int enter, leave;
		cin >> enter >> leave;
		if (enter == leave) continue;
		enter = enter % 100 + 60 * (enter / 100) - OPEN;
		leave = leave % 100 + 60 * (leave / 100) - OPEN;
		events.push_back({ enter, (leave - enter) * 10000 + i + 1 });
		events.push_back({ leave, -((leave - enter) * 10000 + i + 1) });
	}

	sort(events.begin(), events.end());
	int ans = 0;
	ans += events[0].first;
	vector<pair<int, int>> seats;
	set<int> f;

	for (int i = 0; i < events.size(); i++)
	{
		if (f.find(events[i].second) != f.end())
		{
			continue;
		}
		if (events[i].second > 0)
		{
			if (seats.empty())
				seats.push_back({ 1, events[i].second });
			else
			{
				pair<int, int> maxDist = { -seats[0].first + 2, seats[0].first };
				for (int j = 1; j < seats.size(); j++)
				{
					if ((seats[j].first - seats[j - 1].first) / 2 > (maxDist.second - maxDist.first) / 2)
					{
						maxDist = {seats[j - 1].first, seats[j].first };
					}
				}
				if (n - seats.back().first > (maxDist.second - maxDist.first) / 2)
				{
					seats.push_back({ n, events[i].second });
				}
				else
				{
					seats.push_back({ -1, -1 });
					for (int j = seats.size() - 2; j >= 0; j--)
					{
						if (seats[j].first > maxDist.first + (maxDist.second - maxDist.first) / 2)
						{
							seats[j + 1] = seats[j];
							seats[j] = { -1, -1 };
						}
						else
						{
							seats[j + 1] = { maxDist.first + (maxDist.second - maxDist.first) / 2 , events[i].second };
							break;
						}
					}
					if (seats[0] == make_pair(-1, -1))
					{
						seats[0] = { maxDist.first + (maxDist.second - maxDist.first) / 2 , events[i].second };
					}
				}
			}
		}
		else
		{
			int idx = 0;
			while (seats[idx].second != -events[i].second)
			{
				idx++;
			}
			for (int j = idx; j < seats.size() - 1; j++)
			{
				seats[j] = seats[j + 1];
			}
			seats.pop_back();
		}

		if (lower_bound(seats.begin(), seats.end(), make_pair(p, -INF)) == seats.end() || (*lower_bound(seats.begin(), seats.end(), make_pair(p, -INF))).first != p)
		{
			if (i != events.size() - 1)
			{
				ans += events[i + 1].first - events[i].first;
			}
		}

	}

	ans += (CLOSE - OPEN) - events.back().first;
	cout << ans;
	return 0;
}