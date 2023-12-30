#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
typedef long long ll;
using namespace std;

bool solve(int x, vector<pair<int, int>> ab)
{
	// bfs
	int n = ab.size();
	// visited[i][j] -> i는 (점프 횟수 - 1), j는 위치
	vector<vector<bool>> visited(n, vector<bool>(x + 1));
	visited[0][ab[0].first] = true;
	visited[0][ab[0].second] = true;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= x; j++)
		{
			if (visited[i - 1][j] && j + ab[i].first <= x)
			{
				visited[i][j + ab[i].first] = true;
			}
			if (visited[i - 1][j] && j + ab[i].second <= x)
			{
				visited[i][j + ab[i].second] = true;
			}
		}
	}


	return visited.back().back();
}

int main(void)
{
	int n, x;
	cin >> n >> x;
	vector<pair<int, int>> ab(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> ab[i].first >> ab[i].second;
	}

	cout << (solve(x, ab) ? "Yes" : "No");

	return 0;
}