#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

ll sumof1(ll n)
{
	if (n <= 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}

	ll lg = (ll)log2l(n);

	ll lower = (1ll << lg) - 1;
	ll ret = 0;

	ret += (1ll << (lg - 1)) * lg;
	ret += n - lower;
	ret += sumof1(n - (1ll << lg));

	return ret;
}

int main(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	ll a, b;
	cin >> a >> b;

	cout << sumof1(b) - sumof1(a - 1) << '\n';
	return 0;
}