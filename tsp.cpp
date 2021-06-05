#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
const ll MAX = 16;
const ll INF = 987654321;

ll solve(int init, int here, ll visited, vector<vector<ll> >& dist, vector<vector<ll> >& cache)
{
	if (visited == (1ll << dist.size()) - 1)
	{
		return dist[here][init];
	}

	ll& ret = cache[here][visited];
	if (ret >= 0)
	{
		return ret;
	}

	ret = INF;
	for (int next = 0; next < dist.size(); next++)
	{
		if (visited & (1ll << next))
		{
			continue;
		}
		ll c = dist[here][next] + solve(init, next, visited + (1ll << next), dist, cache);
		ret = min(ret, c);
	}

	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<vector<ll> > dist(n, vector<ll>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> dist[i][j];
			if (dist[i][j] == 0)
			{
				dist[i][j] = INF;
			}
		}
	}

	ll ans = INF;
	for (int i = 0; i < n; i++)
	{
		vector<vector<ll> > cache(n, vector<ll>(1ll << n, -1));
		ans = min(ans, solve(i, i, 1ll << i, dist, cache));
	}
	cout << ans << '\n';
	return 0;
}