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

	int N;
	int costs[1000][3];
	int minSums[1000][3];
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int tmp0, tmp1, tmp2;
		cin >> tmp0 >> tmp1 >> tmp2;
		costs[i][0] = tmp0;
		costs[i][1] = tmp1;
		costs[i][2] = tmp2;
	}
		
	minSums[0][0] = costs[0][0];
	minSums[0][1] = costs[0][1];
	minSums[0][2] = costs[0][2];


	for (int i = 1; i < N; i++)
	{
		minSums[i][0] = costs[i][0] + min(minSums[i - 1][1], minSums[i - 1][2]);
		minSums[i][1] = costs[i][1] + min(minSums[i - 1][0], minSums[i - 1][2]);
		minSums[i][2] = costs[i][2] + min(minSums[i - 1][0], minSums[i - 1][1]);
	}

	cout << min(minSums[N-1][0], min(minSums[N-1][1], minSums[N-1][2])) << endl;

	return 0;
}