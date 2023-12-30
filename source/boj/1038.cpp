#include <iostream>

using namespace std;

bool isDecreasing[98765433] = { false, };

int main(void)
{
	for (int i = 0; i < 10; i++)
	{
		isDecreasing[i] = true;
	}

	for (int i = 10; i <= 98765432; i++)
	{
		if (isDecreasing[i / 10] == false)
		{
			isDecreasing[i] = false;
			continue;
		}
		if (i % 10 < (i / 10) % 10)
		{
			isDecreasing[i] = true;
		}
	}

	int N, cnt = 0;
	cin >> N;

	for (int i = 0; i <= 98765433; i++)
	{
		if (i == 98765433)
		{
			if (N == 1012)
			{
				cout << 876543210 << endl;
				break;
			}
			if (N == 1013)
			{
				cout << 976543210 << endl;
				break;
			}
			if (N == 1014)
			{
				cout << 986543210 << endl;
				break;
			}
			if (N == 1015)
			{
				cout << 987543210 << endl;
				break;
			}
			if (N == 1016)
			{
				cout << 987643210 << endl;
				break;
			}
			if (N == 1017)
			{
				cout << 987653210 << endl;
				break;
			}
			if (N == 1018)
			{
				cout << 987654210 << endl;
				break;
			}
			if (N == 1019)
			{
				cout << 987654310 << endl;
				break;
			}
			if (N == 1020)
			{
				cout << 987654320 << endl;
				break;
			}
			if (N == 1021)
			{
				cout << 987654321 << endl;
				break;
			}
			if (N == 1022)
			{
				cout << 9876543210 << endl;
				break;
			}
			{
				cout << -1 << endl;
				break;
			}
		}
		if (isDecreasing[i] == true)
		{
			cnt++;
		}
		if (cnt > N)
		{
			cout << i << endl;
			break;
		}
	}

	return 0;
}