#include <iostream>
#include <vector>
#include <queue>
typedef long long ll;
using namespace std;

void treeDP(vector<vector<pair<ll, ll>>>& adjList, ll curNode, vector<ll>& subtreeSize, vector<ll>& dist, vector<bool>& visited)
{
	visited[curNode] = true;
	if (curNode != 1 && adjList[curNode].size() == 1)
	{
		subtreeSize[curNode] = 1;
		return;
	}

	for (auto edge : adjList[curNode])
	{
		ll nextNode = edge.first, nextDist = edge.second;
		if (!visited[nextNode])
		{
			visited[nextNode] = true;
			dist[nextNode] = dist[curNode] + nextDist;
			treeDP(adjList, nextNode, subtreeSize, dist, visited);
			subtreeSize[curNode] += subtreeSize[nextNode];
		}
	}
	subtreeSize[curNode] += 1;
}

vector<ll> solve(vector<vector<pair<ll, ll>>>& adjList)
{
	vector<ll> ret(adjList.size(), -1);
	int treeSize = adjList.size() - 1;

	vector<ll> dist(treeSize + 1), subtreeSize(treeSize + 1);
	vector<bool> visited(treeSize + 1);

	treeDP(adjList, 1, subtreeSize, dist, visited);
	ret[1] = 0;
	for (int i = 2; i < dist.size(); i++)
		ret[1] += dist[i];
	
	queue<pair<ll, ll>> q;
	q.push({ 1, 0 });
	while (!q.empty())
	{
		ll curNode = q.front().first, curDist = q.front().second;
		q.pop();

		for (auto& edge : adjList[curNode])
		{
			ll nextNode = edge.first, nextDist = edge.second;
			if (ret[nextNode] == -1)
			{
				ret[nextNode] = ret[curNode] + nextDist * (treeSize - 2 * subtreeSize[nextNode]);
				q.push(edge);
			}
		}
	}

	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<vector<pair<ll, ll>>> adjList(n + 1);
	for (int i = 0; i < n - 1; i++)
	{
		int u, v, d;
		cin >> u >> v >> d;
		adjList[u].push_back({ v, d });
		adjList[v].push_back({ u, d });
	}

	auto ans = solve(adjList);
	for (int i = 1; i < ans.size(); i++)
	{
		cout << ans[i] << '\n';
	}

	return 0;
}