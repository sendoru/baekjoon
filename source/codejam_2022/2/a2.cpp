// https://codingcompetitions.withgoogle.com/codejam/round/00000000008778ec/0000000000b15a74

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
typedef long long ll;
using namespace std;

vector<vector<int>> makeGrid(int n)
{
	vector<vector<int>> grid(n, vector<int>(n, -1));
	vector<vector<int>> d =
	{
		{0, 1},
		{1, 0},
		{0, -1},
		{-1, 0}
	};

	int r = 0, c = 0, curD = 0, curVal = 1;
	while (!(r == n / 2 && c == n / 2))
	{
		grid[r][c] = curVal;
		curVal++;
		if (r + d[curD][0] < 0 || r + d[curD][0] >= n || c + d[curD][1] < 0 || c + d[curD][1] >= n || grid[r + d[curD][0]][c + d[curD][1]] != -1)
		{
			curD = (curD + 1) % 4;
		}
		r += d[curD][0];
		c += d[curD][1];
	}

	grid[n / 2][n / 2] = n * n;
	return grid;
}

vector<pair<int, int>> solve(int n, int k)
{
	auto grid = makeGrid(n);
	vector<vector<vector<pair<int, int>>>> prev(n, vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(n * n, {-1, -1})));

	vector<int> dr = { 1, -1, 0, 0 };
	vector<int> dc = { 0, 0, 1, -1 };

	queue<vector<int>> q;
	q.push({ 0,0,0 });
	while (!q.empty())
	{
		auto cur = q.front();
		int curR = cur[0], curC = cur[1], curMove = cur[2];
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextR = curR + dr[i], nextC = curC + dc[i];
			if (nextR >= 0 && nextR < n && nextC >= 0 && nextC < n && grid[nextR][nextC] > grid[curR][curC] && prev[nextR][nextC][curMove + 1] == make_pair(-1, -1))
			{
				prev[nextR][nextC][curMove + 1] = { curR, curC };
				q.push({ nextR, nextC, curMove + 1 });
			}
		}
	}


	// 답이 없으면 {-1, -1}을 return
	if (prev[n / 2][n / 2][k] == make_pair(-1, -1))
	{
		return { make_pair(-1, -1) };
	}

	vector<pair<int, int>> route;
	vector<int> cur = { n / 2, n / 2, k };
	while (cur[2] != -1)
	{
		route.push_back({ cur[0], cur[1] });
		cur = { prev[cur[0]][cur[1]][cur[2]].first, prev[cur[0]][cur[1]][cur[2]].second, cur[2] - 1};
	}

	reverse(route.begin(), route.end());

	vector<pair<int, int>> ret;
	for (int i = 0; i < route.size() - 1; i++)
	{
		if (grid[route[i + 1].first][route[i + 1].second] - grid[route[i].first][route[i].second] != 1)
		{
			ret.push_back({ grid[route[i].first][route[i].second], grid[route[i + 1].first][route[i + 1].second] });
		}
	}

	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		int n, k;
		cin >> n >> k;

		cout << "Case #" << t << ": ";
		if (k < n - 1 && k == n - 2)
		{
			cout << "IMPOSSIBLE\n";
			continue;
		}

		auto ans = solve(n, k);
		if (ans[0].first == -1)
		{
			cout << "IMPOSSIBLE\n";
			continue;
		}

		cout << ans.size() << '\n';
		for (auto elem : ans)
		{
			cout << elem.first << ' ' << elem.second << '\n';
		}
	}
	return 0;
}