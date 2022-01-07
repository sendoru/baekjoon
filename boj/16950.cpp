#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1002
using namespace std;

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

int main(void)
{
	int v, e, k, blueCnt = 0;
	cin >> v >> e >> k;

	vector<pair<int, pair<int, int>>> edgesB0;
	vector<pair<int, pair<int, int>>> edgesB1;
	for (int i = 0; i < e; i++)
	{
		char color; int start, end;
		cin >> color >> start >> end;
		start--; end--;
		if (color == 'B')
		{
			edgesB0.push_back({ 0, {start, end} });
			edgesB1.push_back({ 1, {start, end} });
			blueCnt++;
		}
		else if (color == 'R')
		{
			edgesB0.push_back({ 1, {start, end} });
			edgesB1.push_back({ 0, {start, end} });
		}
	}

	sort(edgesB0.begin(), edgesB0.end());
	int minR = 0, cnt = 0;
	vector<int> parent(v);
	for (int i = 0; i < v; i++)
	{
		parent[i] = i;
	}
	for (int i = 0; i < e; i++)
	{
		if (hasSameParents(edgesB0[i].second.first, edgesB0[i].second.second, parent) == false)
		{
			unite(edgesB0[i].second.first, edgesB0[i].second.second, parent);
			minR += edgesB0[i].first;
			cnt++;
		}
	}
	if (cnt != v - 1)
	{
		cout << 0 << '\n';
		return 0;
	}
	int maxB = (v - 1) - minR;

	sort(edgesB1.begin(), edgesB1.end());
	int minB = 0;
	vector<int> used(e);
	for (int i = 0; i < v; i++)
	{
		parent[i] = i;
	}
	for (int i = 0; i < e; i++)
	{
		if (hasSameParents(edgesB1[i].second.first, edgesB1[i].second.second, parent) == false)
		{
			unite(edgesB1[i].second.first, edgesB1[i].second.second, parent);
			minB += edgesB1[i].first;
			used[i] = 1;
		}
	}

	if (k >= minB && k <= maxB)
	{
		cnt = 0;
		int reversed = 0;
		vector<pair<int, pair<int, int>>> edges;
		for (int i = 0; i < e; i++)
		{
			if (used[i] == 1 && edgesB1[i].first == 1)
			{
				edges.push_back(edgesB1[i]);
			}
		}
		for (int i = 0; i < e; i++)
		{
			if (used[i] == 0 && edgesB1[i].first == 1)
			{
				edges.push_back(edgesB1[i]);
			}
		}
		for (int i = 0; i < e; i++)
		{
			if (edgesB1[i].first == 0)
			{
				edges.push_back(edgesB1[i]);
			}
		}
		for (int i = 0; i < v; i++)
		{
			parent[i] = i;
		}
		for (int i = 0; i < e; i++)
		{
			if (hasSameParents(edges[i].second.first, edges[i].second.second, parent) == false)
			{
				unite(edges[i].second.first, edges[i].second.second, parent);
				minB += edges[i].first;
				cnt++;
				cout << edges[i].second.first + 1 << ' ' << edges[i].second.second + 1 << '\n';
				if (cnt == k)
				{
					i = blueCnt - 1;
				}
			}
		}
	}
	else
	{
		cout << 0 << '\n';
	}

	return 0;
}