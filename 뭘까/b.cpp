#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;

void putPermutation(unordered_set<string>& s, string curStr, int strLen)
{
	if (curStr.length() == strLen)
	{
		s.insert(curStr);
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
	int n, m;
	cin >> n >> m;
	unordered_set<string> nums = {};
	putPermutation(nums, "", n);
	for (int i = 0; i < m; i++)
	{
		string q1;
		int strike, ball;
		cin >> q1 >> strike >> ball;
		auto iter = nums.begin();
		while (iter != nums.end())
		{
			string curStr = *iter;
			int curStrike = 0, curBall = 0;
			for (int i = 0; i < curStr.length(); i++)
			{
				if (q1[i] == curStr[i])
				{
					curStrike++;
				}
				else if (curStr.find(q1[i]) != -1)
				{
					curBall++;
				}
			}
			if (curStrike == strike && curBall == ball)
			{
				iter++;
			}
			else
			{
				iter = nums.erase(iter);
			}
		}
	}

	if (nums.size() == 1)
	{
		cout << *nums.begin();
	}
	else
	{
		cout << nums.size();
	}

	return 0;
}