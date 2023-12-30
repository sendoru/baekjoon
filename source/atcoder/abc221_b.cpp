#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string s, t;
	cin >> s >> t;
	if (s == t)
	{
		cout << "Yes";
		return 0;
	}
	for (int i = 1; i < s.size(); i++)
	{
		swap(s[i - 1], s[i]);
		if (s == t)
		{
			cout << "Yes";
			return 0;
		}
		swap(s[i - 1], s[i]);
	}
	cout << "No";
	return 0;
}