// https://codingcompetitions.withgoogle.com/codejam/round/00000000008778ec/0000000000b158f8

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
typedef long long ll;
using namespace std;
constexpr ll INF = (ll)1e18;

ll squareDist(pair<ll, ll>& a, pair<ll, ll>& b)
{
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

void innerSolve(vector<pair<ll, ll>>& children, vector<pair<ll, ll>>& candies, vector<int>& candiesVisited, vector<ll>& childrenOrder, vector<ll>& candiesOrder, pair<vector<ll>, vector<ll>>& solution, bool& solved, int n, int remain)
{
	if (remain == 0)
	{
		solved = true;
		solution = { childrenOrder, candiesOrder };
		return;
	}

	if (solved) return;

	for (int i = 0; i < children.size(); i++)
	{
		vector<pair<ll, ll>> nearests;
		ll minDist = INF;
		if (find(childrenOrder.begin(), childrenOrder.end(), i) != childrenOrder.end()) continue;
		for (int j = 0; j < candies.size(); j++)
		{
			if (candiesVisited[j]) continue;
			ll curDist = squareDist(children[i], candies[j]);
			if (curDist < minDist)
			{
				nearests = { candies[j] };
				minDist = curDist;
			}
			else if (curDist == minDist)
			{
				if (find(nearests.begin(), nearests.end(), candies[j]) == nearests.end())
					nearests.push_back(candies[j]);
			}
		}

		for (auto elem : nearests)
		{
			bool found = false;
			int nxt = -1;
			for (int j = 1; j < candies.size(); j++)
			{
				if (candies[j] == elem && !candiesVisited[j])
				{
					found = true;
					nxt = j;
					break;
				}
			}

			if (found)
			{
				childrenOrder.push_back(i);
				candiesVisited[nxt] = true;
				candiesOrder.push_back(nxt);
				innerSolve(children, candies, candiesVisited, childrenOrder, candiesOrder, solution, solved, n, remain - 1);
				childrenOrder.pop_back();
				candiesVisited[nxt] = false;
				candiesOrder.pop_back();
			}
		}
	}
}

pair<vector<ll>, vector<ll>> solve(vector<pair<ll, ll>>& children, vector<pair<ll, ll>>& candies)
{
	int n = children.size();
	vector<int> candiesVisited(n + 1);
	vector<ll> childrenOrder;
	vector<ll> candiesOrder;
	pair<vector<ll>, vector<ll>> solution;
	bool solved = false;
	innerSolve(children, candies, candiesVisited, childrenOrder, candiesOrder, solution, solved, n, n);
	return solution;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		int n;
		cin >> n;
		vector<pair<ll, ll>> children(n);
		map<pair<ll, ll>, ll> childrenCnt;
		for (int i = 0; i < n; i++)
		{
			cin >> children[i].first >> children[i].second;
			childrenCnt[children[i]]++;
		}

		vector<pair<ll, ll>> candies(n + 1);
		map<pair<ll, ll>, ll> candiesCnt;
		for (int i = 0; i <= n; i++)
		{
			cin >> candies[i].first >> candies[i].second;
			candiesCnt[candies[i]]++;
		}

		auto ans = solve(children, candies);

		cout << "Case #" << t << ": ";

		if (ans.first.size() == 0)
		{
			cout << "IMPOSSIBLE\n";
		}
		else
		{
			cout << "POSSIBLE\n";
			for (int i = 0; i < ans.first.size(); i++)
			{
				cout << ans.first[i] + 1 << ' ' << ans.second[i] + 1 << '\n';
			}
		}
	}
	return 0;
}