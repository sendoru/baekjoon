#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	cin.tie(NULL);

	long long int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		long long int m, n;
		cin >> m >> n;
		long double temp = (m - 1) * m * (m + 1) / 3;

		long double result = round(10 * (n / 2.0 + temp / (m * m))) / 10.0;

		printf("%.1f\n", result);
	}

	return 0;
}