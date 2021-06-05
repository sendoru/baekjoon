#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void bfs(vector<vector<int> >& v, vector<vector<bool> >& check, int r, int c)
{
	int rSize = v.size();
	int cSize = v[0].size();
	vector<int> dr = { -1, 1, 0, 0 };
	vector<int> dc = { 0, 0, -1, 1 };

	if (check[r][c] || v[r][c] == 0)
	{
		return;
	}

	queue<pair<int, int> > q;
	q.push({ r, c });
	check[r][c] = true;
	while (!q.empty())
	{
		int rNext = q.front().first;
		int cNext = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			if (rNext + dr[i] >= 0 && rNext + dr[i] < rSize && cNext + dc[i] >= 0 && cNext + dc[i] < cSize && v[rNext + dr[i]][cNext + dc[i]] != 0 && !check[rNext + dr[i]][cNext + dc[i]])
			{
				check[rNext + dr[i]][cNext + dc[i]] = true;
				q.push({ rNext + dr[i], cNext + dc[i] });
			}
		}
	}
}

void sink(vector<vector<int> >& v)
{
	int rSize = v.size();
	int cSize = v[0].size();
	vector<int> dr = { -1, 1, 0, 0 };
	vector<int> dc = { 0, 0, -1, 1 };
	vector<vector<int> > sinkMap(rSize, vector<int>(cSize));

	for (int r = 0; r < rSize; r++)
	{
		for (int c = 0; c < cSize; c++)
		{
			for (int i = 0; i < 4; i++)
			{
				if (r + dr[i] >= 0 && r + dr[i] < rSize && c + dc[i] >= 0 && c + dc[i] < cSize && v[r + dr[i]][c + dc[i]] == 0)
				{
					sinkMap[r][c]++;
				}
			}
		}
	}

	for (int r = 0; r < rSize; r++)
	{
		for (int c = 0; c < cSize; c++)
		{
			if (v[r][c] != 0)
			{
				v[r][c] = max(0, v[r][c] - sinkMap[r][c]);
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int rSize, cSize, t = 0, cnt;
	cin >> rSize >> cSize;
	vector<vector<int> > v(rSize, vector<int>(cSize));
	for (int i = 0; i < rSize; i++)
	{
		for (int j = 0; j < cSize; j++)
		{
			cin >> v[i][j];
		}
	}

	while(true)
	{
		vector<vector<bool> > check(rSize, vector<bool>(cSize, false));
		cnt = 0;
		for (int r = 0; r < rSize; r++)
		{
			for (int c = 0; c < cSize; c++)
			{
				if (!check[r][c] && v[r][c] != 0)
				{
					bfs(v, check, r, c);
					cnt++;
				}
			}
		}
		if (cnt >= 2)
		{
			cout << t << '\n';
			return 0;
		}
		if (cnt == 0)
		{
			cout << 0 << '\n';
			return 0;
		}
		sink(v);
		t++;
	}
	
	
	return 0;
}