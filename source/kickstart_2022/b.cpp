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
		string nStr;
		cin >> nStr;
		// O(nStr.length())
		int mod9 = 0;
		for (auto elem : nStr)
		{
			mod9 += elem - '0';
			mod9 %= 9;
		}
		mod9 = 9 - mod9;
		mod9 %= 9;

		cout << "Case #" << t << ": ";
		if (mod9 == 0)
		{
			cout << nStr[0];
			cout << '0';
			for (int i = 1; i < nStr.length(); i++)
			{
				cout << nStr[i];
			}
		}
		else
		{
			bool used = false;
			for (int i = 0; i < nStr.length(); i++)
			{
				if (!used && mod9 < nStr[i] - '0')
				{
					cout << mod9;
					used = true;
				}
				cout << nStr[i];
			}
			if (!used)
			{
				cout << mod9;
			}
		}
		cout << '\n';
	}

	return 0;
}