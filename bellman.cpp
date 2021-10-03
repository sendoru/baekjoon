#include <iostream>
#include <vector>
using namespace std;
constexpr int INF = 0x3fffffff;

vector<int> bellam(vector<vector<pair<int, int>>>& graph)
{
	int n = graph.size();
	vector<int> dist(n, INF);
	for (int i = 0; i < n; i++)
	{
		for (int m = 0; m < n; m++)
		{
			for (auto elem : graph[m])
			{
				int e = elem.first, w = elem.second;
				if (dist[m] + w < dist[e])
				{
					dist[e] = dist[m] + w;
				}
			}
		}
	}

	for (int m = 0; m < n; m++)
	{
		for (auto elem : graph[m])
		{
			int e = elem.first, w = elem.second;
			if (dist[m] + w < dist[e])
			{
				return vector<int>(n, -1);
			}
		}
	}

	return dist;
}