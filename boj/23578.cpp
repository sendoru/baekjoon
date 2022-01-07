#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
typedef long long ll;

int main(void)
{
	int n;
	cin >> n;
	vector<ll> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> unused, used;
	for (int i = 0; i < n; i++)
		unused.push(make_pair(v[i], v[i]));
	ll ans = 0;
	if (n == 1)
	{
		cout << 0;
		return 0;
	}
	while (!unused.empty())
	{
		auto temp = unused.top();
		unused.pop();
		if ((unused.empty()) || !used.empty() && used.top() < unused.top())
		{
			unused.push(temp);
			ans += used.top().first + unused.top().first;
			auto next1 = used.top(), next2 = unused.top();
			used.pop();
			unused.pop();

			next1.first = (ll)sqrtl(next1.first / next1.second) + 1;
			next1.first *= next1.first;
			next1.first *= next1.second;

			next2.first = (ll)sqrtl(next2.first / next2.second) + 1;
			next2.first *= next2.first;
			next2.first *= next2.second;

			used.push(next1);
			used.push(next2);
		}
		else
		{
			unused.push(temp);
			ans += unused.top().first;
			auto next1 = unused.top();
			unused.pop();

			next1.first = (ll)sqrtl(next1.first / next1.second) + 1;
			next1.first *= next1.first;
			next1.first *= next1.second;

			ans += unused.top().first;
			auto next2 = unused.top();
			unused.pop();

			next2.first = (ll)sqrtl(next2.first / next2.second) + 1;
			next2.first *= next2.first;
			next2.first *= next2.second;

			used.push(next1);
			used.push(next2);
		}
	}

	cout << ans;
	return 0;
}