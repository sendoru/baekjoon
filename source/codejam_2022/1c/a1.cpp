#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <deque>
#include <algorithm>
using namespace std;
typedef long long ll;

string compress(string s)
{
	if (s.length() == 0) return s;
	string ret;
	ret.push_back(s[0]);
	for (int i = 1; i < s.length(); i++)
	{
		if (ret.back() != s[i])
		{
			ret.push_back(s[i]);
		}
	}

	return ret;
}

void func(int n, vector<vector<int>>& allPer, vector<int>& picked, int toPick)
{
	// 더 고를 게 없으면 고른거 전부 뱉어내기
	if (toPick == 0)
	{
		allPer.push_back(picked);
		return;
	}

	for (int next = 0; next < n; next++)
	{
		if (find(picked.begin(), picked.end(), next) == picked.end())
		{
			picked.push_back(next);
			func(n, allPer, picked, toPick - 1);
			picked.pop_back();
		}
	}
}

vector<vector<int>> getAllPer(int n)
{
	vector<int> temp;
	vector<vector<int>> ret;
	func(n, ret, temp, n);
	return ret;
}

int main(void)
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		bool possible = false;
		int n;
		cin >> n;
		vector<string> s(n);
		for (auto& elem : s)
		{
			cin >> elem;
		}

		cout << "Case #" << t << ": ";
		auto allPer = getAllPer(n);
		
		for (auto& per : allPer)
		{
			bool correct = true;
			vector<bool> used(26);
			string ans;
			for (int order : per)
			{
				ans += s[order];
			}
			used[ans[0] - 'A'] = true;
			for (int i = 1; i < ans.length(); i++)
			{
				if (used[ans[i] - 'A'] == true && ans[i] != ans[i - 1])
				{
					correct = false;
					break;
				}
				used[ans[i] - 'A'] = true;
			}
			if (correct)
			{
				possible = true;
				cout << ans;
				break;
			}
		}
		if (!possible)
		{
			cout << "IMPOSSIBLE";
		}
		cout << '\n';
	}
}