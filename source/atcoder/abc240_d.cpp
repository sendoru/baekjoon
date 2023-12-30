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

	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& elem : a)
	{
		cin >> elem;
	}
	vector<pair<int, int>> mung;
	int cnt = 0;
	for (auto curBall : a)
	{
		if (!mung.empty() && mung.back().first == curBall)
		{
			mung.back().second++;
		}
		else
		{
			mung.push_back({ curBall, 1 });
		}
		cnt++;
		if (mung.back().second == mung.back().first)
		{
			cnt -= mung.back().second;
			mung.pop_back();
		}
		cout << cnt << '\n';
	}

	return 0;
}