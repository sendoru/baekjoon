#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
typedef long double ld;

int squaredDist(pair<int, int> a, pair<int, int> b)
{
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main(void)
{
	int n;
	cin >> n;
	vector<pair<int, int>> dots(n);
	for (int i = 0; i < n; i++)
	{
		cin >> dots[i].first >> dots[i].second;
	}
	sort(dots.begin(), dots.end());
	auto cmp = [](pair<int, int> a, pair<int, int> b) {return a.second == b.second ? a.first < b.first : a.second < b.second; };
	set<pair<int, int>, decltype(cmp)> s (cmp);
	s.insert(dots[0]);
	s.insert(dots[1]);
	int ans = squaredDist(dots[0], dots[1]), back = 0;
	for (int i = 2; i < n; i++)
	{
		while (back < i && (dots[back].first - dots[i].first) * (dots[back].first - dots[i].first) > ans)
		{
			s.erase(dots[back]);
			back++;
		}
		int d = (int)ceil(sqrt((double)ans + 1));
		auto l = s.lower_bound({ -100000, dots[i].second - d }), r = s.lower_bound({ 100000, dots[i].second + d });
		for (auto j = l; j != r; j++)
		{
			ans = min(ans, squaredDist(dots[i], *j));
		}
		s.insert(dots[i]);
	}
	cout << ans;
	return 0;

}