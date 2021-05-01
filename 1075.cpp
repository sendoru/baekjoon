#include <iostream>

using namespace std;

int main(void)
{
	long long int N; int F, output;
	cin >> N;
	cin >> F;
	N = N - (N % 100);

	for (int i = 0; i < 100; i++)
	{
		if (N % F == 0)
		{
			output = i;
			break;
		}
		N += 1;
	}

	if (output < 10) cout << '0' << output << endl;
	else cout << output << endl;
	return 0;
	
}