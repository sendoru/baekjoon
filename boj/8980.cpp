#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
typedef long long ll;
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, c, m;
	cin >> n >> c;
	cin >> m;
	vector<vector<ll>> boxes2d(n + 1, vector<ll>(n + 1));
	for (int i = 0; i < m; i++)
	{
		ll start, end, boxCnt;
		cin >> start >> end >> boxCnt;
		boxes2d[start][end] += boxCnt;
	}

	vector<vector<pair<ll, ll>>> boxes(n + 1);
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (boxes2d[i][j] != 0)
			{
				boxes[i].push_back({ j, boxes2d[i][j] });
			}
		}
	}

	map<ll, ll> curBox;
	ll curBoxSum = 0;
	ll ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += curBox[i];
		curBoxSum -= curBox[i];
		curBox[i] = 0;
		for (auto elem : boxes[i])
		{
			while (c - curBoxSum < elem.second && curBoxSum != 0)
			{
				if (elem.first >= (*--curBox.end()).first) break;
				if (c - curBoxSum + (*--curBox.end()).second > elem.second)
				{
					curBox[(*--curBox.end()).first] -= elem.second - (c - curBoxSum);
					curBoxSum -= elem.second - (c - curBoxSum);
				}
				else
				{
					curBoxSum -= (*--curBox.end()).second;
					curBox.erase(--curBox.end());
				}
			}
			if (c - curBoxSum < elem.second)
			{
				curBox[elem.first] += c - curBoxSum;
				curBoxSum = c;
			}
			else
			{
				curBox[elem.first] += elem.second;
				curBoxSum += elem.second;
			}
		}
	}

	cout << ans;
	return 0;
}