#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		int n;
		cin >> n;
		vector<int> v(n);
		for (int& elem : v) cin >> elem;
		sort(v.begin(), v.end());
		int curMax = 1, ans = n;
		for (int i = 0; i < v.size(); i++)
		{
			if (curMax <= v[i]) curMax++;
			else ans--;
		}

		cout << "Case #" << t << ": ";
		cout << ans << '\n';
	}
	return 0;
}