#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
	int n;
	string s;
	cin >> n >> s;
	vector<int> v(26);
	v[s[0] - 'a'] = 1;
	int l = 0, r = 0, ans = 1, cnt = 1;
	while (l != s.size() - 1 || r != s.size() - 1)
	{
		if (cnt <= n)
		{
			ans = max(ans, r - l + 1);
			if (r == s.size() - 1)
			{
				break;
			}
			r++;
			if (v[s[r] - 'a'] == 0)
			{
				cnt++;
			}
			v[s[r] - 'a']++;
		}
		else
		{
			if (v[s[l] - 'a'] == 1)
			{
				cnt--;
			}
			v[s[l] - 'a']--;
			l++;
		}
	}
	cout << ans << '\n';
	return 0;
}