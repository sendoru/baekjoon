#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<int>> cache(10001, vector<int>(4001, -1));

int pack(int n, int m, vector<pair<int, int>>& items, int index)
{
	if (index == n)	    return 0;
	int& ret = cache[m][index];
	if (ret != -1)       return ret;

	ret = pack(n, m, items, index + 1);
	if (m >= items[index].first)
	{
		ret = max(ret, pack(n, m - items[index].first, items, index + 1) + items[index].second);
	}
	return ret;
}

// v: 무게, c: 만족도, k: 물건 갯수
vector<pair<int, int>> decompose(int v, int c, int k)
{
	vector<pair<int, int>> ret;
	while (k > 1)
	{
		int bunchSize = 1;
		while (bunchSize < k)
		{
			ret.push_back({ bunchSize * v, bunchSize * c });
			k -= bunchSize;
			bunchSize <<= 1;
		}
	}
	if (k == 1)
	{
		ret.push_back({ v, c });
	}
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> items(n, vector<int>(3));
	vector<pair<int, int>> decomposedItems;

	for (int i = 0; i < n; i++)
	{
		cin >> items[i][0] >> items[i][1] >> items[i][2];
	}

	for (auto item : items)
	{
		auto decomposed = decompose(item[0], item[1], item[2]);
		for (auto decomposedItem : decomposed)
		{
			decomposedItems.push_back(decomposedItem);
		}
	}

	cout << pack(decomposedItems.size(), m, decomposedItems, 0) << '\n';

	return 0;
}