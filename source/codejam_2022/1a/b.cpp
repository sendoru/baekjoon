#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(void)
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		vector<ll> ans, ansRev;
		int n;
		cin >> n;
		ll aSum = 0;
		for (int i = 0; i <= 29; i++)
		{
			cout << (1ll << i) << ' ';
			aSum += (1ll << i);
		}

		for (int i = 1; i <= 35; i++)
		{
			if (i != 1 && i != 3)
			{
				cout << (ll)(1e8 + i) << ' ';
				cout << (ll)(1e8 - i) << ' ';
				aSum += 2e8;
			}


			if (i == 1 || i == 3)
			{
				cout << (ll)(5e7 + i) << ' ';
				cout << (ll)(5e7 - i) << ' ';
				ans.push_back((ll)(5e7 + i));
				ansRev.push_back((ll)(5e7 - i));
				aSum += 1e8;
			}
			else if (i % 2 == 1)
			{
				ans.push_back((ll)(1e8 + i));
				ans.push_back((ll)(1e8 - i));
			}
			else
			{
				ansRev.push_back((ll)(1e8 + i));
				ansRev.push_back((ll)(1e8 - i));
			}
		}

		// cout << (ll)(2e8);
		// aSum += 2e8;
		cout << endl;

		vector<ll> b(n);
		ll bSum = 0;
		for (auto& elem : b)
		{
			cin >> elem;
			bSum += elem;
		}
		ll origBSum = bSum;
		ll ansSum = 0;
		sort(b.begin(), b.end(), greater<ll>());
		int toPut = 0;
		while ((bSum - ansSum + (1ll << 30) - 1) / 2 >= (1ll << 30))
		{
			ans.push_back(b.back());
			ansSum += b.back();
			bSum -= b.back();
			b.pop_back();
			toPut = (toPut + 1) % 2;
		}

		ll target = (bSum - ansSum + (1ll << 30) - 1) / 2;
		if (target < 0)
		{
			swap(ans, ansRev);
			target *= -1;
		}

		// 남은 b는 전부 ansRev에 넣는다고 하자
		vector<ll> unused;
		for (int i = 0; i <= 29; i++)
		{
			if ((target >> i) & 1)
			{
				ans.push_back(1ll << (i));
			}
		}

		ansSum = 0;
		for (auto elem : ans)
		{
			cout << elem << ' ';
			ansSum += elem;
		}
		cout << endl;

		cout << "원래 합: " << aSum + origBSum << '\n';
		cout << "원래 합의 절반: " << (aSum + origBSum) / 2 << '\n';
		cout << "출력의 합: " << ansSum << endl;
	}
}