#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
typedef long long ll;
using namespace std;

int main(void)
{
	int a, b;
	cin >> a >> b;
	cout << (b - a == 1 || b - a == 9 ? "Yes" : "No");
	return 0;
}