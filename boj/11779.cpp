#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 20001;
const int INF = 987654321;

// 

pair<vector<int>, vector<vector<int>>> dijkstra(vector<vector<pair<int, int>>> graph, int start, int vertex) // 시작점, 정점의 갯수
{
	vector<int> distance(vertex, INF);
	vector<vector<int>> route(vertex);
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
			vector<int> neighborRoute = route[currentVertex];
			neighborRoute.push_back(neighbor);

			if (distance[neighbor] > neighborDistance)
			{
				distance[neighbor] = neighborDistance;
				route[neighbor] = neighborRoute;
				pq.push({ neighborDistance, neighbor });
			}
		}
	}

	return { distance, route };
}

int main(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<vector<pair<int, int>>> graph(MAX);

	int V, E, start, end;
	cin >> V >> E;

	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v, w });
	}

	cin >> start >> end;

	pair<vector<int>, vector<vector<int>>> result = dijkstra(graph, start, V + 1);

	cout << result.first[end] << '\n';
	cout << result.second[end].size() + 1 << '\n';
	cout << start << ' ';
	for (auto elem : result.second[end])
	{
		cout << elem << ' ';
	}
	

	return 0;
}