#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
	ll tmp = (x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1);
	if (tmp > 0)	return 1;
	if (tmp == 0)	return 0;
	if (tmp < 0)	return -1;
}

bool isCross(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4)
{
	int isCross1 = ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4);
	int isCross2 = ccw(x3, y3, x4, y4, x1, y1) * ccw(x3, y3, x4, y4, x2, y2);

	if ((isCross1 == -1 && isCross2 == -1) || (isCross1 == 0 && isCross2 == -1) || (isCross1 == -1 && isCross2 == 0))
		return true;

	else if (isCross1 == 1 || isCross2 == 1)
		return false;

	else if ((x4 - x3) * (y2 - y1) == (x2 - x1) * (y4 - y3)) {
		if (y1 - y2 == 0) {
			swap(x1, y1); swap(x2, y2); swap(x3, y3); swap(x4, y4);
		}

		if ((y1 - y3) * (y2 - y3) <= 0 || (y1 - y4) * (y2 - y4) <= 0
			|| (y1 >= min(y3, y4) && y1 <= max(y3, y4) && y2 >= min(y3, y4) && y2 <= max(y3, y4))
			|| (y3 >= min(y1, y2) && y3 <= max(y1, y2) && y4 >= min(y1, y2) && y4 <= max(y1, y2)))
			return true;

		else
			return false;
	}
		return true;
}

int main(void)
{
	
}