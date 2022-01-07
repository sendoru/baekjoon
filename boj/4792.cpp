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
	int v, e, k;
	while (true)
	{
		cin >> v >> e >> k;
		if (v == 0 && e == 0 && k == 0)
		{
			break;
		}

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
			continue;
		}
		int maxB = (v - 1) - minR;

		sort(edgesB1.begin(), edgesB1.end());
		int minB = 0;
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
			}
		}

		if (k >= minB && k <= maxB)
		{
			cout << 1 << '\n';
		}
		else
		{
			cout << 0 << '\n';
		}

	}

	return 0;
}