#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<int> s(2 * n);
	for (int i = 0; i < 2 * n; i++)
	{
		cin >> s[i];
	}
	sort(s.begin(), s.end());
	int ans = 0x3fffffff;
	for (int i = 0; i < n; i++)
	{
		ans = min(ans, s[i] + s[2 * n - 1 - i]);
	}
	cout << ans;
	return 0;
}