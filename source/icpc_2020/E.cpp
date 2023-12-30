#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findRoot(int x, vector<int>& roots)
{
	if (roots[x] == x) return x;
	return roots[x] = findRoot(roots[x], roots);
}

bool hasSameRoots(int x, int y, vector<int>& roots)
{
	return (findRoot(x, roots) == findRoot(y, roots));
}

void unite(int x, int y, vector<int>& roots)
{
	int xRoot = findRoot(x, roots), yRoot = findRoot(y, roots);
	if (xRoot != yRoot)
		roots[yRoot] = xRoot;
}

int main(void)
{
	int n, m;
	cin >> n >> m;
	vector<int> roots(n + 1);
	for (int i = 1; i <= n; i++)
		roots[i] = i;

	for (int i = 0; i < m; i++)
	{
		int d1, d2;
		cin >> d1 >> d2;
		if (hasSameRoots(d1, d2, roots))
		{
			cout << i + 1;
			return 0;
		}
		else
		{
			unite(d1, d2, roots);
		}
	}
	cout << 0;
	return 0;
}