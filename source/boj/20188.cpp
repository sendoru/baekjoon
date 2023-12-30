#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

void dfs(vector<vector<int>>& tree, vector<pair<ll, ll>>& dp, vector<int>& depth, int curNode, int curDepth)
{
	depth[curNode] = curDepth;
	if (curDepth > 0 && tree[curNode].size() == 1)
	{
		return;
	}
	for (auto nextNode : tree[curNode])
	{
		if (depth[nextNode] == -1)
		{
			dfs(tree, dp, depth, nextNode, curDepth + 1);
		}
	}
	if (dp[curNode].first == 0)
	{
		for (auto nextNode : tree[curNode])
		{
			if (depth[nextNode] > curDepth)
			{
				dp[curNode].first += dp[nextNode].first + 1;
			}
		}
		for (auto nextNode : tree[curNode])
		{
			if (depth[nextNode] < depth[curNode]) continue;
			dp[curNode].second += dp[nextNode].first + 1;
		}
		dp[curNode].second *= dp[curNode].second;
		for (auto nextNode : tree[curNode])
		{
			if (depth[nextNode] < depth[curNode]) continue;
			dp[curNode].second -= (dp[nextNode].first + 1) * (dp[nextNode].first + 1);
		}
		dp[curNode].second /= 2;
		dp[curNode].second += dp[curNode].first;
	}
}

int main(void)
{
	int n;
	cin >> n;
	vector<vector<int>> tree(n + 1);
	// dp[i].first : i번 정점의 모든 후손의 갯수, dp[i].second : i번 정점을 lca로 가지는 정점 쌍의 갯수(순서무관)
	vector<pair<ll, ll>> dp(n + 1);
	vector<int> depth(n + 1, -1);
	for (int i = 0; i < n - 1; i++)
	{
		int s, e;
		cin >> s >> e;
		tree[s].push_back(e);
		tree[e].push_back(s);
	}
	dfs(tree, dp, depth, 1, 0);
	ll ans = 0;
	for (ll elem : depth)
	{
		if (elem > 0)
		ans += elem * (n - 1);
	}
	for (int i = 1; i <= n; i++)
	{
		ans -= depth[i] * dp[i].second;
	}
	cout << ans;
	return 0;
}