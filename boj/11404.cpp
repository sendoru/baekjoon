#include <iostream>
#include <vector>
#include <algorithm>
#define INF 98765432100
#define MAX 101

using namespace std;
typedef long long ll;

void floyd(vector<vector<ll> >& graph, vector<vector<vector<ll> > >& route, int n)
{
	for (int i = 0; i < n; i++)
	{
		graph[i][i] = 0;
		for (int j = 0; j < n; j++)
		{
			route[i][j].push_back(i);
			route[i][j].push_back(j);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (graph[j][k] > graph[j][i] + graph[i][k])
				{
					graph[j][k] = graph[j][i] + graph[i][k];
					route[j][k] = route[j][i];
					route[j][k].pop_back();
					for (ll elem : route[i][k])
					{
						route[j][k].push_back(elem);
					}
				}
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<vector<ll> > graph(n + 1, vector<ll>(n + 1, INF));
	vector<vector<vector<ll> > > route(n + 1, vector<vector<ll> >(n + 1));
	for (int i = 0; i < m; i++)
	{
		ll start, end, cost;
		cin >> start >> end >> cost;
		graph[start][end] = min(graph[start][end], cost);
	}

	floyd(graph, route, n + 1);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (graph[i][j] >= INF)
			{
				cout << 0 << ' ';

			}
			else
			{
				cout << graph[i][j] << ' ';
			}
		}
		cout << '\n';
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (graph[i][j] >= INF || graph[i][j] == 0)
			{
				cout << 0 << '\n';
			}
			else
			{
				cout << route[i][j].size() << ' ';
				for (ll elem : route[i][j])
				{
					cout << elem << ' ';
				}
				cout << '\n';
			}
		}
	}
	return 0;
}