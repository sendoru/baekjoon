#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>
#include <functional>
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 0x3fffffff;
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;
	string compressed;
	for (auto elem : s)
	{
		if (elem == '?' || elem == ':')
		{
			compressed.push_back(elem);
		}
	}

	vector<ll> dp(compressed.length());
	dp[0] = 1;
	for (int i = 1; i < dp.size(); i++)
	{

	}
}