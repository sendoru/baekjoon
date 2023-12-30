#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	int dots[10000][2];
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> dots[i][0] >> dots[i][1];
	}

	long long area = 0.0;
	int xBegin = dots[0][0];
	int yBegin = dots[0][1];

	for (int i = 1; i < N; i++)
	{
		long long outerProduct = (dots[i - 1][0] - xBegin) * (dots[i][1] - yBegin) - (dots[i - 1][1] - yBegin) * (dots[i][0] - xBegin);
		area += outerProduct * 5;
	}

	cout << std::abs(area) / 10 << '.' << std::abs(area) % 10 << endl;
	return 0;
}