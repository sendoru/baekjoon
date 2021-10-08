#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
constexpr ll MAX = 30000000000;

ll dist(pair<ll, ll> a, pair<ll, ll> b)
{
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int main(void)
{
	int n;
	cin >> n;
	vector<pair<ll, ll>> polices(n);
	for (int i = 0; i < n; i++)
	{
		cin >> polices[i].first >> polices[i].second;
	}
	pair<ll, ll> thief;
	cin >> thief.first >> thief.second;
	vector<pair<ll, ll>> d = { {thief.first + MAX, thief.second}, {thief.first - MAX, thief.second}, {thief.first, thief.second + MAX}, {thief.first, thief.second - MAX} };
	int blocked = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (dist(polices[j], d[i]) <= MAX)
			{
				blocked++;
				break;
			}
		}
	}
	
	cout << (blocked == 4 ? "NO" : "YES");
	return 0;
}