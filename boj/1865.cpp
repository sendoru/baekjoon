#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--)
	{
		bool ans = false;
		int n, m, w;
		cin >> n >> m >> w;
		vector<vector<pair<int, int>>> graph(n + 1);
		vector<int> dist(n + 1, 10000000);
		dist[1] = 0;
		for (int i = 0; i < m; i++)
		{
			int s, e, t;
			cin >> s >> e >> t;
			graph[s].push_back({ e, t });
			graph[e].push_back({ s, t });
		}
		for (int i = 0; i < w; i++)
		{
			int s, e, t;
			cin >> s >> e >> t;
			graph[s].push_back({ e, -t });
		}

		for (int i = 1; i <= n; i++)
		{
			for (int m = 1; m <= n; m++)
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

		for (int m = 1; m <= n; m++)
		{
			for (auto elem : graph[m])
			{
				int e = elem.first, w = elem.second;
				if (dist[m] + w < dist[e])
				{
					ans = true;
				}
			}
		}
		cout << (ans ? "YES" : "NO") << '\n';
	}

	return 0;
}