#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
const int INF = 0x0fffffff;

int init(vector<int>& a, vector<int>& tree, int node, int start, int end)
{
	// node가 리프 노드인 경우
	if (start == end)
	{
		return tree[node] = a[start];
	}
	else
	{
		return tree[node] = min(init(a, tree, node * 2, start, (start + end) / 2), init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end));
	}
}


int getMin(vector<int>& tree, int node, int start, int end, int left, int right)
{
	// 구간 [start, end]와 [left, right]가 겹치지 않을 경우
	if (left > end || right < start)
	{
		return INF;
	}
	// 구간 [left, right]가 구간 [start, end]를 완전히 포함할 경우
	if (left <= start && right >= end)
	{
		return tree[node];
	}
	return min(getMin(tree, node * 2, start, (start + end) / 2, left, right), getMin(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

void dfs(vector<vector<int>>& graph, vector<int>& eulerRoute, vector<int>& depth, vector<int>& indextoOrder, vector<int>& ordertoIndex, vector<int>& firstApp, int curNode, int curDepth)
{
	depth[curNode] = curDepth;
	indextoOrder[curNode] = ordertoIndex.size();
	int order = indextoOrder[curNode];
	ordertoIndex.push_back(curNode);
	if (firstApp[order] == -1)
	{
		firstApp[order] = eulerRoute.size();
	}
	for (int nextNode : graph[curNode])
	{
		if (depth[nextNode] == -1)
		{
			eulerRoute.push_back(order);
			dfs(graph, eulerRoute, depth, indextoOrder, ordertoIndex, firstApp, nextNode, curDepth + 1);
		}
	}
	if (eulerRoute.back() != order)
	{
		eulerRoute.push_back(order);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, q, c, d, order = 1;
	cin >> n;
	vector<int> a(n), b(n), indextoOrder(n + 1), ordertoIndex(1), depth(n + 1, -1), firstApp(n + 1, -1), eulerRoute;
	vector<vector<int>> graph(n + 1, vector<int>());
	for (int i = 1; i < n; i++)
	{
		cin >> a[i] >> b[i];
		graph[a[i]].push_back(b[i]);
		graph[b[i]].push_back(a[i]);
	}
	dfs(graph, eulerRoute, depth, indextoOrder, ordertoIndex, firstApp, 1, 0);

	int h = (int)ceil(log2(eulerRoute.size()));
	int treeSize = 1 << (h + 1);
	vector<int> tree(treeSize);
	init(eulerRoute, tree, 1, 0, eulerRoute.size() - 1);

	cin >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> c >> d;
		int cConv = indextoOrder[c], dConv = indextoOrder[d];
		if (firstApp[cConv] > firstApp[dConv])
		{
			int temp = cConv;
			cConv = dConv;
			dConv = temp;
		}
		int LCAOrder = getMin(tree, 1, 0, eulerRoute.size() - 1, firstApp[cConv], firstApp[dConv]);
		int LCAIndex = ordertoIndex[LCAOrder];
		cout << LCAIndex << '\n';
	}

	return 0;

}