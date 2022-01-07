#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;
typedef long double ld;
const ld pi = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679;

ld f(ld a, ld b, ld x)
{
	return a * expl(-x * x) + b * sqrtl(x);
}

ld s(ld a, ld b, ld x)
{
	return pi * f(a, b, x) * f(a, b, x);
}

ld vol(ld a, ld b, ld h)
{
	ld ret = 0;
	for (int i = 0; i < 1000000; i++)
	{
		ret += s(a, b, ((ld)i + 0.5l) * h / 1000000.l) * h / 1000000.l;
	}
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ld v; int n;
	cin >> v >> n;
	vector<ld> pots(n);
	ld a, b, h; int index = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b >> h;
		pots[i] = fabsl(v - vol(a, b, h));
		if (pots[i] < pots[index])
		{
			index = i;
		}
	}

	cout << index << '\n';
	return 0;
}