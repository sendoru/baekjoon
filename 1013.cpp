#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int T;
	cin >> T;

	while (T--)
	{
		int state = 0;
		bool flag = true;
		string str;
		cin >> str;
		for (int i = 0; i < str.length(); i++)
		{
			if (state == -1)
			{
				flag = false;
				cout << "NO\n";
				break;
			}
			switch (state)
			{
				case 0:
					str[i] == '0' ? state = 1 : state = 2;
					break;
				case 1:
					str[i] == '0' ? state = -1 : state = 3;
					break;
				case 2:
					str[i] == '0' ? state = 4 : state = -1;
					break;
				case 3:
					str[i] == '0' ? state = 1 : state = 2;
					break;
				case 4:
					str[i] == '0' ? state = 5 : state = -1;
					break;
				case 5:
					str[i] == '0' ? state = 5 : state = 6;
					break;
				case 6:
					str[i] == '0' ? state = 1 : state = 7;
					break;
				case 7:
					str[i] == '0' ? state = 8 : state = 7;
					break;
				case 8:
					str[i] == '0' ? state = 5 : state = 3;
			}
		}

		if (flag)
		{
			if (state == 3 || state == 6 || state == 7)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}

	return 0;
}