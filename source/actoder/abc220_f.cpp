#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

void dfs(vector<vector<ll>>& graph, vector<ll>& subtreeSize, ll& distSum, int curNode, int curDepth)
{
	subtreeSize[curNode] = 1;
	distSum += curDepth;
	for (auto nextNode : graph[curNode])
	{
		if (subtreeSize[nextNode] == -1)
		{
			dfs(graph, subtreeSize, distSum, nextNode, curDepth + 1);
			subtreeSize[curNode] += subtreeSize[nextNode];
		}
	}
}

void solve(vector<vector<ll>>& graph, vector<ll>& subtreeSize, vector<ll>& ans, int curNode, ll prevAns)
{
	if (ans[curNode] == -1)
	{
		ans[curNode] = prevAns - 2 * subtreeSize[curNode] + subtreeSize[1];
	}
	for (auto nextNode : graph[curNode])
	{
		if (ans[nextNode] == -1)
		{
			solve(graph, subtreeSize, ans, nextNode, ans[curNode]);
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<vector<ll>> graph(n + 1);
	vector<ll> subtreeSize(n + 1, -1);
	vector<ll> depths(n + 1, -1);
	for (int i = 0; i < n - 1; i++)
	{
		int v1, v2;
		cin >> v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	ll distSum = 0;
	dfs(graph, subtreeSize, distSum, 1, 0);
	vector<ll> ans(n + 1, -1);
	ans[1] = distSum;
	solve(graph, subtreeSize, ans, 1, 0);

	for (int i = 1; i < ans.size(); i++)
	{
		cout << ans[i] << '\n';
	}

	return 0;
}