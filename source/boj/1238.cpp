#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

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

	int N, M, X;
	cin >> N >> M >> X;

	// vpair<int, int> := 
	vector<vector<pair<int, int> > > graphFromX(N + 1);
	vector<vector<pair<int, int> > > graphToX(N + 1);

	for (int i = 0; i < M; i++)
	{
		int start, end, T;
		cin >> start >> end >> T;
		graphFromX[start].push_back({end, T});
	}

	vector<int> leavefromX = dijkstra(graphFromX, X, N + 1);

	for (int i = 0; i < graphFromX.size(); i++)
	{
		for (int j = 0; j < graphFromX[i].size(); j++)
		{
			graphToX[graphFromX[i][j].first].push_back({ i, graphFromX[i][j].second });
		}
	}

	vector<int> gotoX = dijkstra(graphToX, X, N + 1);

	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		int sum = leavefromX[i] + gotoX[i];
		if (ans < sum)
		{
			ans = sum;
		}
	}

	cout << ans << '\n';
	return 0;

}