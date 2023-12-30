#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAX = 16;
const ll INF = 987654321;

ld solve(int init, int here, ll visited, vector<vector<ld> >& dist, vector<vector<ld> >& cache)
{
	if (visited == (1ll << dist.size()) - 1)
	{
		return dist[here][init];
	}

	ld& ret = cache[here][visited];
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
		ld c = dist[here][next] + solve(init, next, visited + (1ll << next), dist, cache);
		ret = min(ret, c);
	}

	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(15);

	int n;
	cin >> n;
	vector<pair<ld, ld> > pos(n);
	vector<vector<ld> > dist(n, vector<ld>(n));
	for (int i = 0; i < n; i++)
	{
		cin >> pos[i].first >> pos[i].second;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dist[i][j] = powl(powl(pos[i].first - pos[j].first, 2) + powl(pos[i].second - pos[j].second, 2), 0.5);
		}
	}

	ld ans = INF;
	for (int i = 0; i < n; i++)
	{
		vector<vector<ld> > cache(n, vector<ld>(1ll << n, -1.0));
		ans = min(ans, solve(i, i, 1ll << i, dist, cache));
	}
	cout << ans << '\n';
	return 0;
}