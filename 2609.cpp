#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	return gcd(b, a % b);
}

int main(void)
{
	int a, b;
	cin >> a >> b;
	int gcdofTwoNums = gcd(a, b);
	cout << gcdofTwoNums << endl;
	cout << a * b / gcdofTwoNums << endl;
	return 0;
	
}