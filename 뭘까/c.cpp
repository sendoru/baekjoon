#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;

void putPermutation(set<ll>& s, string curStr, int strLen)
{
	if (curStr.length() == strLen)
	{
		s.insert(stoll(curStr));
		return;
	}
	for (char i = '1'; i <= '9'; i++)
	{
		if (curStr.find(i) == -1)
		{
			putPermutation(s, curStr + i, strLen);
		}
	}
}

int main(void)
{
	ll n;
	cin >> n;
	set<ll> nums;
	putPermutation(nums, "", 9);
	auto iter = nums.lower_bound(n);
	if (iter == nums.begin())
	{
		cout << -1;
	}
	else
	{
		cout << *(--iter);
	}

	return 0;
}