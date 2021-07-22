#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100001

// 부모노드 누군지 찾아주는 배열
int parent[MAX];

using namespace std;

int findParent(int x, int* parent)
{
	if (parent[x] == x) return x;
	return parent[x] = findParent(parent[x], parent);
}

bool hasSameParents(int x, int y, int* parent)
{
	int xParent = findParent(x, parent);
	int yParent = findParent(y, parent);
	if (xParent == yParent) return true;
	else return false;
}

void unite(int x, int y, int* parent)
{
	int xParent = findParent(x, parent);
	int yParent = findParent(y, parent);
	if (xParent != yParent)
		parent[yParent] = xParent;
}

int main(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);


	// 간선들 모아둔 벡터. vector<pair<가중치, pair<시작점, 도착점> > > 형태
	vector < pair<int, pair<int, int> > > edges;

	for (int i = 0; i < MAX; i++)
	{
		parent[i] = i;
	}

	int countofVertexes, countofEdges;
	cin >> countofVertexes >> countofEdges;
	for (int i = 0; i < countofEdges; i++)
	{
		edges.push_back({ 0, {0, 0} });
		cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
	}

	sort(edges.begin(), edges.end());

	long long sum = 0, count = 0;

	for (int i = 0; i < countofEdges; i++)
	{
		if (hasSameParents(edges[i].second.first, edges[i].second.second, parent) == false)
		{
			unite(edges[i].second.first, edges[i].second.second, parent);
			sum += edges[i].first;
		}
	}

	cout << sum << endl;

	return 0;
}
