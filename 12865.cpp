#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}

int cache[100001][100];

int pack(int N, int K, vector<pair<int, int>>& items, int index)
{
	if (index == N)	    return 0;
	int& ret = cache[K][index];
	if (ret != 1)       return ret;

	ret = pack(N, K, items, index + 1);
	if (K >= items[index].first)
	{
		ret = max(ret, pack(N, K - items[index].first, items, index + 1) + items[index].second);
	}
	return ret;
}

int main(void)
{
	int N, K;
	cin >> N >> K;

	vector<pair<int, int>> items;
	vector<bool> picked(N);

	for (int i = 0; i < N; i++)
	{
		int W, V;
		cin >> W >> V;
		items.push_back(make_pair(W, V));
	}

	for (int i = 0; i <= 100000; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			cache[i][j] = -1;
		}
	}

	cout << pack(N, K, items, 0) << endl;

	return 0;
}