#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> boxes(n, vector<int>(m));
	vector<vector<bool>> keeped(n, vector<bool>(m));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> boxes[i][j];
		}
	}

	for (int r = 0; r < n; r++)
	{
		int maxHeight = 0;
		for (int c = 0; c < m; c++)
		{
			if (boxes[r][c] > maxHeight)
			{
				maxHeight = boxes[r][c];
			}
		}

		for (int c = 0; c < m; c++)
		{
			if (boxes[r][c] == maxHeight)
			{
				keeped[r][c] = true;
				break;
			}
		}
	}

	for (int c = 0; c < m; c++)
	{
		int maxHeight = 0;
		for (int r = 0; r < n; r++)
		{
			if (boxes[r][c] > maxHeight)
			{
				maxHeight = boxes[r][c];
			}
		}

		for (int r = 0; r < n; r++)
		{
			if (boxes[r][c] == maxHeight)
			{
				keeped[r][c] = true;
				break;
			}
		}
	}

	ll ans = 0;
	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < m; c++)
		{
			if (!keeped[r][c])
			{
				ans += boxes[r][c];
			}
		}
	}

	cout << ans;
	return 0;
}