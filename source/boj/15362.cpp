#include <iostream>
using namespace std;

int x11, y11, r11, x22, y22, r22, x33, y33, r33;
double ans;

bool isinRange(double x, double y)
{
	double i = x, j = y;
	return ((i - x11) * (i - x11) + (j - y11) * (j - y11) < r11 * r11
		|| (i - x22) * (i - x22) + (j - y22) * (j - y22) < r22 * r22
		|| (i - x33) * (i - x33) + (j - y33) * (j - y33) < r33 * r33);
}

void solve(double xl, double xr, double yd, double yu)
{
	if (isinRange(xl, yu) && isinRange(xl, yd) && isinRange(xr, yu) && isinRange(xr, yd))
	{
		ans += (xr - xl) * (yu - yd);
		return;
	}
	double xm = (xr + xl) / 2, ym = (yu + yd) / 2;
	if (xr - xl < 0.01)
	{
		if (isinRange(xm, ym))
		{
			ans += (xr - xl) * (yu - yd);
		}
		return;
	}
	solve(xl, xm, yd, ym);
	solve(xm, xr, yd, ym);
	solve(xl, xm, ym, yu);
	solve(xm, xr, ym, yu);
	return;
}

int main(void)
{
	double ans = 0.;
	cin >> x11 >> y11 >> r11 >> x22 >> y22 >> r22 >> x33 >> y33 >> r33;
	solve(0, 100, 0, 100);
	cout << ans << '\n';
	return 0;
}