#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(void)
{
	int N, temp, lenofLIS = 1;
	cin >> N;
	vector<int> sequence;
	vector<int> dp;
	vector<bool> isIncludedInLIS;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		sequence.push_back(temp);
		dp.push_back(0);
	}

	for (int i = 0; i < N; i++)
	{
		dp[i] = sequence[i];
		for (int j = 0; j < i; j++)
		{
			if (sequence[i] > sequence[j] && dp[i] < dp[j] + sequence[i])
				dp[i] = dp[j] + sequence[i];
		}
	}


	cout << *max_element(dp.begin(), dp.end()) << endl;
	return 0;

}