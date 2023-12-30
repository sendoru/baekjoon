#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
typedef long long ll;
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;
		vector<int> vec(n);
		for (int i = 0; i < n; i++)
		{
			cin >> vec[i];
		}
		vector<int> pos(150001, -1);
		int ans = -1;
		for (int i = 0; i < n; i++)
		{
			if (pos[vec[i]] == -1)
			{
				pos[vec[i]] = i;
			}
			else
			{
				int lLen = i, rLen = n - i - 1;
				lLen = min(lLen, pos[vec[i]]);
				rLen = min(rLen, n - pos[vec[i]] - 1);
				ans = max(ans, lLen + rLen + 1);
				pos[vec[i]] = i;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}