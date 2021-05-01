#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 801
#define INF 987654321

using namespace std;

// edges vector의 원소 pair<int, pair<int, int> > := pair<비용, pair<시작점, 끝점> >
vector<int> dijkstra(vector<pair<int, pair<int, int> > > edges, int countofNodes, int start)
{
	vector<int> distance(countofNodes, INF);
	distance[start] = 0;

	int currentNode = start;
	priority_queue<pair<int, pair<int, int> > > pq;
	pq.push({ 0, {start, start} });
	while (!pq.empty())
	{
		int cost = pq.top().first;
		int currentNode = pq.top().second.second;

		if (distance[currentNode] < cost)
		{
			continue;
		}

		for (auto edge : edges)
		{
			if (edge.second.first == currentNode)
			{
				int neighbor = edge.second.second;
				int neighborDistance = edge.first + distance[currentNode];

				if (distance[neighbor] > neighborDistance)
				{
					distance[neighbor] = neighborDistance;
					pq.push({ neighborDistance, {currentNode, neighbor} });
				}
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

	vector<pair<int, pair<int, int> > > edges;

	int N, E;
	cin >> N >> E;

	for (int i = 0; i < E; i++)
	{
		int start, end, distance;
		cin >> start >> end >> distance;
		edges.push_back({ distance, { start, end } });
		edges.push_back({ distance, { end, start } });
	}

	int v1, v2;
	cin >> v1 >> v2;

	vector<int> fromStart = dijkstra(edges, N + 1, 1);
	vector<int> fromV1 = dijkstra(edges, N + 1, v1);
	vector<int> fromV2 = dijkstra(edges, N + 1, v2);

	cout << min(fromStart[v1] + fromV1[v2] + fromV2[N + 1], fromStart[v2] + fromV2[v1] + fromV1[N + 1]) << '\n';

	return 0;
}