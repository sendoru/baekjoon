#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, n, k;
	cin >> m >> n >> k;
	vector<pair<int, int>> v(k);
	for (int i = 0; i < k; i++)
		cin >> v[i].first >> v[i].second;

	sort(v.begin(), v.end());
	for (int i = 0; i < k; i++)
		v[i].second *= -1;
	vector<int> ldsStack;
	for (int i = 0; i < k; i++)
	{
		auto iter = lower_bound(ldsStack.begin(), ldsStack.end(), v[i].second);
		if (iter == ldsStack.end()) ldsStack.push_back(v[i].second);
		else *iter = v[i].second;
	}

	cout << ldsStack.size();
	return 0;
}