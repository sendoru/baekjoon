#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> tpSort(unordered_map<ll, ll> pre, unordered_map<ll, vector<ll>>& suc)
{
	vector<ll> ret;
	queue<ll> q;

	for (auto elem : pre)
		if (elem.second == 0)
			q.push(elem.first);

	while (!q.empty())
	{
		auto curNode = q.front();
		ret.push_back(curNode);
		q.pop();
		for (auto nextNode : suc[curNode])
		{
			pre[nextNode]--;
			if (pre[nextNode] == 0)
				q.push(nextNode);
		}
	}

	return ret;
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int h, w, n;
	cin >> h >> w >> n;
	unordered_map<ll, ll> squares;
	vector<ll> order;
	unordered_map<ll, vector<ll>> graph;
	unordered_map<ll, ll> pre;
	for (int i = 0; i < n; i++)
	{
		ll r, c, a;
		cin >> r >> c >> a;
		squares[r * 1000000 + c] = a;
		order.push_back(r * 1000000 + c);
	}

	for (int i = 0; i < order.size(); i++)
	{
		ll curNode = order[i];
		ll curWeight = squares[order[i]];
		pre[curNode] = max(0ll, pre[curNode]);
		for (ll j = 1; j <= h; j++)
		{
			ll nextNode = j * 1000000 + curNode % 1000000;
			if (squares[nextNode] > curWeight)
			{
				graph[curNode].push_back(nextNode);
				pre[nextNode]++;
			}
		}
		for (ll j = 1; j <= w; j++)
		{
			ll nextNode = curNode / 1000000 + j;
			if (squares[nextNode] > curWeight)
			{
				graph[curNode].push_back(nextNode);
				pre[nextNode]++;
			}
		}
	}

	vector<ll> sorted = tpSort(pre, graph);
	reverse(sorted.begin(), sorted.end());
	unordered_map<ll, ll> ans;
	for (auto startNode : sorted)
	{
		if (graph[startNode].size() == 0)
		{
			ans[startNode] = 0;
		}
		else
		{
			ans[startNode] = 0;
			for (auto nextNode : graph[startNode])
			{
				ans[startNode] = max(ans[startNode], ans[nextNode] + 1);
			}
		}
	}

	for (auto elem : order)
	{
		cout << ans[elem] << '\n';
	}
	return 0;
}