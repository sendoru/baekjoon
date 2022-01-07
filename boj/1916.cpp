#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 20001;
const int INF = 987654321;

// 

vector<int> dijkstra(vector<vector<pair<int, int>>> graph, int start, int vertex) // 시작점, 정점의 갯수
{
	vector<int> distance(vertex, INF);
	distance[start] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  // cost, vertex

	pq.push({ 0, start });

	while (!pq.empty())
	{
		int cost = pq.top().first;
		int currentVertex = pq.top().second;
		pq.pop();

		if (distance[currentVertex] < cost)
		{
			continue;
		}

		for (int i = 0; i < graph[currentVertex].size(); i++)
		{
			int neighbor = graph[currentVertex][i].first;
			int neighborDistance = graph[currentVertex][i].second + distance[currentVertex];

			if (distance[neighbor] > neighborDistance)
			{
				distance[neighbor] = neighborDistance;
				pq.push({ neighborDistance, neighbor });
			}
		}
	}

	return distance;
}

int main(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<vector<pair<int, int>>> graph(MAX);

	int V, E;
	cin >> V >> E;

	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v, w });
	}

	int start, end;
	cin >> start >> end;

	vector<int> result = dijkstra(graph, start, V + 1);

	cout << result[end] << '\n';


	return 0;
}