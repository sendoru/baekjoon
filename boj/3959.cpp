#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long double ld;
typedef long long ll;

const ld G = 9.81;
const ld PI = 3.1415926535;

ld calc2(ld a, ld b, ld c, ld x)
{
	return a * x * x + b * x + c;
}

ld solve2(ld a, ld b, ld c)
{
	ld d = b * b - 4 * a * c;
	if (d < 0)
	{
		return -1.0l;
	}
	else
	{
		if (a > 0)
		{
			return (-b + sqrt(d)) / (2 * a);
		}
		else
		{
			return (-b - sqrt(d)) / (2 * a);
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(10);

	int t;
	cin >> t;
	while (t--)
	{
		ld j, p, H, L,
			l, v, alpha,
			dy, vy, fPrime, hPrime, tanAlpha;
		int section = -1;
		cin >> j >> p >> H >> L;

		ld v0 = sqrt(2 * G * j);
		vector<ld> f = { -G / (2 * v0 * v0), 0, H + p };
		vector<ld> h0 = { (-2 * H) / (L * L), 0, H };					// 0 <= l < L / 2
		vector<ld> h1 = { (2 * H) / (L * L), (-4 * H) / L, 2 * H };		// L / 2 <= l < L
		vector<ld> h2 = { 0, 0, 0 };									// l >= L

		if ((l = solve2(f[0] - h0[0], f[1] - h0[1], f[2] - h0[2])) < L / 2 && l != -1)
		{
			section = 0;
			hPrime = calc2(0, 2 * h0[0], h0[1], l);
		}
		else if ((l = solve2(f[0] - h1[0], f[1] - h1[1], f[2] - h1[2])) < L && l != -1)
		{
			section = 1;
			hPrime = calc2(0, 2 * h1[0], h1[1], l);
		}
		else
		{
			l = solve2(f[0], f[1], f[2]);
			section = 2;
			hPrime = 0;
		}

		dy = H + p - calc2(f[0], f[1], f[2], l);
		v = sqrt(v0 * v0 + 2 * G * dy);

		fPrime = calc2(0, 2 * f[0], f[1], l);
		tanAlpha = fabsl((fPrime - hPrime) / (1 + fPrime * hPrime));
		alpha = 180 * atanl(tanAlpha) / PI;
		cout << l << ' ' << v << ' ' << alpha << '\n';
	}

	return 0;
}