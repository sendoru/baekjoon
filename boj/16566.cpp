#include <iostream>
#include <vector>
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

void unite(int x, int y, vector<int>& roots)
{
	int xRoot = findRoot(x, roots);
	int yRoot = findRoot(y, roots);
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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;
	vector<int> roots(n + 1, n + 10);
	for (int i = 1; i <= n; i++)
	{
		roots[i] = i;
	}
	vector<int> cards(m + 1);
	for (int i = 1; i <= m; i++)
	{
		cin >> cards[i];
	}
	sort(cards.begin(), cards.end());
	int cardsIndex = 1;
	// ex) 주어진 카드가 3, 5, 8일때
	// roots[1], [2], [3] = 3, [4], [5] = 5, [6], [7], [8] = 8
	for (int i = 1; i <= n; i++)
	{
		if (cardsIndex > m)
			break;
		roots[i] = cards[cardsIndex];
		if (cards[cardsIndex] == i)
			cardsIndex++;
	}
	for (int i = 0; i < k; i++)
	{
		int curCard;
		cin >> curCard;
		cout << findRoot(curCard + 1, roots) << '\n';
		unite(curCard + 1, findRoot(curCard + 1, roots) + 1, roots);
	}
	return 0;
}