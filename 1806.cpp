#include <iostream>
#include <vector>
#include <algorithm>

#define INF 987654321

using namespace std;

int main(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, S;
	cin >> N >> S;
	vector<int> sequence(N);
	for (int i = 0; i < N; i++)
	{
		cin >> sequence[i];
	}

	long long sum = 0;
	int minLen = INF;
	bool flag = 0;
	int p1 = 0, p2 = 0;
	while (true)
	{
		if (sum < S)
		{
			if (p2 == N) break;
			sum += sequence[p2];
			p2++;
		}
		else
		{
			minLen = min(minLen, p2 - p1);
			sum -= sequence[p1];
			p1++;
		}
	}

	if (minLen == INF)
	{
		cout << 0 << '\n';
	}
	else
	{
		cout << minLen << '\n';
	}

	return 0;
}