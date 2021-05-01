#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 50001;
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

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		graph[start].push_back({ end, cost });
		graph[end].push_back({ start, cost });
	}

	vector<int> result = dijkstra(graph, 1, N + 1);

	cout << result[N] << endl;

	return 0;
}