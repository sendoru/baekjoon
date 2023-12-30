#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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
		string i, p;
		cin >> i >> p;
		// LCS 길이가 i의 길이랑 같은지 보면된다?
		// 그냥 투포인터 쓰는건가
		/*
		2
		Ilovecoding
		IIllovecoding
		KickstartIsFun
		kkickstartiisfun
		*/
		int iPtr = 0, pPtr = 0;
		bool possible = true;
		while (iPtr != i.length() || pPtr != p.length())
		{
			if (iPtr == i.length())
			{
				break;
			}
			if (pPtr == p.length())
			{
				possible = false;
				break;
			}
			if (i[iPtr] == p[pPtr])
			{
				iPtr++;
				pPtr++;
			}
			else
			{
				pPtr++;
			}
		}
		cout << "Case #" << t << ": ";
		if (!possible)
		{
			cout << "IMPOSSIBLE";
		}
		else
		{
			cout << p.length() - i.length();
		}
		cout << '\n';
	}

	return 0;
}