#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int findParent(int x, vector<int>& parent)
{
	if (parent[x] == x) return x;
	return parent[x] = findParent(parent[x], parent);
}

bool hasSameParents(int x, int y, vector<int>& parent)
{
	int xParent = findParent(x, parent);
	int yParent = findParent(y, parent);
	if (xParent == yParent) return true;
	else return false;
}

void unite(int x, int y, vector<int>& parent)
{
	int xParent = findParent(x, parent);
	int yParent = findParent(y, parent);
	if (xParent != yParent)
		parent[yParent] = xParent;
}

struct dot2D
{
	ll idx, x, y;
	ll dist(const dot2D& other)
	{
		return min(abs(x - other.x), abs(y - other.y));
	}
};

struct query
{
	ll idx, hp, d1Idx, d2Idx;
};

struct edge
{
	ll s, e, w;
	edge(ll _s, ll _e, ll _w) { s = _s; e = _e; w = _w; }
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, q;
	cin >> n >> q;
	vector<dot2D> dots(n);
	for (int i = 0; i < n; i++)
	{
		cin >> dots[i].x >> dots[i].y;
		dots[i].idx = i;
	}

	vector<query> queries(q);
	for (int i = 0; i < q; i++)
	{
		queries[i].idx = i;
		cin >> queries[i].d1Idx >> queries[i].d2Idx >> queries[i].hp;
		queries[i].d1Idx--;
		queries[i].d2Idx--;
	}

	vector<edge> edges;
	sort(dots.begin(), dots.end(), [](dot2D& a, dot2D& b) { return a.x < b.x; });
	for (int i = 0; i < dots.size() - 1; i++)
	{
		edges.push_back(edge(dots[i].idx, dots[i + 1].idx, dots[i].dist(dots[i + 1])));
	}

	sort(dots.begin(), dots.end(), [](dot2D& a, dot2D& b) { return a.y < b.y; });
	for (int i = 0; i < dots.size() - 1; i++)
	{
		edges.push_back(edge(dots[i].idx, dots[i + 1].idx, dots[i].dist(dots[i + 1])));
	}

	sort(edges.begin(), edges.end(), [](edge& a, edge& b) { return a.w < b.w; });
	sort(dots.begin(), dots.end(), [](dot2D& a, dot2D& b) { return a.idx < b.idx; });

	sort(queries.begin(), queries.end(), [](query& a, query& b) { return a.hp < b.hp; });
	vector<bool> ans(q);
	vector<int> parents(n);
	for (int i = 0; i < n; i++)
	{
		parents[i] = i;
	}
	int edgeIdx = 0;

	// 코드 진짜 쓰레기같네
	for (auto& curQuery : queries)
	{
		while (edgeIdx < edges.size() && edges[edgeIdx].w <= curQuery.hp)
		{
			unite(edges[edgeIdx].s, edges[edgeIdx].e, parents);
			edgeIdx++;
		}

		if (hasSameParents(curQuery.d1Idx, curQuery.d2Idx, parents))
		{
			ans[curQuery.idx] = true;
		}
	}

	for (auto elem : ans)
	{
		cout << (elem ? "YES" : "NO") << '\n';
	}

	return 0;
}