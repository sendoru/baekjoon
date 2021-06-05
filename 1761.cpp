#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 40001

using namespace std;
typedef long long ll;

vector<vector<pair<ll, ll>>> graph(MAX);
int parent[MAX];
int depth[MAX];
int cost[MAX];

void dfs(int parentNode, int currentDepth)
{
	currentDepth++;
	depth[parentNode] = currentDepth;
	for (pair<ll, ll> nextNode : graph[parentNode])
	{
		if (depth[nextNode.first] == 0)
		{
			parent[nextNode.first] = parentNode;
			cost[nextNode.first] = nextNode.second;
			dfs(nextNode.first, currentDepth);
		}
	}
}

int main(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}

	dfs(1, 0);

	int m;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		ll ans = 0;
		cin >> a >> b;
		if (depth[a] > depth[b])
		{
			swap(a, b);
		}
		while (depth[a] != depth[b])
		{
			ans += cost[b];
			b = parent[b];
		}
		while (a != b)
		{
			ans += cost[a];
			ans += cost[b];
			a = parent[a];
			b = parent[b];
		}
		cout << ans << '\n';
	}

	return 0;
}