#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
	string s1, s2, s3, t;
	cin >> s1 >> s2 >> s3 >> t;
	for (char elem : t)
	{
		if (elem - '0' == 1)
			cout << s1;
		else if (elem - '0' == 2)
			cout << s2;
		else
			cout << s3;
	}

	return 0;
}