#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

// 처음 주어지는 picked는 {}

void pick(int n, vector<int> xVector, vector<int> yVector, set<int>& picked, int toPick, double& min)
{
	// 더 고를 게 없으면 고른 놈들은 +, 안 고른 놈들은 -
	if (toPick == 0)
	{
		int tempX = 0; int tempY = 0;
		for (int i = 0; i < picked.size() * 2; i++)
		{
			if (find(picked.begin(), picked.end(), i) != picked.end())
			{
				tempX += xVector[i];
				tempY += yVector[i];
			}
			else
			{
				tempX -= xVector[i];
				tempY -= yVector[i];
			}
		}

		double temp = pow((double)tempX * (double)tempX + (double)tempY * (double)tempY, 0.5);
		if (temp < min)
			min = temp;

		return;
	}

	for (int next = 0; next < n; next++)
	{
		if (picked.find(next) == picked.end())
		{
			picked.insert(next);
			pick(n, xVector, yVector, picked, toPick - 1, min);
			picked.erase(next);
		}
	}
}

int main(void)
{

	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int N;
		double min = 1000000000.0;
		cin >> N;
		set<int> emptySet;
		vector<int> xVector, yVector;
		int tempX, tempY;

		for (int i = 0; i < N; i++)
		{
			cin >> tempX >> tempY;
			xVector.push_back(tempX);
			yVector.push_back(tempY);
		}

		pick(N, xVector, yVector, emptySet, N / 2, min);
		printf("%f\n", min);
	}
	return 0;
}