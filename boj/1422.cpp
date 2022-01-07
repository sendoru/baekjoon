#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;

bool comp(ll a, ll b)
{
	return to_string(a) + to_string(b) > to_string(b) + to_string(a);
}

int main(void)
{
	// int t;
	// cin >> t;
	// while (t--)
	{
		int k, n;
		cin >> k >> n;
		vector<ll> nums(k);
		for (int i = 0; i < k; i++)
		{
			cin >> nums[i];
		}
		sort(nums.begin(), nums.end(), greater<ll>());
		int greatest = nums[0];
		bool printedGreatest = false;
		sort(nums.begin(), nums.end(), comp);
		for (ll elem : nums)
		{
			if (elem == greatest && !printedGreatest)
			{
				for (int i = 0; i < n - k + 1; i++)
				{
					cout << elem;
				}
				printedGreatest = true;
			}
			else
			{
				cout << elem;
			}
		}
		cout << '\n';
	}
	return 0;
}