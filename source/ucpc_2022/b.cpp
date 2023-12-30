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

int ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
	ll tmp = (x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1);
	if (tmp > 0)	return 1;
	if (tmp == 0)	return 0;
	if (tmp < 0)	return -1;
	return 0;
}



struct Line
{
	ll x1, y1, x2, y2, w;

	Line(ll x1_, ll y1_, ll x2_, ll y2_, ll w_)
	{
		x1 = x1_;
		y1 = y1_;
		x2 = x2_;
		y2 = y2_;
		w = w_;
	}

	Line()
	{
		x1 = 0;
		y1 = 0;
		x2 = 0;
		y2 = 0;
		w = 0;
	}

	const bool operator<(const Line& other)
	{
		return w < other.w;
	}

	bool cross(const Line& other)
	{
		ll x3 = other.x1, x4 = other.x2;
		ll y3 = other.y1, y4 = other.y2;
		int isCross1 = ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4);
		int isCross2 = ccw(x3, y3, x4, y4, x1, y1) * ccw(x3, y3, x4, y4, x2, y2);
		return (isCross1 == -1 && isCross2 == -1);
	}
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<Line> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].x1 >> v[i].y1 >> v[i].x2 >> v[i].y2 >> v[i].w;
	}
	sort(v.begin(), v.end());

	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		ll curW = v[i].w;
		ll curCross = 0;
		for (int j = i + 1; j < n; j++)
		{
			curCross += (ll)v[i].cross(v[j]);
		}
		ans += (curCross + 1) * curW;
	}

	cout << ans;
	return 0;
}