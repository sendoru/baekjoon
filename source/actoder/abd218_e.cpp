#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int findRoot(ll x, vector<ll>& roots)
{
	if (roots[x] == x) return x;
	return roots[x] = findRoot(roots[x], roots);
}

bool hasSameRoot(ll x, ll y, vector<ll>& roots)
{
	ll xRoot = findRoot(x, roots);
	ll yRoot = findRoot(y, roots);
	if (xRoot == yRoot) return true;
	else return false;
}

void unite(ll x, ll y, vector<ll>& roots)
{
	ll xRoot = findRoot(x, roots);
	ll yRoot = findRoot(y, roots);
	if (xRoot != yRoot)
	{
		if (xRoot > yRoot)
			roots[yRoot] = xRoot;
		else
			roots[xRoot] = yRoot;
	}
}

int main(void)
{
	ll n, m;
	ll ans = 0;
	cin >> n >> m;
	vector<ll> roots(n + 1);
	// cost, start, end 순으로 저장
	vector<vector<ll>> edges(m, vector<ll>(3));
	for (int i = 1; i <= n; i++)
	{
		roots[i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> edges[i][1] >> edges[i][2] >> edges[i][0];
	}
	sort(edges.begin(), edges.end());
	for (int i = 0; i < m; i++)
	{
		if (!hasSameRoot(edges[i][1], edges[i][2], roots))
		{
			edges[i][0] = 0;
			unite(edges[i][1], edges[i][2], roots);
		}
	}

	for (int i = 0; i < m; i++)
	{
		if (edges[i][0] > 0)
		{
			ans += edges[i][0];
		}
	}

	cout << ans;
	return 0;
}