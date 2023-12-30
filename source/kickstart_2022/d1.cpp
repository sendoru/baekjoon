#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		// 일단 nlogn이라도 짜자
		string aStr, bStr;
		cin >> aStr >> bStr;
		ll a = stoll(aStr), b = stoll(bStr);
		ll ans = 0;
		for (ll i = a; i <= b; i++)
		{
			ll digitProduct = 1;
			ll digitSum = 0;
			ll cur = i;
			while (cur != 0)
			{
				digitProduct *= cur % 10;
				digitSum += cur % 10;
				cur /= 10;
			}

			if (digitProduct % digitSum == 0)
			{
				ans++;
			}
		}

		cout << "Case #" << t << ": ";
		cout << ans;
		cout << '\n';
	}

	return 0;
}