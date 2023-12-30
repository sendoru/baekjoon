#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

int main(void)
{
	vector<int> p(26);
	for (int i = 0; i < 26; i++)
	{
		cin >> p[i];
		cout << (char)('a' + p[i] - 1);
	}
	return 0;
}