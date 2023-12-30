#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}

void dp(vector<pair<int, int>> stickers, vector<pair<int, int>>& sum)
{
	sum[0].first = stickers[0].first;
	sum[0].second = stickers[0].second;

	sum[1].first = stickers[0].second + stickers[1].first;
	sum[1].second = stickers[0].first + stickers[1].second;

	for (int i = 2; i < stickers.size(); i++)
	{
		sum[i].first = max(sum[i - 1].second, max(sum[i - 2].first, sum[i - 2].second)) + stickers[i].first;
		sum[i].second = max(sum[i - 1].first, max(sum[i - 2].second, sum[i - 2].first)) + stickers[i].second;
	}
}

int main(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	vector<pair<int, int>> stickers;
	vector<pair<int, int>> sum;

	for (int t = 0; t < T; t++)
	{
		int N;
		cin >> N;
		stickers.resize(N);
		sum.resize(N);

		for (int i = 0; i < N; i++)
		{
			cin >> stickers[i].first;
		}
		for (int i = 0; i < N; i++)
		{
			cin >> stickers[i].second;
		}

		if (N == 1)
		{
			cout << max(stickers[0].first, stickers[0].second) << '\n';
			stickers.clear();
			sum.clear();
			continue;
		}

		dp(stickers, sum);

		cout << max(sum[N - 1].first, sum[N - 1].second) << '\n';

		stickers.clear();
		sum.clear();
	}

	return 0;
}