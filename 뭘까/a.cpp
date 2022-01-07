#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int main(void)
{
	ll n;

	string fullStr;
	for (char i = 'a'; i <= 'z'; i++)
	{
		fullStr += i;
	}
	for (char i = 'a'; i <= 'z'; i++)
	{
		for (char j = 'a'; j <= 'z'; j++)
		{
			fullStr += i;
			fullStr += j;
		}
	}

	for (char i = 'a'; i <= 'z'; i++)
	{
		for (char j = 'a'; j <= 'z'; j++)
		{
			for (char k = 'a'; k <= 'z'; k++)
			{
				fullStr += i;
				fullStr += j;
				fullStr += k;
			}
		}
	}

	for (n = 0; n < fullStr.length(); n++)
	{
		ll nn = n;
		ll cnt = 26, len = 1;
		while (n >= cnt * len)
		{
			n -= cnt * len;
			cnt *= 26;
			len += 1;
		}

		string curStr = "";
		for (int i = 0; i < len; i++)
		{
			curStr += 'a';
		}
		int idx = 0;
		while (cnt >= 26)
		{
			while (n >= (cnt / 26) * len)
			{
				n -= (cnt / 26) * len;
				curStr[idx]++;
			}
			cnt /= 26;
			idx++;
		}
		if (fullStr[nn] != curStr[n])
		{
			cout << "ERROR: n = " << nn;
			return 0;
		}
		n = nn;
	}
	return 0;
}