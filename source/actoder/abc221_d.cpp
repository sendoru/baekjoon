#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(void)
{
	int n;
	cin >> n;
	vector<pair<ll, ll>> players(n);
	for (int i = 0; i < n; i++)
	{
		cin >> players[i].first >> players[i].second;
	}

	vector<pair<ll, ll>> events;
	for (int i = 0; i < n; i++)
	{
		events.push_back({ players[i].first, 1 });
		events.push_back({ players[i].first + players[i].second, -1 });
	}

	sort(events.begin(), events.end());
	
	vector<ll> d(n + 1);
	ll curPlayers = 1;
	for (int i = 1; i < events.size(); i++)
	{
		d[curPlayers] += events[i].first - events[i - 1].first;
		curPlayers += events[i].second;
	}

	for (int i = 1; i < d.size(); i++)
	{
		cout << d[i] << ' ';
	}

	return 0;
}