#include <iostream>
#include <vector>
#include <string>

using namespace std;

int abs(int a)
{
	return a >= 0 ? a : -a;
}

// È÷¿À½º
int hots(int r, int c)
{
	if (r == 0 && c == 0)
	{
		return 1;
	}
	if (c > 0 && abs(r) < abs(c))
	{
		return (2 * c - 1) * (2 * c - 1) + (c - r);
	}
	if (c < 0 && abs(r) <= abs(c))
	{
		return 4 * c * c + 1 + (r - c);
	}
	if (r > 0 && abs(c) <= abs(r))
	{
		return (2 * r + 1) * (2 * r + 1) - (r - c);
	}
	return 4 * r * r + 1 - (c - r);
}

int main(void)
{
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	vector<vector<int> > nums(r2 - r1 + 1, vector<int>(c2 - c1 + 1, 0));
	vector<vector<int> > lens(r2 - r1 + 1, vector<int>(c2 - c1 + 1, 0));
	int maxLen = 0;
	
	for (int r = r1; r <= r2; r++)
	{
		for (int c = c1; c <= c2; c++)
		{
			nums[r - r1][c - c1] = hots(r, c);
			lens[r - r1][c - c1] = to_string(nums[r - r1][c - c1]).length();
			if (maxLen < lens[r - r1][c - c1])
			{
				maxLen = lens[r - r1][c - c1];
			}
		}
	}

	for (int r = r1; r <= r2; r++)
	{
		for (int c = c1; c <= c2; c++)
		{
			for (int blankCount = 0; blankCount < maxLen - lens[r - r1][c - c1]; blankCount++)
			{
				cout << ' ';
			}
			cout << nums[r - r1][c - c1];
			cout << ' ';
		}
		cout << '\n';
	}

	return 0;
}