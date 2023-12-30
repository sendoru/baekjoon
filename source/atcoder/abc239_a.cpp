#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
typedef long long ll;
using namespace std;

int main(void)
{
	cout.precision(15);
	ll h;
	cin >> h;
	cout << sqrtl(h * (12800000 + h));
	return 0;
}