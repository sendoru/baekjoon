#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <stack>
#define INF 98764321

using namespace std;


int main(void)
{
	int N, temp, lenofLIS = 1, start = 0;
	cin >> N;
	vector<int> sequence;
	vector<int> dp;
	vector<int> backTracking;
	stack<int> LIS;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		sequence.push_back(temp);
		dp.push_back(1);
		backTracking.push_back(-1);
	}

	for (int i = 0; i < N; i++)
	{
		int end = sequence[i];
		for (int j = 0; j < i; j++)
		{
			if (end > sequence[j])
			{
				if (dp[j] + 1 > dp[i])
				{
					dp[i] = dp[j] + 1;
					backTracking[i] = j;
				}
			}
		}
		if (dp[i] > lenofLIS)
		{
			lenofLIS = dp[i];
			start = i;
		}
	}


	cout << lenofLIS << endl;
	int index = start;
	while (index != -1)
	{
		LIS.push(sequence[index]);
		index = backTracking[index];
	}
	while (!LIS.empty())
	{
		cout << LIS.top() << ' ';
		LIS.pop();
	}
	cout << endl;
	return 0;

}