#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
	string s, exp, st;
	cin >> s >> exp;
	for (int i = 0; i < s.length(); i++)
	{
		st.push_back(s[i]);

		if (st.substr(st.length() - exp.length(), exp.length()) == exp)
		{
			for (int j = 0; j < exp.length(); j++)
			{
				st.pop_back();
			}
		}

	}

	cout << (st.empty() ? "FRULA" : st);
	return 0;
}