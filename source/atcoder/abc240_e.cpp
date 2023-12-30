#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <algorithm>
typedef long long ll;
using namespace std;

vector<pair<int, int>> solve(vector<vector<int>>& adj)
{
	vector<pair<int, int>> ret(adj.size());
	int leafCnt = 0;
	vector<vector<int>> childs(adj.size());
	
	vector<bool> visited(adj.size());
	vector<int> parents(adj.size(), -1);

	function<void(int)> dfs1 = [&](int curNode) -> void
	{
		visited[curNode] = true;
		if (curNode != 1 && adj[curNode].size() == 1)
		{
			return;
		}
		for (auto nextNode : adj[curNode])
		{
			if (!visited[nextNode])
			{
				childs[curNode].push_back(nextNode);
				dfs1(nextNode);
			}
		}
	};
	
	dfs1(1);

	visited = vector<bool>(adj.size(), false);
	function<void(int)> dfs2 = [&] (int curNode) -> void
	{
		visited[curNode] = true;
		if (childs[curNode].size() == 0)
		{
			ret[curNode].first = leafCnt + 1;
			ret[curNode].second = leafCnt + 1;
			leafCnt++;
			return;
		}
		for (auto nextNode : adj[curNode])
		{
			if (!visited[nextNode])
			{
				dfs2(nextNode);
			}
		}
		ret[curNode].first = ret[childs[curNode][0]].first;
		ret[curNode].second = ret[childs[curNode].back()].second;
	};

	dfs2(1);

	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	
	vector<vector<int>> adj(n + 1);
	for (int i = 0; i < n - 1; i++)
	{
		int s, e;
		cin >> s >> e;
		adj[s].push_back(e);
		adj[e].push_back(s);
	}

	auto ans = solve(adj);
	for (int i = 1; i < ans.size(); i++)
	{
		cout << ans[i].first << ' ' << ans[i].second << '\n';
	}

	return 0;
}