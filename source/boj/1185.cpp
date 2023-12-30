#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findRoot(int x, vector<int>& roots)
{
	if (roots[x] == x) return x;
	return roots[x] = findRoot(roots[x], roots);
}

bool hasSameRoots(int x, int y, vector<int>& roots)
{
	return (findRoot(x, roots) == findRoot(y, roots));
}

void unite(int x, int y, vector<int>& roots)
{
	int xRoot = findRoot(x, roots), yRoot = findRoot(y, roots);
	if (xRoot != yRoot) roots[yRoot] = xRoot;
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, p;
	cin >> n >> p;
	vector<int> nodeCosts(n + 1), roots(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> nodeCosts[i];
		roots[i] = i;
	}
	vector<vector<int>> edges(p, vector<int>(3));
	for (int i = 0; i < p; i++)
	{
		cin >> edges[i][1] >> edges[i][2] >> edges[i][0];
		edges[i][0] = 2 * edges[i][0] + nodeCosts[edges[i][1]] + nodeCosts[edges[i][2]];
	}

	sort(edges.begin(), edges.end());
	int ans = 0;
	for (auto edge : edges)
	{
		if (!hasSameRoots(edge[1], edge[2], roots))
		{
			unite(edge[1], edge[2], roots);
			ans += edge[0];
		}
	}

	int minNodeCost = nodeCosts[1];
	for (int i = 2; i < nodeCosts.size(); i++)
	{
		minNodeCost = min(minNodeCost, nodeCosts[i]);
	}
	ans += minNodeCost;

	cout << ans;
	return 0;
}