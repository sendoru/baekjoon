#include <iostream>
using namespace std;
typedef unsigned long long ull;
int main(void)
{
	ull A = 0, B = 0, C = 0, D = 0, E = 0, F = 0, G = 0;
	cin >> A;
	B = A;
	B &= 7;
	A >>= 3;
	D = 4294967295ULL;
	C = D;
	C &= A;
	C ^= 4294967295ULL;




	cout << A;
	return 0;
}