#include <iostream>
#define MAX 191230
typedef long long ll;
using namespace std;

ll fib[MAX];

int main(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	fib[0] = 0;
	fib[1] = 1;
	fib[2] = 2;
	for (int i = 3; i < MAX; i++)
	{
		fib[i] = (fib[i - 1] + fib[i - 2]) % (1000000007);
	}

	int T;
	cin >> T;

	while (T--)
	{
		int N;
		cin >> N;
		cout << fib[N] << '\n';
	}

	return 0;

}