#include <iostream>
#include <cstring>
#include <algorithm>
#define INF 987654321

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int nums[2][3] = { 0, };
	int dpMax[2][3] = { 0, };
	int dpMin[2][3];
	for (int i = 0; i < 6; i++)
	{
		dpMin[0][i] = INF;
	}

	cin >> n;

	cin >> nums[0][0] >> nums[0][1] >> nums[0][2];
	for (int i = 0; i < 3; i++)
	{
		dpMax[0][i] = nums[0][i];
		dpMin[0][i] = nums[0][i];
	}

	for (int i = 1; i < n; i++)
	{
		cin >> nums[i % 2][0] >> nums[i % 2][1] >> nums[i % 2][2];
		dpMax[i % 2][0] = max(dpMax[(i - 1) % 2][0], dpMax[(i - 1) % 2][1]) + nums[i % 2][0];
		dpMax[i % 2][1] = max(dpMax[(i - 1) % 2][0], max(dpMax[(i - 1) % 2][1], dpMax[(i - 1) % 2][2])) + nums[i % 2][1];
		dpMax[i % 2][2] = max(dpMax[(i - 1) % 2][1], dpMax[(i - 1) % 2][2]) + nums[i % 2][2];
		dpMin[i % 2][0] = min(dpMin[(i - 1) % 2][0], dpMin[(i - 1) % 2][1]) + nums[i % 2][0];
		dpMin[i % 2][1] = min(dpMin[(i - 1) % 2][0], min(dpMin[(i - 1) % 2][1], dpMin[(i - 1) % 2][2])) + nums[i % 2][1];
		dpMin[i % 2][2] = min(dpMin[(i - 1) % 2][1], dpMin[(i - 1) % 2][2]) + nums[i % 2][2];
	}

	cout << max(dpMax[(n - 1) % 2][0], max(dpMax[(n - 1) % 2][1], dpMax[(n - 1) % 2][2])) << ' ' << min(dpMin[(n - 1) % 2][0], min(dpMin[(n - 1) % 2][1], dpMin[(n - 1) % 2][2])) << '\n';

	return 0;
}