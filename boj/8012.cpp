#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 30005

using namespace std;
typedef long long ll;

vector<vector<ll>> graph(MAX);
int parent[MAX];
int depth[MAX];
int cost[MAX];

void dfs(int parentNode, int currentDepth)
{
	currentDepth++;
	depth[parentNode] = currentDepth;
	for (ll nextNode : graph[parentNode])
	{
		if (depth[nextNode] == 0 && nextNode != 1)
		{
			parent[nextNode] = parentNode;
			dfs(nextNode, currentDepth);
		}
	}
}

int main(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	// cin >> n;
	n = 30000;
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		// cin >> a >> b;
		a = i + 1, b = i + 2;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(1, 0);

	int m, cur = 1, next = 1;
	ll ans = 0;
	// cin >> m;
	m = 5000;

	for (int i = 0; i < m; i++)
	{
		ll dist = 0;
		cur = next;
		// cin >> next;
		next = 29999 * ((1 + i) % 2) + 1;
		int tempCur = cur, tempNext = next;

		while (depth[tempCur] < depth[tempNext])
		{
			dist++;
			tempNext = parent[tempNext];
		}
		while (depth[tempCur] > depth[tempNext])
		{
			dist++;
			tempCur = parent[tempCur];
		}
		while (tempCur != tempNext)
		{
			dist += 2;
			tempCur = parent[tempCur];
			tempNext = parent[tempNext];
		}
		ans += dist;
	}
	cout << ans;
	return 0;
}