#include <iostream>
#include <functional>
#include <queue>
#include <deque>
#include <string>
#include <unordered_set>
#include <set>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

vector<pair<int, int>> solve1(vector<int>& d, vector<pair<int, int>>& nodes)
{
	vector<pair<int, int>> ret;
	set<pair<int, int>> tempSet;
	int n = d.size() - 1;
	int degree = 0;
	for (auto elem : d) degree += elem;
	if (degree != 2 * (n - 1))
	{
		return ret;
	}
	for (auto node : nodes)
	{
		tempSet.insert(node);
		d[node.first]--;
		d[node.second]--;
	}

	set<pair<int, int>, greater<pair<int, int>>> s;
	deque<pair<int, int>> dq;
	for (int i = 1; i <= n; i++)
	{
		if (d[i] < 0)
		{
			return ret;
		}
		else if (d[i] > 0)
		{
			s.insert({ d[i], i });
		}
	}

	while (!s.empty())
	{
		if (s.size() == 1)
		{
			return {};
		}
		auto l = s.begin(), ll = --s.end();
		auto node1 = *l;
		auto node2 = *ll;
		if (node1.first != 1)
		{
			if (s.size() != 2 || node2.first != 1)
			{
				return {};
			}
		}
		s.erase(l);
		s.erase(ll);
		tempSet.insert(make_pair(min(node1.second, node2.second), max(node1.second, node2.second)));
		ret.push_back(make_pair(min(node1.second, node2.second), max(node1.second, node2.second)));
		node1.first--;
		if (node1.first != 0)
		{
			s.insert(node1);
		}
		node2.first--;
		if (node2.first != 0)
		{
			s.insert(node2);
		}
	}

	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> d(n + 1);
	vector<pair<int, int>> nodes(m);
	for (int i = 1; i <= n; i++)
	{
		cin >> d[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> nodes[i].first >> nodes[i].second;
	}

	auto ans = solve1(d, nodes);
	// cout << '\n';

	if (ans.empty())
	{
		cout << -1;
	}
	else
	{
		for (auto elem : ans)
		{
			cout << elem.first << ' ' << elem.second << '\n';
		}
	}

	return 0;
}