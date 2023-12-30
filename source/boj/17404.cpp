#include <iostream>
int min(int a, int b)
{
	if (a < b) return a;
	return b;
}

using namespace std;

int main(void)
{
	cin.tie(NULL);

	int N, minSum;
	int costs[1000][3];
	int minSums[3][1000][3];
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int tmp0, tmp1, tmp2;
		cin >> tmp0 >> tmp1 >> tmp2;
		costs[i][0] = tmp0;
		costs[i][1] = tmp1;
		costs[i][2] = tmp2;
	}

	


	// 0번째 집이 R, G, B 색인 경우 각각 구하기 위해 하는 짓
	for (int color = 0; color < 3; color++)
	{
		minSums[color][0][0] = costs[0][0];
		minSums[color][0][1] = costs[0][1];
		minSums[color][0][2] = costs[0][2];

		for (int i = 0; i < N; i++)
		{
			if (i == 0)
			{
				if (color == 0)
				{
					minSums[color][i][0] = costs[0][0];
					minSums[color][i][1] = 1 << 30;
					minSums[color][i][2] = 1 << 30;
				}
				else if (color == 1)
				{
					minSums[color][i][0] = 1 << 30;
					minSums[color][i][1] = costs[0][1];
					minSums[color][i][2] = 1 << 30;
				}
				else
				{
					minSums[color][i][0] = 1 << 30;
					minSums[color][i][1] = 1 << 30;
					minSums[color][i][2] = costs[0][2];
				}
			}
			else
			{
				minSums[color][i][0] = costs[i][0] + min(minSums[color][i - 1][1], minSums[color][i - 1][2]);
				minSums[color][i][1] = costs[i][1] + min(minSums[color][i - 1][0], minSums[color][i - 1][2]);
				minSums[color][i][2] = costs[i][2] + min(minSums[color][i - 1][0], minSums[color][i - 1][1]);
			}
		}
	}
	 
	minSum = minSums[0][N - 1][1];

	for(int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (i != j)
				minSum = min(minSum, minSums[i][N - 1][j]);

	cout << minSum << endl;

	return 0;
}