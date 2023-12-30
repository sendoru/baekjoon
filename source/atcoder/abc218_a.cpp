#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	cout << (s[n - 1] == 'o' ? "Yes" : "No");
	return 0;
}