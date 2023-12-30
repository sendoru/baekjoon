#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;

int ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
	ll tmp = (x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1);
	if (tmp > 0)	return 1;
	if (tmp == 0)	return 0;
	if (tmp < 0)	return -1;
}

void swap(ll& a, ll& b)
{
	ll temp = a;
	a = b;
	b = temp;
}

pair<int, int> cross(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4)
{

	int isCross1 = ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4);
	int isCross2 = ccw(x3, y3, x4, y4, x1, y1) * ccw(x3, y3, x4, y4, x2, y2);

	if ((isCross1 == -1 && isCross2 == -1) || (isCross1 == 0 && isCross2 == -1) || (isCross1 == -1 && isCross2 == 0))
	{
		if (ccw(x1, y1, x2, y2, x3, y3) == 0 || ccw(x1, y1, x2, y2, x4, y4) == 0)
		{
			return { 1, 1 };
		}
		else
		{
			return { 1, 0 };
		}
	}

	else if (isCross1 == 1 || isCross2 == 1)
	{
		return { 0, 0 };
	}

	// 두 선분의 방향벡터가 평행할 경우
	else if ((x4 - x3) * (y2 - y1) == (x2 - x1) * (y4 - y3))
	{
		if (x1 == x2)
		{
			if ((y1 - y3) * (y2 - y3) <= 0 || (y1 - y4) * (y2 - y4) <= 0
				|| (y1 >= min(y3, y4) && y1 <= max(y3, y4) && y2 >= min(y3, y4) && y2 <= max(y3, y4))
				|| (y3 >= min(y1, y2) && y3 <= max(y1, y2) && y4 >= min(y1, y2) && y4 <= max(y1, y2)))
			{
				vector<ll> dots = { y1, y2, y3, y4 };
				sort(dots.begin(), dots.end());
				if (dots[1] == dots[2])
				{
					return { 1, 1 };
				}
				else
				{
					return { 100, 0 };
				}
			}
			else
			{
				return { 0, 0 };
			}
		}
		else
		{
			if ((x1 - x3) * (x2 - x3) <= 0 || (x1 - x4) * (x2 - x4) <= 0
				|| (x1 >= min(x3, x4) && x1 <= max(x3, x4) && x2 >= min(x3, x4) && x2 <= max(x3, x4))
				|| (x3 >= min(x1, x2) && x3 <= max(x1, x2) && x4 >= min(x1, x2) && x4 <= max(x1, x2)))
			{
				vector<ll> dots = { x1, x2, x3, x4 };
				sort(dots.begin(), dots.end());
				if (dots[1] == dots[2])
				{
					return { 1, 1 };
				}
				else
				{
					return { 100, 0 };
				}
			}
			else
			{
				return { 0, 0 };
			}
		}
	}
	else
	{
		return { 1, 1 };
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll xStart, yStart, xEnd, yEnd, xLeft, yTop, xRight, yBottom, T;
	cin >> T;
	while (T--)
	{
		cin >> xLeft >> yTop >> xRight >> yBottom;
		cin >> xStart >> yStart >> xEnd >> yEnd;
		int crossCnt = 0;
		int duplicated = 0;
		pair<int, int> p;

		vector<ll> x(4);
		vector<ll> y(4);

		x[0] = xLeft, y[0] = yTop;
		x[1] = xLeft, y[1] = yBottom;
		x[2] = xRight, y[2] = yBottom;
		x[3] = xRight, y[3] = yTop;

		for (int i = 0; i < 4; i++)
		{
			p = cross(xStart, yStart, xEnd, yEnd, x[i], y[i], x[(i + 1) % 4], y[(i + 1) % 4]);
			crossCnt += p.first;
			duplicated += p.second;
		}

		if (crossCnt > 99)
		{
			cout << 4 << '\n';
		}
		else if (crossCnt > 0)
		{
			cout << crossCnt - duplicated / 2 << '\n';
		}
		else
		{
			cout << 0 << '\n';
		}
	}

	return 0;
}