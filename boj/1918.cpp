#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
	// int t;
	// cin >> t;
	// while (t--)
	{
		string input;
		cin >> input;
		// priority: (, ) > *, / > +, -
		vector<char> s;
		for (auto elem : input)
		{
			if (elem == '(')
			{
				s.push_back(elem);
			}
			else if (elem == ')')
			{
				while (s.back() != '(')
				{
					cout << s.back();
					s.pop_back();
				}
				s.pop_back();
			}
			else if (elem == '*' || elem == '/')
			{
				while (!s.empty() && s.back() != '(' && s.back() != '+' && s.back() != '-')
				{
					cout << s.back();
					s.pop_back();
				}
				s.push_back(elem);
			}
			else if (elem == '+' || elem == '-')
			{
				while (!s.empty() && s.back() != '(')
				{
					cout << s.back();
					s.pop_back();
				}
				s.push_back(elem);
			}
			else
			{
				s.push_back(elem);
			}
		}
		while (!s.empty())
		{
			cout << s.back();
			s.pop_back();
		}
		cout << '\n';
	}
	return 0;
}