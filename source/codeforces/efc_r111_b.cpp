#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		int n, a, b, ans;
		cin >> n >> a >> b;
		// b >= 0 : maximize op, ans = (a + b) * s.length()
		// b < 0 : minimize op, ans = a * s.length() + b * op.min
		string s;
		cin >> s;
		if (b >= 0)
		{
			ans = (a + b) * s.length();
		}
		else
		{
			int partitionCnt = 1;
			for (int i = 1; i < s.length(); i++)
			{
				if (s[i - 1] != s[i])
				{
					partitionCnt++;
				}
			}
			int opMin = partitionCnt / 2 + 1;
			ans = a * s.length() + b * opMin;
		}
		cout << ans << '\n';
	}
	return 0;
}