#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > verify(vector<vector<int> >& a, int bound)
{
	int r = a.size(), c = a[0].size();
	vector<vector<int> > ret(r, vector<int>(c));
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (a[i][j] < bound)
				ret[i][j] = 1;
			else if (a[i][j] == bound)
				ret[i][j] = 0;
			else
				ret[i][j] = -1;
		}
	}
	return ret;
}


vector<vector<int> > getPartialSum(vector<vector<int> >& a)
{
	int r = a.size(), c = a[0].size();
	// ret[i][j] := a[0][0]과 a[i][j]를 꼭짓점으로 하는 사각형 내부의 모든 값의 합
	vector<vector<int> > ret(r, vector<int>(c));

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (i == 0 && j == 0)
			{
				ret[i][j] = a[i][j];
			}
			else if (i == 0 && j != 0)
			{
				ret[i][j] = ret[i][j - 1] + a[i][j];
			}
			else if (i != 0 && j == 0)
			{
				ret[i][j] = ret[i - 1][j] + a[i][j];
			}
			else
			{
				ret[i][j] = ret[i][j - 1] + ret[i - 1][j] - ret[i - 1][j - 1] + a[i][j];
			}
		}
	}

	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int r, c, h, w;
	cin >> r >> c >> h >> w;
	vector<vector<int> > a(r, vector<int>(c));
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> a[i][j];
		}
	}

	// int lowest = 1000000000 / 2;
	// int diff = 1000000000 / 4;
	int lowest = r * c / 2, prevLowest = r * c / 2, prevprevLowest;
	int diff = r * c / 4 + 1, prevDiff = diff, prevprevDiff;
	while (true)
	{
		vector<vector<int> > v = verify(a, lowest);
		vector<vector<int> > partialSum = getPartialSum(v);
		bool flag = false;
		prevprevDiff = prevDiff;
		prevDiff = diff;
		for (int i = 0; i < r - h + 1; i++)
		{
			for(int j = 0; j < c - w + 1; j++)
			{
				int sum;
				if (i == 0 && j == 0)
				{
					sum = partialSum[i + h - 1][j + w - 1];
				}
				else if (i == 0 && j != 0)
				{
					sum = partialSum[i + h - 1][j + w - 1] - partialSum[i + h - 1][j - 1];
				}
				else if (i != 0 && j == 0)
				{
					sum = partialSum[i + h - 1][j + w - 1] - partialSum[i - 1][j + w - 1];
				}
				else
				{
					sum = partialSum[i + h - 1][j + w - 1] - partialSum[i + h - 1][j - 1] - partialSum[i - 1][j + w - 1] + partialSum[i - 1][j - 1];
				}
				if (sum >= 0)
				{
					flag = true;
					break;
				}
			}
			if (flag)
			{
				break;
			}
		}

		if (flag)
		{
			if (diff == 1 && prevDiff == 1 && prevprevDiff == 1)
			{
				break;
			}
			lowest -= diff;
		}
		else
		{
			lowest += diff;
			if (diff == 1 && prevDiff == 1 && prevprevDiff == 1)
			{
				break;
			}
		}

		int remaining = diff & 1;
		diff = (diff >> 1) + remaining;
	}

	cout << lowest << '\n';
	return 0;
}