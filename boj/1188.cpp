#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main(void)
{
	int N, M;
	cin >> N >> M;
	cout << M - gcd(M, N) << endl;

	return 0;
}