#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
typedef long long ll;
using namespace std;
constexpr ll INF = 0x3fffffff;

void recost(vector<ll>& costs, vector<vector<int>>& childs)
{
	vector<bool> visited(costs.size());
	function <ll(int)> dfs = [&](int curNode) -> ll
	{
		if (visited[curNode]) return -1;
		visited[curNode] = true;
		if (childs[curNode].size() == 0) return costs[curNode];
		ll minCost = INF;
		for (auto elem : childs[curNode])
		{
			dfs(elem);
			minCost = min(minCost, costs[elem]);
		}
		costs[curNode] = max(costs[curNode], minCost);
		return costs[curNode];
	};

	dfs(0);
}

vector<int> getOrder(vector<vector<int>>& childs)
{
	vector<bool> visited(childs.size());
	vector<int> ret;
	function <void(int)> dfs = [&](int curNode) -> void
	{
		if (visited[curNode]) return;
		visited[curNode] = true;
		if (childs[curNode].size() == 0)
		{
			ret.push_back(curNode);
			return;
		}
		ll minCost = INF;
		for (auto elem : childs[curNode])
		{
			dfs(elem);
		}
	};

	dfs(0);
	return ret;
}

ll getMaxCost(vector<ll>& costs, vector<int>& order, vector<int>& parents)
{
	ll ret = 0;
	vector<bool> visited(parents.size());
	for (auto initNode : order)
	{
		ll curCost = costs[initNode];
		int curNode = initNode;
		while (curNode != 0 && !visited[curNode])
		{
			visited[curNode] = true;
			curCost = max(curCost, costs[curNode]);
			curNode = parents[curNode];
		}
		ret += curCost;
	}

	return ret;
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
		vector<ll> costs(n + 1);
		vector<int> parents(n + 1);
		vector<vector<int>> childs(n + 1);
		for (int i = 1; i <= n; i++) cin >> costs[i];
		for (int i = 1; i <= n; i++)
		{
			cin >> parents[i];
			childs[parents[i]].push_back(i);
		}

		recost(costs, childs);
		for (auto& elem : childs)
		{
			sort(elem.begin(), elem.end(), [&] (int a, int b) -> bool {
				return costs[a] < costs[b];
			});
		}
		auto order = getOrder(childs);
		auto ans = getMaxCost(costs, order, parents);
		cout << "Case #" << t << ": ";
		cout << ans << '\n';
	}
	return 0;
}