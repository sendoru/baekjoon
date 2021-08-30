#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;

int solve(int here, int cost, ll visited, vector<vector<int>>& graph, vector<vector<vector<int>>>& dp)
{
	int& ret = dp[here][cost][visited];
	if (ret != -1) return ret;
	ret = 0;

	for (int next = 0; next < graph.size(); next++)
	{
		if (!(visited & (1ll << next)) && graph[here][next] >= cost)
		{
			ret = max(ret, 1 + solve(next, graph[here][next], visited | (1ll << next), graph, dp));
		}
	}
	return ret;
}


int main(void)
{
	int n;
	cin >> n;
	vector<vector<int>> graph(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
		{
			graph[i][j] = s[j] - '0';
		}
	}
	// dp[현재위치][가격][비트마스킹]
	vector<vector<vector<int>>> dp(n, vector<vector<int>>(10, vector<int>(1ll << n, -1)));
	cout << solve(0, 0, 1ll, graph, dp) + 1<< '\n';
	return 0;
}