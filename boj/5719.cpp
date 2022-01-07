#include <iostream>
#include <vector>
#include <queue>
using namespace std;
constexpr int INF = 0x3fffffff;

// graph는 <비용, 도착 정점> 형태로 간선이 저장된 인접 리스트 형태
vector<int> dijkstra(vector<vector<pair<int, int>>>& graph, int start, int end)
{
	vector<int> dist(graph.size(), INF);
	vector<vector<pair<int, int>>> route(graph.size());
	dist[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });

	while (!pq.empty())
	{
		int cost = pq.top().first;
		int curNode = pq.top().second;
		pq.pop();

		for (int i = 0; i < graph[curNode].size(); i++)
		{
			auto edge = graph[curNode][i];
			int nextCost = edge.first;
			int nextNode = edge.second;
			if (dist[nextNode] >= dist[curNode] + nextCost)
			{
				if (dist[nextNode] > dist[curNode] + nextCost)
					route[nextNode].clear();
				route[nextNode].push_back({curNode, i});
				if (dist[nextNode] > dist[curNode] + nextCost)
				{
					dist[nextNode] = dist[curNode] + nextCost;
					pq.push(edge);
				}
			}
		}
	}

	queue<int> q;
	vector<bool> visited(graph.size());

	for (auto elem : route[end])
	{
		graph[elem.first][elem.second].first = INF;
		q.push(elem.first);
		visited[elem.first] = true;
	}

	while (!q.empty())
	{
		int curNode = q.front();
		q.pop();
		for (auto nextNode : route[curNode])
		{
			graph[nextNode.first][nextNode.second].first = INF;
			if (!visited[nextNode.first])
			{
				visited[nextNode.first] = true;
				q.push(nextNode.first);
			}
		}
	}
	
	return dist;
}

int main(void)
{
	while (true)
	{
		int n, m;
		cin >> n >> m;
		if (n == 0)
			break;

		int s, d;
		cin >> s >> d;

		vector<vector<pair<int, int>>> graph(n + 1);
		for (int i = 0; i < m; i++)
		{
			int start, end, cost;
			cin >> start >> end >> cost;
			graph[start].push_back({ cost, end });
		}
		
		dijkstra(graph, s, d);
		int ans = dijkstra(graph, s, d)[d];
		cout << (ans >= INF ? -1 : ans) << '\n';
	}

	return 0;
}

