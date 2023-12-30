#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
typedef long long ll;

using namespace std;

int main(void)
{
	string s, ss;
	cin >> s;
	cout << stoi(ss + s[0] + s[1] + s[2]) + stoi(ss + s[1] + s[2] + s[0]) + stoi(ss + s[2] + s[0] + s[1]);
	return 0;
}