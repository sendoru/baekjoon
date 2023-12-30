#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <random>
using namespace std;
typedef long long ll;
constexpr ll INF = 2e9;
constexpr ll MOD = 1e9 + 7;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> adjList(n);
	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;
		adjList[s].push_back(e);
		adjList[e].push_back(s);
	}

	vector<vector<int>> newAdjList(n);
	for (int i = 0; i < n; i++)
	{
		for (auto& nextNode : adjList[i])
		{
			if (adjList[nextNode].size() > adjList[i].size())
			{
				newAdjList[i].push_back(nextNode);
			}
		}
	}

	// 위상정렬 + dp
	vector<ll> anses(n);
	vector<ll> inDeg(n);
	for (int i = 0; i < n; i++)
	{
		for (auto& nextNode : newAdjList[i])
		{
			inDeg[nextNode]++;
		}
	}

	queue<int> q;
	for (int i = 0; i < n; i++)
	{
		if (inDeg[i] == 0)
		{
			q.push(i);
			anses[i] = 1;
		}
	}

	while (!q.empty())
	{
		int curNode = q.front();
		q.pop();
		for (auto nextNode : newAdjList[curNode])
		{
			anses[nextNode] = max(anses[nextNode], anses[curNode] + 1);
			inDeg[nextNode]--;
			if (inDeg[nextNode] == 0)
			{
				q.push(nextNode);
			}
		}
	}

	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans = max(ans, anses[i]);
	}
	cout << ans << '\n';

	return 0;
}