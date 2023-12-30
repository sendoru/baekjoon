#include <iostream>
#include <cmath>

using namespace std;

double dots[3][2];

int main(void)
{
	for (int i = 0; i < 3; i++)
	{
		cin >> dots[i][0] >> dots[i][1];
	}

	double initialDots[3][2] =
	{
		{dots[0][0], dots[0][1] },
		{dots[1][0], dots[1][1] },
		{dots[2][0], dots[2][1] },
	};
	

	// 점 0이 원점에 오도록 전부 평행이동
	for (int i = 0; i < 3; i++)
	{
		dots[i][0] -= initialDots[0][0];
		dots[i][1] -= initialDots[0][1];
	}

	// 점 0과 1을 이은 직선이 x축과 일치하도록 회전이동
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 2; j++)
			initialDots[i][j] = dots[i][j];

	double cosTheta = dots[1][0] / pow(dots[1][0] * dots[1][0] + dots[1][1] * dots[1][1], 0.5); // 0.6
	double sinTheta = dots[1][1] / pow(dots[1][0] * dots[1][0] + dots[1][1] * dots[1][1], 0.5); // 0.4

	for (int i = 1; i < 3; i++)
	{
		dots[i][0] = cosTheta * initialDots[i][0] + sinTheta * initialDots[i][1];
		dots[i][1] = (-sinTheta) * initialDots[i][0] + cosTheta * initialDots[i][1];
	}

	cout << dots[2][1] << endl;

	if (dots[2][1] > 0.000001)
		cout << 1 << endl;
	else if (dots[2][1] < -0.000001)
		cout << -1 << endl;
	else
		cout << 0 << endl;


}
