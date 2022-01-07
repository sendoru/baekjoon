#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> f(n);
		for (int i = 0; i < n; i++)
		{
			cin >> f[i];
		}

		ll a1, a2, a3;

	case1:	// d == 1
		if (f[1] % f[0] != 0) goto case2;
		a1 = f[1] / f[0];
		for (int i = 2; i < f.size(); i++)
		{
			if (f[i] != f[i - 1] * a1)
			{
				goto case2;
			}
		}

		cout << f[f.size() - 1] * a1 << '\n';
		continue;

	case2: // d == 2
		if ((f[1] * f[1] - f[0] * f[2]) == 0 || (f[1] * f[3] - f[2] * f[2]) % (f[1] * f[1] - f[0] * f[2]) != 0) goto case3;
		a2 = (f[1] * f[3] - f[2] * f[2]) / (f[1] * f[1] - f[0] * f[2]);
		if ((f[2] - a2 * f[0]) % f[1] != 0) goto case3;
		a1 = (f[2] - a2 * f[0]) / f[1];
		for (int i = 4; i < f.size(); i++)
		{
			if (f[i] != f[i - 1] * a1 + f[i - 2] * a2)
			{
				goto case3;
			}
		}

		cout << f[f.size() - 1] * a1 + f[f.size() - 2] * a2 << '\n';
		continue;

	case3: // d == 3
		ll  c11 = f[2] * f[2] - f[1] * f[3],
			c12 = f[1] * f[2] - f[0] * f[3],
			c21 = f[3] * f[2] - f[1] * f[4],
			c22 = f[2] * f[2] - f[0] * f[4];

		ll  y1 = f[4] * f[2] - f[3] * f[3],
			y2 = f[5] * f[2] - f[3] * f[4];

		ll detC = c11 * c22 - c12 * c21;
		ll detC1 = y1 * c22 - c12 * y2;
		ll detC2 = c11 * y2 - y1 * c21;

		a2 = detC1 / detC;
		a3 = detC2 / detC;
		a1 = (f[3] - f[1] * a2 - f[0] * a3) / f[2];

		cout << f[f.size() - 1] * a1 + f[f.size() - 2] * a2 + f[f.size() - 3] * a3 << '\n';
	}

	return 0;
}