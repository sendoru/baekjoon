#include <iostream>

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
	lln x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> x3 >> y3 >> x4 >> y4;

	int isCross1 = ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4);
	int isCross2 = ccw(x3, y3, x4, y4, x1, y1) * ccw(x3, y3, x4, y4, x2, y2);


	if ((isCross1 == -1 && isCross2 == -1) || (isCross1 == 0 && isCross2 == -1) || (isCross1 == -1 && isCross2 == 0))
	{
		cout << 1 << endl;
	}
	else if (isCross1 == 1 || isCross2 == 1)
	{
		cout << 0 << endl;
	}
	else if((x4 - x3) * (y2 - y1) == (x2 - x1) * (y4 - y3))
	{
		if (x1 - x2 == 0)
		{
			if ((y1 - y3) * (y2 - y3) <= 0 || (y1 - y4) * (y2 - y4) <= 0)
			{
				cout << 1 << endl;
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
	}

	return 0;
}

