#include <iostream>
#include <vector>

using namespace std;

int countOfPapers(int num, vector<vector<int>>& paper, int yStart, int yEnd, int xStart, int xEnd)
{
	if (yStart == yEnd || xStart == xEnd)
	{
		return 0;
	}

	if (yEnd - yStart == 1 && xEnd - xStart == 1 && paper[yStart][xStart] == num)
	{
		return 1;
	}

	if (yEnd - yStart == 1 && xEnd - xStart == 1 && paper[yStart][xStart] != num)
	{
		return 0;
	}

	int tmpColor = paper[yStart][xStart], ifBreak = 0;

	for (int i = yStart; i < yEnd; i++)
	{
		for (int j = xStart; j < xEnd; j++)
		{
			if (tmpColor != paper[i][j])
			{
				ifBreak = 1;
				break;
			}
			tmpColor = paper[i][j];
			if (i == yEnd - 1 && j == xEnd - 1)
			{
				if (tmpColor == num)
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}
		}
		if (ifBreak)
		{
			break;
		}
	}

	/*
	 1  |  2  |  3
	---------------
	 4  |  5  |  6
	---------------
	 7  |  8  |  9
	*/

	return countOfPapers(num, paper, yStart, yStart + (yEnd - yStart) / 3, xStart, xStart + (xEnd - xStart) / 3)
		+ countOfPapers(num, paper, yStart, yStart + (yEnd - yStart) / 3, xStart + (xEnd - xStart) / 3, xStart + 2 * (xEnd - xStart) / 3)
		+ countOfPapers(num, paper, yStart, yStart + (yEnd - yStart) / 3, xStart + 2 * (xEnd - xStart) / 3, xEnd)
		+ countOfPapers(num, paper, yStart + (yEnd - yStart) / 3, yStart + 2 * (yEnd - yStart) / 3, xStart, xStart + (xEnd - xStart) / 3)
		+ countOfPapers(num, paper, yStart + (yEnd - yStart) / 3, yStart + 2 * (yEnd - yStart) / 3, xStart + (xEnd - xStart) / 3, xStart + 2 * (xEnd - xStart) / 3)
		+ countOfPapers(num, paper, yStart + (yEnd - yStart) / 3, yStart + 2 * (yEnd - yStart) / 3, xStart + 2 * (xEnd - xStart) / 3, xEnd)
		+ countOfPapers(num, paper, yStart + 2 * (yEnd - yStart) / 3, yEnd, xStart, xStart + (xEnd - xStart) / 3)
		+ countOfPapers(num, paper, yStart + 2 * (yEnd - yStart) / 3, yEnd, xStart + (xEnd - xStart) / 3, xStart + 2 * (xEnd - xStart) / 3)
		+ countOfPapers(num, paper, yStart + 2 * (yEnd - yStart) / 3, yEnd, xStart + 2 * (xEnd - xStart) / 3, xEnd);
}



int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N;
	int temp;
	cin >> N;
	vector<vector<int>> paper;

	for (int i = 0; i < N; i++)
	{
		paper.push_back(vector<int> {});
		for (int j = 0; j < N; j++)
		{
			cin >> temp;
			paper[i].push_back(temp);
		}
	}

	cout << countOfPapers(-1, paper, 0, N, 0, N) << '\n';
	cout << countOfPapers(0, paper, 0, N, 0, N) << '\n';
	cout << countOfPapers(1, paper, 0, N, 0, N) << '\n';

	return 0;
}