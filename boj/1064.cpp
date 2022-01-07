#include <iostream>
#include <algorithm>

using namespace std;

long double distance(int dot1[], int dot2[])
{
	return pow((dot1[0] - dot2[0]) * (dot1[0] - dot2[0]) + (dot1[1] - dot2[1]) * (dot1[1] - dot2[1]), 0.5);
}

int main(void)
{
	int dots[3][2];
	cin >> dots[0][0] >> dots[0][1] >> dots[1][0] >> dots[1][1] >> dots[2][0] >> dots[2][1];

	if ((dots[1][0] - dots[0][0]) * (dots[2][1] - dots[0][1]) == (dots[2][0] - dots[0][0]) * (dots[1][1] - dots[0][1]))
	{
		cout << -1.0 << endl;
	}
	else
	{
		long double ans = 2 * (max(distance(dots[0], dots[1]), max(distance(dots[0], dots[2]), distance(dots[1], dots[2]))) - min(distance(dots[0], dots[1]), min(distance(dots[0], dots[2]), distance(dots[1], dots[2]))));
		printf("%.15f\n", ans);
	}

	return 0;
		
}