#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string s;
	int ans = 0;
	while (true)
	{
		cin >> s;
		if (cin.eof()) break;
		ans++;
	}
	cout << ans;
	return 0;
}