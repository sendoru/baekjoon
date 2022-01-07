#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int findRoot(int x, vector<int>& roots)
{
	if (roots[x] == x) return x;
	return roots[x] = findRoot(roots[x], roots);
}

bool hasSameRoot(int x, int y, vector<int>& roots)
{
	int xRoot = findRoot(x, roots);
	int yRoot = findRoot(y, roots);
	if (xRoot == yRoot) return true;
	else return false;
}

void unite(int x, int y, vector<int>& roots, vector<set<int>>& colors)
{
	int xRoot = findRoot(x, roots);
	int yRoot = findRoot(y, roots);
	if (xRoot != yRoot)
	{
		if (colors[xRoot].size() > colors[yRoot].size())
		{
			for (auto elem : colors[yRoot])
			{
				colors[xRoot].insert(elem);
			}
			colors[yRoot].clear();
			roots[yRoot] = xRoot;
		}
		else
		{
			for (auto elem : colors[xRoot])
			{
				colors[yRoot].insert(elem);
			}
			colors[xRoot].clear();
			roots[xRoot] = yRoot;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, q;
	cin >> n >> q;
	q += n - 1;
	vector<int> initRoots, roots(n + 1);
	vector<set<int>> colors(n + 1);
	roots[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		cin >> roots[i];
	}
	for (int i = 1; i <= n; i++)
	{
		int temp;
		cin >> temp;
		colors[i].insert(temp);
	}
	initRoots = roots;
	vector<vector<int>> query(q, vector<int>(2));
	for (int i = 0; i < q; i++)
	{
		cin >> query[i][0] >> query[i][1];
		if (query[i][0] == 1)
		{
			roots[query[i][1]] = query[i][1];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		unite(i, roots[i], roots, colors);
	}
	vector<int> ans;
	for (int i = q - 1; i >= 0; i--)
	{
		if (query[i][0] == 1)
		{
			unite(query[i][1], initRoots[query[i][1]], roots, colors);
		}
		else if (query[i][0] == 2)
		{
			ans.push_back(colors[findRoot(query[i][1], roots)].size());
		}
	}
	for (int i = ans.size() - 1; i >= 0; i--)
	{
		cout << ans[i] << '\n';
	}
	return 0;
}