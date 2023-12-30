#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		int aIndex = s.find('a'), sSize = s.size();
		// cout << aIndex << '\n';
		if (aIndex == -1)
		{
			cout << "NO" << '\n';
			continue;
		}
		int lIndex = aIndex, rIndex = aIndex;
		char curChar = 'b';
		while (lIndex != 0 || rIndex != sSize - 1)
		{
			if (lIndex > 0)
			{
				if (s[lIndex - 1] == curChar)
				{
					curChar++;
					lIndex--;
					continue;
				}
			}
			if (rIndex < sSize - 1)
			{
				if (s[rIndex + 1] == curChar)
				{
					curChar++;
					rIndex++;
					continue;
				}
			}
			break;
		}
		if (lIndex == 0 && rIndex == sSize - 1)
		{
			cout << "YES" << '\n';
		}
		else
		{
			cout << "NO" << '\n';
		}

	}
	return 0;
}