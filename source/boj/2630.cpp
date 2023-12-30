#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int countOfPapers(int size, int num, short** paper)
{
	if (size == 1 && paper[0][0] == num)
	{
		return 1;
	}

	if (size == 1 && paper[0][0] != num)
	{
		return 0;
	}

	int tmpColor = num, ifBreak = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (tmpColor != paper[i][j])
			{
				ifBreak = 1;
				break;
			}
			tmpColor = paper[i][j];
			if (i == size - 1 && j == size - 1)
			{
				return 1;
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

	short** subPaper1 = new short* [size / 3];
	for (int i = 0; i < size / 3; i++) subPaper1[i] = new short[size / 3];
	short** subPaper2 = new short* [size / 3];
	for (int i = 0; i < size / 3; i++) subPaper2[i] = new short[size / 3];
	short** subPaper3 = new short* [size / 3];
	for (int i = 0; i < size / 3; i++) subPaper3[i] = new short[size / 3];
	short** subPaper4 = new short* [size / 3];
	for (int i = 0; i < size / 3; i++) subPaper4[i] = new short[size / 3];
	short** subPaper5 = new short* [size / 3];
	for (int i = 0; i < size / 3; i++) subPaper5[i] = new short[size / 3];
	short** subPaper6 = new short* [size / 3];
	for (int i = 0; i < size / 3; i++) subPaper6[i] = new short[size / 3];
	short** subPaper7 = new short* [size / 3];
	for (int i = 0; i < size / 3; i++) subPaper7[i] = new short[size / 3];
	short** subPaper8 = new short* [size / 3];
	for (int i = 0; i < size / 3; i++) subPaper8[i] = new short[size / 3];
	short** subPaper9 = new short* [size / 3];
	for (int i = 0; i < size / 3; i++) subPaper9[i] = new short[size / 3];
	

	for (int i = 0; i < size / 3; i++)
	{
		for (int j = 0; j < size / 3; j++)				subPaper1[i][j] = paper[i][j];
		for (int j = size / 3; j < 2 * size / 3; j++)	subPaper2[i][j - size/3] = paper[i][j];
		for (int j = 2 * size / 3; j < size; j++)		subPaper3[i][j - 2*size/3] = paper[i][j];

	}
	for (int i = size / 3; i < 2 * size / 3; i++)
	{
		for (int j = 0; j < size / 3; j++)				subPaper4[i - size/3][j] = paper[i][j];
		for (int j = size / 3; j < 2 * size / 3; j++)	subPaper5[i - size/3][j - size/3] = paper[i][j];
		for (int j = 2 * size / 3; j < size; j++)		subPaper6[i - size/3][j - 2*size/3] = paper[i][j];

	}
	for (int i = 2 * size / 3; i < size; i++)
	{
		for (int j = 0; j < size / 3; j++)				subPaper7[i - 2 * size / 3][j] = paper[i][j];
		for (int j = size / 3; j < 2 * size / 3; j++)	subPaper8[i - 2 * size / 3][j - size/3] = paper[i][j];
		for (int j = 2 * size / 3; j < size; j++)		subPaper9[i - 2 * size / 3][j - 2*size/3] = paper[i][j];

	}

	return countOfPapers(size / 3, num, subPaper1) + countOfPapers(size / 3, num, subPaper2) + countOfPapers(size / 3, num, subPaper3) + countOfPapers(size / 3, num, subPaper4) + countOfPapers(size / 3, num, subPaper5) + countOfPapers(size / 3, num, subPaper6) + countOfPapers(size / 3, num, subPaper7) + countOfPapers(size / 3, num, subPaper8) + countOfPapers(size / 3, num, subPaper9);
}



int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N;
	int temp;
	cin >> N;
	short** paper = new short* [N];

	for (int i = 0; i < N; i++)
	{
		paper[i] = new short[N];
		for (int j = 0; j < N; j++)
		{
			cin >> paper[i][j];
		}
	}

	cout << countOfPapers(N, -1, paper) << '\n';
	cout << countOfPapers(N, 0, paper) << '\n';
	cout << countOfPapers(N, 1, paper) << '\n';

	return 0;
}