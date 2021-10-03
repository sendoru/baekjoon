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
	cout << "������ ������ ������ ������ �Է��ϼ���:" << endl;
	int n, q;
	cin >> n >> q;
	vector<int> roots(n + 1), sizes(n + 1);
	for (int i = 0; i <= n; i++)
	{
		roots[i] = i;
		sizes[i] = 1;
	}

	cout << "q���� �ٿ� ������ �� ������ ��ȣ�� �Է��ϼ���:" << endl;
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		if (hasSameRoots(x, y, roots))
		{
			cout << x << "�� ���ҿ� " << y << "�� ���Ҵ� �̹� ���� ���տ� ������, �� ���տ��� " << getSize(x, roots, sizes) << "���� ���Ұ� �ֽ��ϴ�." << endl;
		}
		else
		{
			unite(x, y, roots, sizes);
			cout << x << "�� ���ҿ� " << y << "�� ���Ҹ� ��ģ �� �� ���տ��� " << getSize(x, roots, sizes) << "���� ���Ұ� �ֽ��ϴ�." << endl;
		}
	}

	return 0;
}