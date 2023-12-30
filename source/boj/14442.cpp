#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int N, M, initialDrill;

int solve(vector<string>& map, vector<vector<vector<int> > >& visit, int initialDrill)
{
	queue<vector<int> > q;

	// 행(y좌표), 열(x좌표), 벽을 부술 수 있는 횟수, 경로의 길이
	q.push({ 0, 0, initialDrill, 1 });
	int row, col, drill, dist;

	while (!q.empty())
	{

		row = q.front()[0];
		col = q.front()[1];
		drill = q.front()[2];
		dist = q.front()[3];

		// 끝점에 도달하면 종료
		if (row == N - 1 && col == M - 1)
		{
			return dist;
		}

		// 위
		if (row > 0)
		{
			if (map[row - 1][col] == '0' && visit[row - 1][col][drill] == 0)
			{
				visit[row - 1][col][drill] = dist + 1;
				q.push({ row - 1, col, drill, dist + 1 });
			}
			else if (map[row - 1][col] == '1' && drill > 0 && visit[row - 1][col][drill - 1] == 0)
			{
				visit[row - 1][col][drill - 1] = dist + 1;
				q.push({ row - 1, col, drill - 1, dist + 1 });
			}
		}

		// 아래
		if (row < N - 1)
		{
			if (map[row + 1][col] == '0' && visit[row + 1][col][drill] == 0)
			{
				visit[row + 1][col][drill] = dist + 1;
				q.push({ row + 1, col, drill, dist + 1 });
			}
			else if (map[row + 1][col] == '1' && drill > 0 && visit[row + 1][col][drill - 1] == 0)
			{
				visit[row + 1][col][drill - 1] = dist + 1;
				q.push({ row + 1, col, drill - 1, dist + 1 });
			}
		}

		// 왼쪽
		if (col > 0)
		{
			if (map[row][col - 1] == '0' && visit[row][col - 1][drill] == 0)
			{
				visit[row][col - 1][drill] = dist + 1;
				q.push({ row, col - 1, drill, dist + 1 });

			}
			else if (map[row][col - 1] == '1' && drill > 0 && visit[row][col - 1][drill - 1] == 0)
			{
				visit[row][col - 1][drill - 1] = dist + 1;
				q.push({ row, col - 1, drill - 1, dist + 1 });
			}
		}

		// 오른쪽
		if (col < M - 1)
		{
			if (map[row][col + 1] == '0' && visit[row][col + 1][drill] == 0)
			{
				visit[row][col + 1][drill] = dist + 1;
				q.push({ row, col + 1, drill, dist + 1 });
			}
			else if (map[row][col + 1] == '1' && drill > 0 && visit[row][col + 1][drill - 1] == 0)
			{
				visit[row][col + 1][drill - 1] = dist + 1;
				q.push({ row, col + 1, drill - 1, dist + 1 });
			}
		}

		q.pop();
	}

	return -1;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> initialDrill;

	vector<string> map(N);
	vector<vector<vector<int> > > visit(N, vector<vector<int> >(M, vector<int>(initialDrill + 1, 0)));
	visit[0][0][initialDrill] = 1;

	for (int i = 0; i < N; i++)
	{
		cin >> map[i];
	}

	int ans = solve(map, visit, initialDrill);
	cout << ans << '\n';

	return 0;
}