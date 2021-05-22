#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef long double ld;

ld cubicFunction(ld a, ld b, ld c, ld d, ld x)
{
	return a * x * x * x + b * x * x + c * x + d;
}

ld determinant(ld a, ld b, ld c)
{
	return b * b - 4 * a * c;
}

pair<int, vector<ld> > solve2(ld a, ld b, ld c)
{
	ld d = determinant(a, b, c);
	if (d > 0)
	{
		return { 2, {(-b + sqrtl(d)) / (2 * a), (-b - sqrtl(d)) / (2 * a)} };
	}
	else if (d == 0)
	{
		return { 1, {-b / (2 * a)} };
	}
	else
	{
		return { 0, {} };
	}
}

pair<int, vector<ld> > solve3(ld a, ld b, ld c, ld d)
{
	ld x0, x1, x2;
	if (a < 0)
	{
		a *= -1;
		b *= -1;
		c *= -1;
		d *= -1;
	}
	pair<int, vector<ld> > rootOfDerivative = solve2(3 * a, 2 * b, c);

	if (rootOfDerivative.first <= 1)
	{
		if (cubicFunction(a, b, c, d, -b / (3 * a)) > 0)
		{
			x0 = -b / (3 * a) - 1;
		}
		else
		{
			x0 = -b / (3 * a) + 1;
		}
		for (int i = 0; i < 2000; i++)
		{
			x0 = x0 - cubicFunction(a, b, c, d, x0) / cubicFunction(0, 3 * a, 2 * b, c, x0);
		}

		return { 1, {x0} };
	}

	else
	{
		ld localMax = cubicFunction(a, b, c, d, rootOfDerivative.second[0]);
		ld localMin = cubicFunction(a, b, c, d, rootOfDerivative.second[1]);

		/*
		if (localMax > 0 && localMin > 0)
		{
			x0 = rootOfDerivative.second[0] - 1;
			for (int i = 0; i < 200; i++)
			{
				x0 = x0 - cubicFunction(a, b, c, d, x0) / cubicFunction(0, 3 * a, 2 * b, c, x0);
			}
			return { 1, {x0} };
		}
		else if (localMax < 0 && localMin < 0)
		{
			x0 = rootOfDerivative.second[1] + 1;
			for (int i = 0; i < 200; i++)
			{
				x0 = x0 - cubicFunction(a, b, c, d, x0) / cubicFunction(0, 3 * a, 2 * b, c, x0);
			}
			return { 1, {x0} };
		}
		else
		*/
		{
			x0 = rootOfDerivative.second[0] - 1;
			x1 = (rootOfDerivative.second[0] + rootOfDerivative.second[1]) / 2;
			x2 = rootOfDerivative.second[1] + 1;
			for (int i = 0; i < 2000; i++)
			{
				x0 = x0 - cubicFunction(a, b, c, d, x0) / cubicFunction(0, 3 * a, 2 * b, c, x0);
				x1 = x1 - cubicFunction(a, b, c, d, x1) / cubicFunction(0, 3 * a, 2 * b, c, x1);
				x2 = x2 - cubicFunction(a, b, c, d, x2) / cubicFunction(0, 3 * a, 2 * b, c, x2);
			}
			vector<ld> v = { x0, x1, x2 };
			sort(v.begin(), v.end());
			if (fabsl(x2 - x1) <= 0.99e-4)
			{
				v.erase(v.begin() + 2);
			}
			if (fabsl(x1 - x0) <= 0.99e-4)
			{
				v.erase(v.begin() + 1);
			}
			return { v.size(), v };
		}
	}
}

int main(void)
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.fixed;
	cout.precision(5);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		ld a, b, c, d;
		cin >> a >> b >> c >> d;
		vector<ld> root = solve3(a, b, c, d).second;
		for (ld elem : root)
		{
			elem *= 10000;
			elem = roundl(elem);
			elem /= 10000;
			cout << elem << ' ';
		}
		cout << '\n';
	}

	return 0;
}