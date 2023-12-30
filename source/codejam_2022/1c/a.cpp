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

int main(void)
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		bool possible = true;
		int n;
		cin >> n;
		vector<string> s(n);
		for (auto& elem : s)
		{
			cin >> elem;
		}

		cout << "Case #" << t << ": ";

		vector<string> compressedS(n);

		for (int i = 0; i < n; i++)
		{
			compressedS[i] = compress(s[i]);
			// 중복 문자가 있는지 확인
			for (int j = 0; j < compressedS[i].length(); j++)
			{
				for (int k = j + 1; k < compressedS[i].length(); k++)
				{
					if (compressedS[i][j] == compressedS[i][k])
					{
						possible = false;
						break;
					}
					if (!possible)
					{
						break;
					}
				}
			}
		}

		if (!possible)
		{
			cout << "IMPOSSIBLE\n";
			continue;
		}

		vector<pair<string, string>> pairS(n);
		for (int i = 0; i < n; i++)
		{
			pairS[i].first = compressedS[i];
			pairS[i].second = s[i];
		}

		sort(pairS.begin(), pairS.end());
		for (int i = 0; i < n; i++)
		{
			compressedS[i] = pairS[i].first;
			s[i] = pairS[i].second;
		}

		for (int i = 0; i < n - 1; i++)
		{
			if (compressedS[i].length() == 1 && compressedS[i][0] == compressedS[i + 1][0])
			{
				s[i] += s[i + 1];
				compressedS[i] = compressedS[i + 1];
				s.erase(s.begin() + i + 1);
				compressedS.erase(compressedS.begin() + i + 1);
				i--;
				n--;
			}
		}
		vector<int> pre(n, -1), nxt(n, -1);

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j) continue;
				// s[j]가 s[i] 뒤에 오냐?
				if (compressedS[i].back() == compressedS[j][0])
				{
					if (nxt[i] != -1 || pre[j] != -1)
					{
						possible = false;
						break;
					}
					nxt[i] = j;
					pre[j] = i;
				}
			}
			if (!possible)
			{
				break;
			}
		}

		if (!possible)
		{
			cout << "IMPOSSIBLE\n";
			continue;
		}
		// answer

		vector<bool> visited(n);
		vector<int> order;

		for (int i = 0; i < n; i++)
		{
			if (pre[i] == -1)
			{
				int cur = i;
				while (cur != -1)
				{
					order.push_back(cur);
					if (visited[cur])
					{
						possible = false;
						break;
					}
					visited[cur] = true;
					cur = nxt[cur];
				}
			}
			if (!possible) break;
		}

		if (!possible || order.size() != s.size())
		{
			cout << "IMPOSSIBLE\n";
			continue;
		}
		string ans;
		for (auto elem : order)
		{
			ans += s[elem];
		}

		vector<bool> used(26);
		used[ans[0] - 'A'] = true;
		for (int i = 1; i < ans.length(); i++)
		{
			if (used[ans[i] - 'A'] && ans[i] != ans[i - 1])
			{
				possible = false;
				break;
			}
			used[ans[i] - 'A'] = true;
		}

		if (!possible)
		{
			cout << "IMPOSSIBLE\n";
		}
		else
		{
			cout << ans << '\n';
		}
	}
}