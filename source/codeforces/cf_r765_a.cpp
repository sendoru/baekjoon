#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
typedef long long ll;
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		int n, l;
		cin >> n >> l;
		vector<int> nums(n);
		vector<int> bitCnt(31);
		for (int i = 0; i < n; i++)
		{
			cin >> nums[i];
			for (int j = 0; j < 31; j++)
			{
				if (nums[i] & (1 << j))
				{
					bitCnt[j]++;
				}
			}
		}

		int ans = 0;
		for (int i = 0; i < 31; i++)
		{
			if (bitCnt[i] > n / 2)
			{
				ans += (1 << i);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}