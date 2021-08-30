#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(void)
{
	// int t;
	// cin >> t;
	// while (t--)
	{
		int n;
		cin >> n;
		vector<string> nums(n);
		for (int i = 0; i < n; i++)
		{
			cin >> nums[i];
		}
		sort(nums.begin(), nums.end(),
			[](string a, string b)->bool {return (a + b < b + a); });

		string ans = "9";
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = 0; j < nums[i].size(); j++)
			{
				ans += "9";
			}
		}
		string inf = ans;

		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i][0] == '0')
			{
				continue;
			}
			string cur = nums[i];
			for (int j = 0; j < nums.size(); j++)
			{
				if (i != j)
				{
					cur += nums[j];
				}
			}
			if (cur < ans)
			{
				ans = cur;
			}
		}
		if (ans == inf)
		{
			cout << "INVALID" << '\n';
		}
		else
		{
			cout << ans << '\n';
		}
	}
	return 0;
}