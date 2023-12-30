#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(void)
{
	int a, b, c;
	cin >> a >> b >> c;
	int d = b / c;
	int ans = d * c;
	cout << (ans < a ? -1 : ans);
	return 0;
}