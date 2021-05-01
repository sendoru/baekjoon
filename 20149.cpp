#include <iostream>
#include <string>

using namespace std;

typedef long long int lln;

int ccw(lln x1, lln y1, lln x2, lln y2, lln x3, lln y3)
{
	lln tmp = (x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1);
	if (tmp > 0)	return 1;
	if (tmp == 0)	return 0;
	if (tmp < 0)	return -1;
}

int main(void)
{
	cout.precision(11);

	lln x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> x3 >> y3 >> x4 >> y4;

	int isCross1 = ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4);
	int isCross2 = ccw(x3, y3, x4, y4, x1, y1) * ccw(x3, y3, x4, y4, x2, y2);

	if ((isCross1 == -1 && isCross2 == -1) || (isCross1 == 0 && isCross2 == -1) || (isCross1 == -1 && isCross2 == 0))
	{
		cout << 1 << endl;
		long double x = ((x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4)) / (long double)((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4));
		long double y = ((x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4)) / (long double)((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4));
		cout << x << ' ' << y << endl;
	}
	else if (isCross1 == 1 || isCross2 == 1)
	{
		cout << 0 << endl;
	}

	// 두 선분이 평행하거나 일부가 일치하는 경우
	else if ((x4 - x3) * (y2 - y1) == (x2 - x1) * (y4 - y3))
	{
		if (x1 - x2 == 0)
		{
			if ((y1 - y3) * (y2 - y3) <= 0 || (y1 - y4) * (y2 - y4) <= 0)
			{
				cout << 1 << endl;
				if (y1 > y2)
				{
					lln temp = y2;
					y2 = y1;
					y1 = temp;
				}
				if (y3 > y4)
				{
					lln temp = y4;
					y4 = y3;
					y3 = temp;
				}
				if (y1 > y3)
				{
					lln temp = y3;
					y3 = y1;
					y1 = temp;
					temp = y4;
					y4 = y2;
					y2 = temp;
				}
				if (y2 == y3)
				{
					cout << x2 << ' ' << y2 << endl;
				}
			}
			else
			{
				cout << 0 << endl;
			}
		}
		else
		{
			if ((x1 - x3) * (x2 - x3) <= 0 || (x1 - x4) * (x2 - x4) <= 0)
			{
				cout << 1 << endl;
				if (x1 > x2)
				{
					lln tempx = x2, tempy = y2;
					x2 = x1;
					x1 = tempx;
					y2 = y1;
					y1 = tempy;
				}
				if (x3 > x4)
				{
					lln tempx = x4, tempy = y4;
					x4 = x3;
					x3 = tempx;
					y4 = y3;
					y4 = tempy;
				}
				if (y1 > y3)
				{
					lln tempx = x3, tempy = y3;
					x3 = x1;
					x1 = tempy;
					y3 = y1;
					y1 = tempy;

					tempx = x4;
					tempy = y4;
					x4 = x2;
					x2 = tempx;
					y4 = y2;
					y2 = tempy;
				}
				if (x2 == x3)
				{
					cout << x2 << ' ' << y2 << endl;
				}
			}
			else
			{
				cout << 0 << endl;
			}
		}
	}
	else
	{
		cout << 1 << endl;
		long double x = ((x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4)) / (long double)((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4));
		long double y = ((x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4)) / (long double)((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4));
		cout << x << ' ' << y << endl;
	}

	return 0;
}

