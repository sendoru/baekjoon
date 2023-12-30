#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		ll n2, n3, n4;
		cin >> n2 >> n3 >> n4;
		ll ans = 0;
		/*
		* 10 = 2 + 2 + 2 + 2 + 2
		*    = 2 + 2 + 2 + 4
		*    = 2 + 2 + 3 + 3 = 2 + 2 + 6
		*    = 2 + 4 + 4
		*    = 3 + 3 + 4 = 4 + 6
		*/

		// 길이 3짜리 2개를 합쳐서 길이 6짜리로 만듦
		n3 /= 2;

		// 4 + 6인 경우 먼저 처리
		ans += min(n3, n4);
		n3 -= ans;
		n4 -= ans;

		// 4짜리가 하나도 안남은경우, 2짜리 5개 또는 2 + 2 + 6만 가능
		if (n4 == 0)
		{
			ll addi = min(n2 / 2, n3);
			ans += addi;
			n2 -= addi * 2ll;
			n3 -= addi;
			// 2 + 2 + 6을 전부 만들고 2짜리가 남은경우 2짜리 5개를 합함
			// 6짜리가 남았으면 아무것도못함
			if (n2 != 0)
			{
				ans += n2 / 5;
			}
		}

		// 6짜리가 하나도 안남은경우, 2짜리 5개, 2 + 2 + 2 + 4, 2 + 4 + 4가 가능
		// 뒤쪽부터 처리
		else
		{
			ll addi = min(n2, n4 / 2);
			ans += addi;
			n2 -= addi;
			n4 -= addi * 2;
			// n4가 안남았으면 2 * 5만 가능
			if (n4 == 0)
			{
				ans += n2 / 5;
			}
			// n4가 1개 남았으면 
			else if (n4 == 1)
			{
				if (n2 >= 3)
				{
					n2 -= 3;
					n4 = 0;
					ans++;
				}
				ans += n2 / 5;
			}
			// n4가 2개 이상 남은 경우는 더 이상 못만듦
		}

		cout << ans << '\n';
	}

	return 0;
}