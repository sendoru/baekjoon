#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<pair<ll, ll>> labeled(n);
	for (int i = 0; i < n; i++) cin >> labeled[i].first;
	for (int i = 0; i < n; i++) cin >> labeled[i].second;
	sort(labeled.begin(), labeled.end());

	// dp[i][0] := i번째 선이 안 꺾여있을 때, i + 1 ~ 끝까지 선 중에 꺾인 선의 갯수의 최솟값
	// dp[i][1] := i번째 선이 꺾여있을 때, i + 1 ~ 끝까지 선 중에 꺾인 선의 갯수의 최솟값
	vector<vector<ll>> dp(n, vector<ll>(2));
	ll ans = n;
	for (int i = n - 2; i >= 0; i--)
	{
		int dist = labeled[i + 1].first - labeled[i].first;
		if (dist >= labeled[i].second + 1)
		{

		}
		else
		{

		}
	}
}