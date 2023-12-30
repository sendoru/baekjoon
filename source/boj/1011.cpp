#include <iostream>

using namespace std;

long long int maxDistance[1 << 17];

int main(void)
{
	cin.tie(NULL);
	
	int N;
	cin >> N;

	for (long long int i = 0; i < (1 << 16); i++)
	{
		maxDistance[2 * i] = i * (i + 1);
		maxDistance[2 * i + 1] = (i + 1) * (i + 1);
	}

	long long int start, end, distance;
	for (int i = 0; i < N; i++)
	{
		cin >> start >> end;
		distance = end - start;
		for (int i = 0; i < (1 << 17); i++)
		{
			if (maxDistance[i] >= distance)
			{
				cout << i << '\n';
				break;
			}
		}
	}


	return 0;
}