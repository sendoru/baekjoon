#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		vector<int> cnt(3);
		for (int i = 0; i < s.length(); i++)
			cnt[s[i] - 'A']++;
		cout << (cnt[1] == cnt[0] + cnt[2] ? "YES" : "NO") << '\n';
	}
	return 0;
}