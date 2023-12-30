#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string nStr, kStr;
	cin >> nStr >> kStr;
	ll n = stoll(nStr), k = stoll(kStr);
	
	if (kStr.back() == '0')
	{
		cout << 0;
	}

	else
	{
		ll ans = 0;
		string kReverse;
		for (int i = kStr.length() - 1; i >= 0; i--)
		{
			kReverse.push_back(kStr[i]);
		}
		if (kReverse < kStr)
		{
			cout << 0;
		}
		else
		{
			bool isPal = kReverse == kStr;
			for (int i = 0; i + kStr.length() <= 14; i++)
			{
				string zeros(i, '0');
				if (stoll(kStr + zeros) <= n)
				{
					ans++;
				}
				if (!isPal && stoll(kReverse + zeros) <= n)
				{
					ans++;
				}
			}
			cout << ans;
		}
	}

	return 0;
}