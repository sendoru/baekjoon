#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
const ll MAX = 16;
const ll INF = 987654321;

void floyd(vector<vector<ll> >& dist)
{
	int n = dist.size();
	for (int m = 0; m < n; m++)
	{
		for (int s = 0; s < n; s++)
		{
			for (int e = 0; e < n; e++)
			{
				dist[s][e] = min(dist[s][e], dist[s][m] + dist[m][e]);
			}
		}
	}

}

ll solve(int init, int here, ll visited, vector<vector<ll> >& dist, vector<vector<ll> >& cache)
{
	if (visited == (1ll << dist.size()) - 1)
	{
		return 0;
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

	int n, k;
	cin >> n >> k;
	vector<vector<ll> > dist(n, vector<ll>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> dist[i][j];
		}
	}

	floyd(dist);
	vector<vector<ll> >cache(n, vector<ll>(1ll << n, -1));
	ll ans = solve(k, k, 1ll << k, dist, cache);

	cout << ans << '\n';
	return 0;
}