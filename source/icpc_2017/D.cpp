#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
using namespace std;
typedef long long ll;
constexpr ll INF = 2e9;
constexpr ll MOD = 1e9 + 7;

ll f(ll n)
{
	ll ret = 0;
	while (n != 0)
	{
		ret += (n % 10) * (n % 10);
		n /= 10;
	}
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	set<ll> s;
	ll n;
	cin >> n;
	ll initN = n;
	while (n != 1)
	{
		s.insert(n);
		n = f(n);
		if (s.find(n) != s.end())
		{
			cout << "UNHAPPY";
			break;
		}
	}

	if (n == 1)
	{
		cout << "HAPPY";
	}

	return 0;
}