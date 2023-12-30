// https://codingcompetitions.withgoogle.com/codejam/round/00000000008778ec/0000000000b15a74

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
typedef long long ll;
using namespace std;

// TC : O(r)
void draw_circle_perimeter(vector<vector<int>>& plot, int r, int maxR)
{
	for (int x = -r; x <= r; x++)
	{
		int y = round(sqrt(r * r - x * x));   // round to nearest integer, breaking ties towards zero
		plot[x + maxR][y + maxR] = 1;
		plot[x + maxR][-y + maxR] = 1;
		plot[y + maxR][x + maxR] = 1;
		plot[-y + maxR][x + maxR] = 1;
	}
}

// O(r^2)
void draw_circle_field(vector<vector<int>>& plot, int r)
{
	for (int x = -r; x <= r; x++)
	{
		for (int y = -r; y <= r; y++)
		{
			if (round(sqrt(x * x + y * y)) <= r)
			{
				plot[x + r][y + r] = 1;
			}
		}
	}

	return;
}

// O(r^2)
void draw_circle_filled_wrong(vector<vector<int>>& plot, int r)
{
	for (int curR = 0; curR <= r; curR++)
	{
		draw_circle_perimeter(plot, curR, r);
	}
}

int solve(int r)
{
	vector<vector<int>> filled(2 * r + 1, vector<int>(2 * r + 1));
	vector<vector<int>> wrong(2 * r + 1, vector<int>(2 * r + 1));

	draw_circle_field(filled, r);
	draw_circle_filled_wrong(wrong, r);

	int ans = 0;
	for (int i = 0; i < filled.size(); i++)
	{
		for (int j = 0; j < filled[0].size(); j++)
		{
			if (filled[i][j] != wrong[i][j])
			{
				ans++;
			}
		}
	}

	return ans;

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
		int r;
		cin >> r;

		cout << "Case #" << t << ": " << solve(r) << '\n';
	}
	return 0;
}