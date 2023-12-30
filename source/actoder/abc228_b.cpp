#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int bfs(vector<int>& a, int root)
{
	vector<bool> visited(a.size());
	visited[root] = true;
	int ret = 1;
	int curNode = root;

	while (true)
	{
		if (!visited[a[curNode]])
		{
			curNode = a[curNode];
			ret++;
			visited[curNode] = true;
		}
		else
			break;
	}

	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, x;
	cin >> n >> x;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	cout << bfs(a, x);

	return 0;
}