#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int n, m, nearestDist = 1 << 24, ans = 0;
	bool flag = false;
	cin >> n >> m;
	vector<int> a(n);
	vector<bool> aHasI(2, false);
	vector<int> b;
	vector<int> t(m);
	vector<bool> tHasI(2, false);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		aHasI[a[i]] = true;
		if (i >= 1 && a[i] != a[0])
		{
			nearestDist = min(nearestDist, min(i - 0, n - i));
		}
	}
	for (int i = 0; i < m; i++)
	{
		cin >> t[i];
		tHasI[t[i]] = true;
	}
	if ((!aHasI[0] && tHasI[0]) || (!aHasI[1] && tHasI[1]))
	{
		cout << -1;
		return 0;
	}
	if (a[0] != t[0])
	{
		ans += nearestDist;
		flag = true;
	}
	for (int i = 1; i < m; i++)
	{
		if (t[i] != t[i - 1])
		{
			if (!flag)
			{
				ans += nearestDist;
				flag = true;
			}
			else
			{
				ans++;
			}
		}
	}
	ans += m;
	cout << ans;
	return 0;
}