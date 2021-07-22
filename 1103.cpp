#include <iostream>
#include <vector>
#include <string>

using namespace std;
const int INF = 0x4ffffff;
bool hasCycle = false;

bool isinBoard(vector<string>& board, pair<int, int> coin)
{
	int rSize = board.size(), cSize = board[0].size();
	return coin.first >= 0 && coin.first < rSize && coin.second >= 0 && coin.second < cSize && board[coin.first][coin.second] != 'H';
}


int move(vector<string>& board, vector<vector<int>>& cache, vector<vector<bool>>& visited, vector<vector<bool>>& noCycle, pair<int, int> coin)
{

	int dr[] = { 1, -1, 0, 0 };
	int dc[] = { 0, 0, 1, -1 };
	int r = coin.first, c = coin.second;
	int& ret = cache[r][c];
	if (visited[r][c])
	{
		hasCycle = true;
		return INF;
	}
	if (cache[r][c] != 1)
	{
		return cache[r][c];
	}
	visited[r][c] = true;
	for (int i = 0; i < 4; i++)
	{
		int nextR = r + dr[i] * (board[r][c] - '0');
		int nextC = c + dc[i] * (board[r][c] - '0');
		if (isinBoard(board, { nextR, nextC }))
		{
			if (!hasCycle)
			{
				ret = max(ret, move(board, cache, visited, noCycle, { nextR, nextC }) + 1);
			}
		}
	}
	visited[r][c] = false;
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<string> board(n);
	vector<vector<int>> cache(n, vector<int>(m, 1));
	vector<vector<bool>> visited(n, vector<bool>(m));
	vector<vector<bool>> noCycle(n, vector<bool>(m));
	for (int i = 0; i < n; i++)
	{
		cin >> board[i];
	}
	int ans = move(board, cache, visited, noCycle, { 0, 0 });
	if (ans >= INF)
	{
		cout << -1 << '\n';
	}
	else
	{
		cout << ans << '\n';
	}
	return 0;
}