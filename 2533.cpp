#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& tree, vector<bool>& visited, int curNode, int depth, int& evenCnt, int& oddCnt)
{
	visited[curNode] = true;
	if (depth % 2 == 0)
	{
		evenCnt++;
	}
	else
	{
		oddCnt++;
	}
	for (int elem : tree[curNode])
	{
		if (!visited[elem])
		{
			dfs(tree, visited, elem, depth + 1, evenCnt, oddCnt);
		}
	}
}

void solveDP(vector<vector<int>>& tree, vector<pair<int, int>>& dp, vector<bool>& visited, int curNode)
{
	visited[curNode] = true;
	dp[curNode].first = 0;
	dp[curNode].second = 1;
	for (int nextNode : tree[curNode])
	{
		if (visited[nextNode] == 0)
		{
			solveDP(tree, dp, visited, nextNode);
			dp[curNode].first += dp[nextNode].second;
			dp[curNode].second += min(dp[nextNode].first, dp[nextNode].second);
		}
	}
}

int main(void)
{
	int n;
	cin >> n;
	vector<vector<int>> tree(n);
	// dp[node].first := node가 얼리어답터가 아닐 때 필요한 최소 얼리어답터 수
	// dp[node].second := node가 얼리어답터일 때 필요한 최소 얼리어답터 수
	// 맞겠지?
	vector<pair<int, int>> dp(n, { -1, -1 });
	vector<bool> visited(n);
	for (int i = 0; i < n - 1; i++)
	{
		int start, end;
		cin >> start >> end;
		start--; end--;
		tree[start].push_back(end);
		tree[end].push_back(start);
	}

	int evenCnt = 0, oddCnt = 0;
	solveDP(tree, dp, visited, 0);
	cout << min(dp[0].first, dp[0].second) << '\n';
	return 0;
}