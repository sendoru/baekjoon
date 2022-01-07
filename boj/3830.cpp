#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
constexpr int INF = 0x3fffffff;

int findRoot(int x, vector<int>& roots, vector<int>& weights)
{
	if (roots[x] == x) return x;
	int nextRoot = findRoot(roots[x], roots, weights);
	weights[x] += weights[roots[x]];
	return roots[x] = nextRoot;
}

bool hasSameRoots(int x, int y, vector<int>& roots, vector<int>& weights)
{
	return (findRoot(x, roots, weights) == findRoot(y, roots, weights));
}

void unite(int x, int y, int diff, vector<int>& roots, vector<int>& weights)
{
	int xRoot = findRoot(x, roots, weights), yRoot = findRoot(y, roots, weights);
	if (xRoot != yRoot)
	{
		weights[yRoot] += diff - weights[y] + weights[x];
		roots[yRoot] = xRoot;
	}
}


int getDiff(int x, int y, vector<int>& roots, vector<int>& weights)
{
	if (!hasSameRoots(x, y, roots, weights)) return INF;
	return weights[y] - weights[x];
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	while (n != 0)
	{
		vector<int> roots(n + 1), weights(n + 1);
		for (int i = 1; i <= n; i++)
		{
			roots[i] = i;
		}
		for (int i = 0; i < m; i++)
		{
			char c;
			cin >> c;
			if (c == '!')
			{
				int a, b, c;
				cin >> a >> b >> c;
				unite(a, b, c, roots, weights);
			}
			else
			{
				int a, b;
				cin >> a >> b;
				int diff = getDiff(a, b, roots, weights);
				if (diff == INF)
					cout << "UNKNOWN\n";
				else
					cout << diff << '\n';
			}
		}
		cin >> n >> m;
	}

}