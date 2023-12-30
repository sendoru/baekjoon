#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		bool possible = false;

		// 길이 5 이상인 팰린드롬이 있다 = 길이 5 또는 6인 팰린드롬이 있다와 동치
		// 길이 n (n >= 3)인 팰린드롬이 있으면 그 팰린드롬의 부분문자열인 길이 n-2짜리 팰린드롬도 존재하기 때문
		// 섭테나 긁자...
		if (n < 5)
		{
			possible = true;
		}
		else
		{
			for (int i = 0; i < (1 << n); i++)
			{
				bool curPossible = true;
				for (int j = 0; j < n; j++)
				{
					if (s[j] != '?' && (i >> j) % 2 + '0' != s[j])
					{
						curPossible = false;
						break;
					}
				}
				if (!curPossible)
				{
					continue;
				}
				// 길이 5인 팰린드롬 확인
				for (int j = 0; j < n - 4; j++)
				{
					if ((i >> j) % 2 == (i >> (j + 4)) % 2 && (i >> (j + 1)) % 2 == (i >> (j + 3)) % 2)
					{
						curPossible = false;
						break;
					}
				}
				if (!curPossible)
				{
					continue;
				}
				// 길이 6인 팰린드롬 확인
				for (int j = 0; j < n - 5; j++)
				{
					if ((i >> j) % 2 == (i >> (j + 5)) % 2 && (i >> (j + 1)) % 2 == (i >> (j + 4)) % 2 && (i >> (j + 2)) % 2 == (i >> (j + 3)) % 2)
					{
						curPossible = false;
						break;
					}
				}
				if (curPossible)
				{
					possible = true;
					break;
				}
			}
		}
		cout << "Case #" << t << ": ";
		cout << (possible ? "POSSIBLE" : "IMPOSSIBLE");
		cout << '\n';
	}

	return 0;
}