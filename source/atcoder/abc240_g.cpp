#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
typedef long long ll;
using namespace std;
constexpr ll MOD = 998244353;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, x, y, z;
	cin >> n >> x >> y >> z;

	x = llabs(x); y = llabs(y); z = llabs(z);
	if (n % 2 != (x + y + z) % 2 || n < x + y + z)
	{
		cout << 0;
		return 0;
	}



	return 0;
}