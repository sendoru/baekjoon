#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 0x3fffffff

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> pos, neg, zeros;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		if (temp > 0) pos.push_back(temp);
		else if (temp == 0) zeros.push_back(temp);
		else neg.push_back(temp);
	}

	int ans = -INF;
	sort(pos.begin(), pos.end(), greater<int>());
	sort(neg.begin(), neg.end());

	if (pos.size() >= 3)
		ans = max(ans, pos[0] * pos[1] * pos[2]);

	if (pos.size() >= 1 && neg.size() >= 2)
		ans = max(ans, pos[0] * neg[0] * neg[1]);

	if (pos.size() >= 2)
		ans = max(ans, pos[0] * pos[1]);

	if (neg.size() >= 2)
		ans = max(ans, neg[0] * neg[1]);

	if (zeros.size() >= 1)
		ans = max(ans, 0);

	if (pos.size() >= 1 && neg.size() >= 1)
		ans = max(ans, pos[0] * neg[0]);

	cout << ans;
	return 0;
}