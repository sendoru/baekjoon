#include <iostream>
#include <vector>
#include <string>
using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}

int main(void)
{
	int N, M, ans = 1;
	string temp;
	cin >> N >> M;

	vector<vector<int>> rectangle(N);

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		for (int j = 0; j < M; j++)
		{
			rectangle[i].push_back(temp[j] - '0');
		}
	}


	for (int size = min(N, M); size > 1; size--)
	{
		for (int h = 0; h <= N - size; h++)
		{
			for (int w = 0; w <= M - size; w++)
			{
				if (rectangle[h][w] == rectangle[h][w + size - 1] && rectangle[h][w] == rectangle[h + size - 1][w] && rectangle[h][w] == rectangle[h + size - 1][w + size - 1])
				{
					ans = size * size;
					cout << ans << endl;
					return 0;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}