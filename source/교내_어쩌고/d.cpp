#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#define DEBUG
#undef DEBUG

using namespace std;
typedef long long ll;
typedef long double ld;

ll cntFromPSum(vector<ll>& v, int s, int e)
{
	if (s == 0) return v[e];
	return v[e] - v[s - 1];
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;

#ifdef DEBUG
	cout << "Enter the coutnt of test cases: ";
	cin >> t;
#endif // DEBUG

#ifndef DEBUG
	t = 1;
#endif // !DEBUG

	while (t--)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;

		vector<ll> t(n), g(n), f(n), p(n);
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == 'T')
				t[i] = 1;
			else if (s[i] == 'G')
				g[i] = 1;
			else if (s[i] == 'F')
				f[i] = 1;
			else if (s[i] == 'P')
				p[i] = 1;
		}

		vector<ll> tSum(n), gSum(n), fSum(n), pSum(n);
		ll ans = 0;
		vector<ll> cntFromZero = { 0, 0, 0 };
		tSum[0] = t[0];
		gSum[0] = g[0];
		fSum[0] = f[0];
		pSum[0] = p[0];

		vector<vector<vector<vector<ll>>>> cnts(3, vector<vector<vector<ll>>>(3, vector<vector<ll>>(3, vector<ll>(3))));

		for (int i = 1; i < n; i++)
		{
			tSum[i] = tSum[i - 1] + t[i];
			gSum[i] = gSum[i - 1] + g[i];
			fSum[i] = fSum[i - 1] + f[i];
			pSum[i] = pSum[i - 1] + p[i];
		}

		// i - 2 ~ i번째 문자가 같은 문자라고 해보자.
		// 
		for (int i = 0; i < n; i++)
		{
			if (tSum[i] % 3 == 0 && gSum[i] % 3 == 0 && fSum[i] % 3 == 0 && pSum[i] % 3 == 0)
			{
				ans++;
			}
			ans += cnts[tSum[i] % 3][gSum[i] % 3][fSum[i] % 3][pSum[i] % 3];
			cnts[tSum[i] % 3][gSum[i] % 3][fSum[i] % 3][pSum[i] % 3]++;
		}

		cout << ans << '\n';

	#ifdef DEBUG
		ll naiveAns = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = i; j < n; j++)
			{
				if (cntFromPSum(tSum, i, j) % 3 == 0 && cntFromPSum(gSum, i, j) % 3 == 0 && cntFromPSum(fSum, i, j) % 3 == 0 && cntFromPSum(pSum, i, j) % 3 == 0)
				{
					naiveAns++;
				}
			}
		}

		cout << naiveAns << '\n';
	#endif
	}

	return 0;
}