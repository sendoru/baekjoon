#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s)
{
	for (int i = 0; i < s.length() / 2; i++)
	{
		if (s[i] != s[s.length() - i - 1])
			return false;
	}

	return true;
}

int main(void)
{
	string input = "a";
	while (true)
	{
		cin >> input;
		if (input == "0") break;
		isPalindrome(input) ? cout << "yes" << endl : cout << "no" << endl;
	}

	return 0;
}