#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
typedef long long ll;

int findRoot(int x, vector<int>& roots) {
	if (roots[x] == x) return x;
	return roots[x] = findRoot(roots[x], roots);
}

bool hasSameRoots(int x, int y, vector<int>& roots) {
	return (findRoot(x, roots) == findRoot(y, roots));
}

void unite(int x, int y, vector<int>& roots, vector<int>& sizes) {
	int xRoot = findRoot(x, roots), yRoot = findRoot(y, roots);
	if (xRoot != yRoot) {
		sizes[xRoot] += sizes[yRoot];
		roots[yRoot] = xRoot;
	}
}

int getSize(int x, vector<int>& roots, vector<int>& sizes) {
	return sizes[findRoot(x, roots)];
}

vector<vector<int>> makeSparseTable(vector<int> f) {
	int n = f.size(), h = 1 + (int)ceil(log2(n));
	vector<vector<int>> ret(h, vector<int>(f.size()));

	for (int i = 0; i < n; i++)
		ret[0][i] = f[i];
	for (int i = 1; i < h; i++)
		for (int j = 0; j < n; j++)
			ret[i][j] = ret[i - 1][ret[i - 1][j]];

	return ret;
}

int main(void)
{
	cout << "원소의 갯수와 쿼리의 갯수를 입력하세요:" << endl;
	int n, q;
	cin >> n >> q;
	vector<int> roots(n + 1), sizes(n + 1);
	for (int i = 0; i <= n; i++)
	{
		roots[i] = i;
		sizes[i] = 1;
	}

	cout << "q개의 줄에 결합할 두 원소의 번호를 입력하세요:" << endl;
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		if (hasSameRoots(x, y, roots))
		{
			cout << x << "번 원소와 " << y << "번 원소는 이미 같은 집합에 있으며, 그 집합에는 " << getSize(x, roots, sizes) << "개의 원소가 있습니다." << endl;
		}
		else
		{
			unite(x, y, roots, sizes);
			cout << x << "번 원소와 " << y << "번 원소를 합친 후 두 집합에는 " << getSize(x, roots, sizes) << "개의 원소가 있습니다." << endl;
		}
	}

	return 0;
}