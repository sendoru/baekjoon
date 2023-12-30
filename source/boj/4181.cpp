

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
		return x != other.x ? x < other.x : y < other.y;
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
	int n;
	cin >> n;
	vector<vector2d> dots, convexHull;
	for (int i = 0; i < n; i++)
	{
		vector2d tempVec;
		char tempStr;
		cin >> tempVec.x >> tempVec.y >> tempStr;
		if (tempStr == 'Y')
		{
			dots.push_back(tempVec);
		}
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
		{ ld ccwDiff = ccw(firstDot, vector2d(1, 0) + firstDot, a) / (a - firstDot).norm() - ccw(firstDot, vector2d(1, 0) + firstDot, b) / (b - firstDot).norm();
	if (ccwDiff < 0)
		return true;
	if (ccwDiff > 0)
		return false;
	if (ccwDiff == 0)
		return (a - firstDot).normSquare() < (b - firstDot).normSquare();
		}
	);
	ld firstAngle = ccw(firstDot, vector2d(1, 0) + firstDot, dots[1]) / (dots[1] - firstDot).norm();
	sort(dots.begin() + 1, dots.end(), [firstDot, firstAngle](vector2d a, vector2d b)
		{ ld ccwDiff = ccw(firstDot, vector2d(1, 0) + firstDot, a) / (a - firstDot).norm() - ccw(firstDot, vector2d(1, 0) + firstDot, b) / (b - firstDot).norm();
	if (ccwDiff < 0)
		return true;
	if (ccwDiff > 0)
		return false;
	if (ccwDiff == 0)
	{
		if (ccw(firstDot, vector2d(1, 0) + firstDot, a) / (a - firstDot).norm() > firstAngle)
		{
			return (a - firstDot).normSquare() > (b - firstDot).normSquare();
		}
		else
		{
			return (a - firstDot).normSquare() < (b - firstDot).normSquare();
		}
	}
		}
	);
	// 신나는 풍차돌리기
	convexHull.push_back(dots[0]);
	convexHull.push_back(dots[1]);
	for (int i = 2; i < dots.size(); i++)
	{
		while (convexHull.size() >= 2 && (ccw(convexHull[convexHull.size() - 2], convexHull[convexHull.size() - 1], dots[i]) < 0))
		{
			dots.push_back(convexHull.back());
			convexHull.pop_back();
		}
		convexHull.push_back(dots[i]);
	}

	cout << convexHull.size() << '\n';
	for (auto elem : convexHull)
	{
		cout << elem.x << ' ' << elem.y << '\n';
	}
	return 0;


}