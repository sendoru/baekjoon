#include <iostream>

using namespace std;

int triangle[501][501];
int maxSum[501][501];

int max(int a, int b)
{
	if (a > b) return a;
	return b;
}

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 501; i++)
	{
		for (int j = 0; j < 501; j++)
		{
			triangle[i][j] = 0;
			maxSum[i][j] = 0;
		}
	}

	int N, temp;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> temp;
			triangle[i][j] = temp;
		}
	}

	maxSum[0][0] = triangle[0][0];

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
			{
				maxSum[i][j] = triangle[i][j] + maxSum[i - 1][0];
			}
			else
			{
				maxSum[i][j] = triangle[i][j] + max(maxSum[i - 1][j - 1], maxSum[i-1][j]);
			}
		}
	}

	int ref = 0;
	for (int i = 0; i < N; i++)
	{
		ref = max(ref, maxSum[N - 1][i]);
	}

	cout << ref << '\n';

	return 0;
}