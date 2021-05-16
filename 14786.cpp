#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long double ld;

ld a, b, c;

ld f(ld x)
{
	return a * x + b * sin(x) - c;
}

ld fPrime(ld x)
{
	return a + b * cos(x);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(30);

	cin >> a >> b >> c;

	// f(x) = ax + bsin(x) - c
	// f'(x) = a + bcos(X)
	// x_n = x_(n - 1) - f(x_(n - 1)) / f'(x_(n - 1))

	vector<ld> x;
	x.push_back(c / a);
	for (int i = 0; i < 200; i++)
	{
		x.push_back(x[i] - f(x[i]) / fPrime(x[i]));
	}

	cout << x.back() << '\n';
	return 0;
}