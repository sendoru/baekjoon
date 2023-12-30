#include <iostream>
#include <functional>
#include <string>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

vector<int> solve(vector<vector<int>>& adj, vector<int>& x, vector<pair<int, int>>& queries)
{
	vector<bool> visited(adj.size());
	vector<int> parents(adj.size(), -1);
	vector<vector<int>> sorted(adj.size());
	function<void(int)> dfs = [&](int node)
	{
		visited[node] = true;
		if (node != 1 && adj[node].size() == 1)
		{
			sorted[node] = { x[node] };
			return;
		}
		for (auto nextNode : adj[node])
		{
			parents[nextNode] = node;
			if (!visited[nextNode])
			{
				dfs(nextNode);
			}
		}
		for (auto nextNode : adj[node])
		{
			if (nextNode != parents[nextNode])
			{
				for (auto elem : sorted[nextNode])
				{
					sorted[node].push_back(elem);
				}
			}
		}
		sorted[node].push_back(x[node]);
		sort(sorted[node].begin(), sorted[node].end(), greater<int>());
		if (sorted[node].size() > 20)
		{
			sorted[node].resize(20);
		}
	};

	dfs(1);

	vector<int> ret(queries.size());
	for (int i = 0; i < queries.size(); i++)
	{
		ret[i] = sorted[queries[i].first][queries[i].second - 1];
	}
	
	return ret;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, q;
	cin >> n >> q;
	vector<vector<int>> adj(n + 1);
	vector<int> x(n + 1);
	vector<pair<int, int>> queries(q);
	for (int i = 1; i <= n; i++)
	{
		cin >> x[i];
	}
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 0; i < q; i++)
	{
		cin >> queries[i].first >> queries[i].second;
	}

	auto ans = solve(adj, x, queries);

	for (int elem : ans)
	{
		cout << elem << '\n';
	}

	return 0;
}