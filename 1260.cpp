#include <iostream>
#include <queue>
#include <vector>
#include <cstring>	// memset
#define MAX 1001

using namespace std;

bool visited[MAX] = { 0, };
bool map[MAX][MAX];

void dfs(int n)
{
	visited[n] = true;
	cout << n << ' ';
	for (int i = 0; i < MAX; i++)
	{
		if (map[n][i] == true && visited[i] == false)
		{
			dfs(i);
		}
	}
}

void bfs(int n, queue<int>& q)
{
	int current;
	q.push(n);
	visited[n] = true;
	while (!q.empty())
	{
		current = q.front();
		q.pop();
		cout << current << ' ';
		
		
		for (int i = 0; i < MAX; i++)
		{
			if (map[current][i] == true && visited[i] == false)
			{
				visited[i] = true;
				q.push(i);
			}
		}
	}

	
}

int main(void)
{
	queue<int> q;

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			map[i][j] = false;
		}
	}

	int countofVertexes, countofEdges, root;
	cin >> countofVertexes >> countofEdges >> root;
	for (int i = 0; i < countofEdges; i++)
	{
		int start, end;
		cin >> start >> end;
		map[start][end] = true;
		map[end][start] = true;
	}

	dfs(root);
	cout << '\n';
	memset(visited, 0, MAX);
	bfs(root, q);
	cout << '\n';

	return 0;
}