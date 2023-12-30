#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <functional>
using namespace std;

int solve(vector<pair<int, vector<int>>> adj, int s, vector<int> terminal);
void groupSCC(vector<vector<int>>& adj, int& s, vector<int>& terminal);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<pair<int, vector<int>>> adj(n + 1);
	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;
		adj[s].second.push_back(e);
	}
	for (int i = 1; i <= n; i++)
	{
		int money;
		cin >> money;
		adj[i].first = money;
	}

	int s, p;
	cin >> s >> p;
	vector<int> terminal;
	for (int i = 0; i < p; i++)
	{
		int t;
		cin >> t;
		terminal.push_back(t);
	}

	cout << solve(adj, s, terminal);
	return 0;
}

void groupSCC(vector<pair<int, vector<int>>>& adj, int& s, vector<int>& terminal)
{
	int nodeCnt = adj.size();
	vector<bool> visited(nodeCnt);
	vector<int> postOrder(nodeCnt);
	vector<vector<int>> scc;
	vector<int> sccNo(nodeCnt);
	vector<vector<int>> reversedAdj(nodeCnt + 1);
	for (int i = 0; i < nodeCnt; i++)
		for (auto j : adj[i].second)
			reversedAdj[j].push_back(i);

	function<void(int, bool)> dfs = [&](int curNode, bool reversed) -> void
	{
		if (visited[curNode])
			return;
		visited[curNode] = true;

		for (int nextNode : (reversed ? reversedAdj[curNode] : adj[curNode].second))
		{
			dfs(nextNode, reversed);
		}
		if (reversed)
		{
			scc.back().push_back(curNode);
			sccNo[curNode] = scc.size() - 1;
		}
		else postOrder.push_back(curNode);
	};

	for (int i = 0; i < adj.size(); i++)
	{
		if (!visited[i])
		{
			dfs(i, false);
		}
	}

	visited.clear();
	visited.resize(nodeCnt);

	while (!postOrder.empty())
	{
		if (!visited[postOrder.back()])
		{
			scc.push_back({});
			dfs(postOrder.back(), true);
		}
		postOrder.pop_back();
	}

	vector<pair<int, vector<int>>> sccAdj(scc.size());
	for (int i = 0; i < nodeCnt; i++)
	{
		for (int elem : adj[i].second)
		{
			sccAdj[sccNo[i]].second.push_back(sccNo[elem]);
		}
		sccAdj[sccNo[i]].first += adj[i].first;
	}

	for (int i = 0; i < sccAdj.size(); i++)
	{
		sort(sccAdj[i].second.begin(), sccAdj[i].second.end());
		vector<int> newAdj;
		for (int elem : sccAdj[i].second)
		{
			if (elem != i && (newAdj.empty() || newAdj.back() != elem))
			{
				newAdj.push_back(elem);
			}
		}
		sccAdj[i].second = newAdj;
	}
	
	adj = sccAdj;

	s = sccNo[s];

	for (int& elem : terminal)
	{
		elem = sccNo[elem];
	}

}

int solve(vector<pair<int, vector<int>>> adj, int s, vector<int> terminal)
{
	groupSCC(adj, s, terminal);
	int nodeCnt = adj.size();
	vector<int> preCnt(nodeCnt);
	vector<bool> visited(nodeCnt);

	function<void(int)> dfs = [&](int curNode) -> void
	{
		if (visited[curNode])
			return;
		visited[curNode] = true;

		for (int nextNode : adj[curNode].second)
		{
			dfs(nextNode);
		}
	};

	dfs(s);

	for (int i = 0; i < nodeCnt; i++)
	{
		if (!visited[i])
		{
			adj[i].second.clear();
		}
	}

	for (int i = 0; i < nodeCnt; i++)
	{
		for (auto nextNode : adj[i].second)
		{
			preCnt[nextNode]++;
		}
	}

	vector<int> maxMoney(nodeCnt);
	queue<int> q;
	for (int i = 0; i < nodeCnt; i++)
	{
		if (preCnt[i] == 0)
		{
			maxMoney[i] = adj[i].first;
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int curNode = q.front();
		q.pop();
		for (int nextNode : adj[curNode].second)
		{
			preCnt[nextNode]--;
			maxMoney[nextNode] = max(maxMoney[nextNode], maxMoney[curNode]);
			if (preCnt[nextNode] == 0)
			{
				maxMoney[nextNode] += adj[nextNode].first;
				q.push(nextNode);
			}
		}
	}

	int ret = 0;
	for (int node : terminal)
	{
		if (visited[node])
		{
			ret = max(ret, maxMoney[node]);
		}
	}

	return ret;
}