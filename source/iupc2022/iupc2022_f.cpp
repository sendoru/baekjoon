#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
const int N = 20;
const ll INF = 1e9;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		vector<int> r1(4), r2(4), r3(4), r4(4);

		// 가까운 x, 가까운 y, 먼 x, 먼 y
		cin >> r1[0] >> r1[1] >> r1[2] >> r1[3];
		cin >> r2[0] >> r2[1] >> r2[2] >> r2[3];
		cin >> r3[0] >> r3[1] >> r3[2] >> r3[3];
		cin >> r4[0] >> r4[1] >> r4[2] >> r4[3];

		// compress r1
		r1[0] = max(r1[0], r4[0]);
		r1[1] = max(r1[1], r2[1]);
		r1[2] = min(r1[2], r4[2]);
		r1[3] = min(r1[3], r2[3]);

		// r2
		r2[0] = min(r2[0], r3[0]);
		r2[1] = max(r2[1], r1[1]);
		r2[2] = max(r2[2], r3[2]);
		r2[3] = min(r2[3], r1[3]);

		r3[0] = min(r3[0], r2[0]);
		r3[1] = min(r3[1], r4[1]);
		r3[2] = max(r3[2], r2[2]);
		r3[3] = max(r3[3], r4[3]);

		r4[0] = max(r4[0], r1[0]);
		r4[1] = min(r4[1], r3[1]);
		r4[2] = min(r4[2], r1[2]);
		r4[3] = max(r4[3], r3[3]);

		if (r1[0] > r1[2] || r1[1] > r1[3] ||
			r2[0] < r2[2] || r2[1] > r2[3] ||
			r3[0] < r3[2] || r3[1] < r3[3] ||
			r4[0] > r4[2] || r4[1] < r4[3])
		{
			cout << 0;
			continue;
		}

		int h1, h2, h3, w1, w2, w3;

		h1 = r1[3] - r1[1];
		h2 = r1[1] - r4[1];
		h3 = r4[1] - r4[3];

		w1 = r1[2] - r1[0];
		w2 = r1[0] - r2[0];
		w3 = r2[0] - r2[2];

		ll ans = 0;
		for (int i = max(1, max(w2, h2)); i <= min(w1 + w2 + w3, h1 + h2 + h3); i++)
		{
			ll wCnt = min(w1 + w2 + w3 + 1 - i, min(min(w1, w3) + 1, i - w2 + 1));
			ll hCnt = min(h1 + h2 + h3 + 1 - i, min(min(h1, h3) + 1, i - h2 + 1));
			ans += wCnt * hCnt;
		}

		cout << ans << '\n';
	}
	return 0;
}