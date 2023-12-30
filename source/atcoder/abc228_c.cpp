#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_SCORE 300
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	vector<int> p(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int temp;
			cin >> temp;
			p[i] += temp;
		}
	}

	vector<int> sorted = p;
	sort(sorted.begin(), sorted.end(), greater<int>());
	for (int i = 0; i < n; i++)
	{
		int stand = lower_bound(sorted.begin(), sorted.end(), p[i] + MAX_SCORE, greater<int>()) - sorted.begin();
		cout << ((stand < k) ? "YES" : "NO") << '\n';
	}
	return 0;
}