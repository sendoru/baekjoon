#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
typedef long double ld;
const ld PI = acos(-1.);
struct vector2d
{
	ld x, y;
	vector2d()
	{
		x = 0;
		y = 0;
	}
	vector2d(ld x_, ld y_)
	{
		x = x_;
		y = y_;
	}
	vector2d operator+(vector2d other)
	{
		return vector2d(x + other.x, y + other.y);
	}
	vector2d operator-(vector2d other)
	{
		return vector2d(x - other.x, y - other.y);
	}
	vector2d operator*(ld a)
	{
		return vector2d(a * x, a * y);
	}
	bool operator==(vector2d other)
	{
		return x == other.x && y == other.y;
	}
	bool operator!=(vector2d other)
	{
		return !(vector2d(x, y) == other);
	}
	bool operator<(vector2d other)
	{
		return y != other.y ? y > other.y : x < other.x;
	}
	ld normSquare()
	{
		return x * x + y * y;
	}
	ld norm()
	{
		return sqrt(normSquare());
	}
	ld dot(vector2d other)
	{
		return x * other.x + y * other.y;
	}
	ld cross(vector2d other)
	{
		return x * other.y - y * other.x;
	}
	vector2d unitVector()
	{
		if (x == 0 && y == 0)
		{
			return vector2d(x, y);
		}
		else
		{
			return vector2d(x / norm(), y / norm());
		}
	}
	ld polar()
	{
		return fmod(atan2(y, x) + 2 * PI, 2 * PI);
	}
};

ld ccw(vector2d p, vector2d a, vector2d b)
{
	return (a - p).cross(b - p);
}

int sgn(ld a)
{
	return a > 0 ? 1 : a == 0 ? 0 : -1;
}

int main(void)
{
	int p;
	cin >> p;
	while (p--)
	{
		int n;
		cin >> n;
		vector<vector2d> dots(n), convexHull;
		for (int i = 0; i < n; i++)
		{
			cin >> dots[i].x >> dots[i].y;
		}
		int firstDotIndex = 0;
		vector2d firstDot = dots[0];
		for (int i = 1; i < dots.size(); i++)
		{
			if (dots[i] < dots[firstDotIndex])
			{
				firstDotIndex = i;
				firstDot = dots[i];
			}
		}
		swap(dots[firstDotIndex], dots[0]);
		vector2d currentDot = firstDot;
		sort(dots.begin() + 1, dots.end(), [firstDot](vector2d a, vector2d b)
			{ ld ccwDiff = (b - firstDot).normSquare() * ccw(firstDot, vector2d(0, -1) + firstDot, a) * ccw(firstDot, vector2d(0, -1) + firstDot, a) * sgn(ccw(firstDot, vector2d(0, -1) + firstDot, a)) - (a - firstDot).normSquare() * ccw(firstDot, vector2d(0, -1) + firstDot, b) * ccw(firstDot, vector2d(0, -1) + firstDot, b) * sgn(ccw(firstDot, vector2d(0, -1) + firstDot, b));
		if (ccwDiff > 0) return true;
		if (ccwDiff < 0) return false;
		if (ccwDiff == 0) return (a - firstDot).normSquare() < (b - firstDot).normSquare();
			}
		);
		// 신나는 풍차돌리기
		convexHull.push_back(dots[0]);
		convexHull.push_back(dots[1]);
		for (int i = 2; i < dots.size(); i++)
		{
			while (convexHull.size() >= 2 && (ccw(convexHull[convexHull.size() - 2], convexHull[convexHull.size() - 1], dots[i]) >= 0))
			{
				convexHull.pop_back();
			}
			convexHull.push_back(dots[i]);

		}
		if (ccw(convexHull[convexHull.size() - 2], convexHull[convexHull.size() - 1], convexHull[0]) == 0)
		{
			convexHull.pop_back();
		}
		if (convexHull.size() == 1)
		{
			convexHull.push_back(dots.back());
		}
		cout << convexHull.size() << '\n';
		for (auto elem : convexHull)
		{
			cout << elem.x << ' ' << elem.y << '\n';
		}
	}
	return 0;
}