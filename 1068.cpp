#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

int bfs(int start, vector<set<int> >& tree, vector<bool>& check)
{
	if (check[start])
	{
		return 0;
	}

	int nodeCnt = 0;
	
	queue<int> q;
	q.push(start);

	while (!q.empty())
	{
		int curNode = q.front();
		check[curNode] = true;
		if (tree[curNode].empty())
		{
			nodeCnt++;
		}
		q.pop();

		for (auto iter = tree[curNode].begin(); iter != tree[curNode].end(); iter++)
		{
			int nextNode = *iter;
			if (!check[nextNode])
			{
				q.push(nextNode);
			}
		}
	}

	return nodeCnt;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, deletedNode, ans, root = 0;
	cin >> n;
	vector<set<int> > tree(n, set<int>());
	vector<bool> check(n, false);

	for (int i = 0; i < n; i++)
	{
		int parent;
		cin >> parent;
		if (parent != -1)
		{
			tree[parent].insert(i);
		}
		else
		{
			root = i;
		}
	}

	cin >> deletedNode;
	bfs(deletedNode, tree, check);

	for (int i = 0; i < n; i++)
	{
		if (find(tree[i].begin(), tree[i].end(), deletedNode) != tree[i].end())
		{
			tree[i].erase(deletedNode);
			break;
		}
	}

	ans = bfs(root, tree, check);

	cout << ans << '\n';
	return 0;

}