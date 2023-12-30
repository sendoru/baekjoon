#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

vector<vector<int>> cols(int h1)
{
	vector<vector<int>> ret;
	for (int c11 = 1; c11 <= h1 - 2; c11++)
	{
		for (int c12 = 1; c12 <= h1 - c11 - 1; c12++)
		{
			ret.push_back({ c11, c12, h1 - c11 - c12 });
		}
	}

	return ret;
}

int main(void)
{
	int h1, h2, h3, w1, w2, w3;
	cin >> h1 >> h2 >> h3 >> w1 >> w2 >> w3;

	ll ans = 0;
	vector<vector<int>> col1 = cols(h1), col2 = cols(h2), col3 = cols(h3);
	for (auto& c1 : col1)
	{
		for (auto& c2 : col2)
		{
			for (auto& c3 : col3)
			{
				if (c1[0] + c2[0] + c3[0] == w1
					&& c1[1] + c2[1] + c3[1] == w2
					&& c1[2] + c2[2] + c3[2] == w3)
				{
					ans++;
				}
			}
		}
	}

	cout << ans;
	return 0;
}