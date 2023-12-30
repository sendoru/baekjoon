#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

int main(void)
{
	vector<pair<ll, ll>> v1;
	v1.push_back({ 1, 2 });
	v1.push_back({ 2, 1 });
	v1.push_back({ -1, 2 });
	v1.push_back({ -2, 1 });
	v1.push_back({ 1, -2 });
	v1.push_back({ 2, -1 });
	v1.push_back({ -1, -2 });
	v1.push_back({ -2, -1 });

	vector<pair<ll, ll>> v2;
	for (auto elem1 : v1)
	{
		for (auto elem2 : v1)
		{
			v2.push_back({ elem1.first + elem2.first, elem1.second + elem2.second });
		}
	}

	ll x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	x2 -= x1;
	y2 -= y1;
	bool ans = (find(v2.begin(), v2.end(), make_pair(x2, y2)) != v2.end());
	cout << (ans ? "Yes" : "No");
	return 0;
}