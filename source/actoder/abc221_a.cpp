#include <iostream>
using namespace std;
typedef long long ll;

int main(void)
{
	int a, b;
	cin >> a >> b;
	cout << (1ll << (5 * (a - b)));
	return 0;
}