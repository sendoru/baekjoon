#include <iostream>
using namespace std;

unsigned long long int A, B, C;

unsigned long long int check(unsigned long long int A, unsigned long long int B, unsigned long long int C)
{
	if (B == 0)
		return 1;
	if (B == 1)
		return A % C;
	if (B % 2 == 0)
	{
		unsigned long long refer = check(A, B / 2, C);
		return (refer % C) * (refer % C) % C;
	}
	else
	{
		unsigned long long refer = check(A, (B - 1) / 2, C);
		return (refer % C) * (refer * A % C) % C;
	}

}

int main(void)
{

	cin >> A >> B >> C;

	cout << check(A, B, C) << endl;

	return 0;
}