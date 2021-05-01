#include <iostream>
#include <queue>
#include <vector>

using namespace std;


queue<pair<int, int>> q;

// 상, 하, 좌, 우
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void bfs(int m, int n, vector<vector<int>>& tomatoes)
{
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int newX = x + dx[i];
			int newY = y + dy[i];

			// 배열의 인덱스를 벗어날 때 예외처리
			if (newX < 0 || newY < 0 || newX >= m || newY >= n)
			{
				continue;
			}
			// 안익은 토마토 익게 하기
			if (tomatoes[newY][newX] == 0)
			{
				tomatoes[newY][newX] = tomatoes[y][x] + 1;
				q.push(make_pair(newX, newY));
			}
		}
	}
}

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<vector<int>> tomatoes(1000);

	for (int i = 0; i < 1000; i++)
	{
		for (int j = 0; j < 1000; j++)
		{
			tomatoes[i].push_back(-1);
		}
	}

	int M, N;
	cin >> M >> N;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			cin >> tomatoes[y][x];
			if (tomatoes[y][x] == 1)
			{
				q.push(make_pair(x, y));
			}
		}
	}

	bfs(M, N, tomatoes);

	int result = 0;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (tomatoes[y][x] == 0)
			{
				cout << -1 << endl;
				return 0;
			}
			if (tomatoes[y][x] > result)
			{
				result = tomatoes[y][x];
			}
		}
	}

	cout << result - 1 << endl;
	return 0;
}