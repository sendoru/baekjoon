#include <iostream>
#include <vector>
using namespace std;

void postorder(vector<pair<int, int>>& tree, vector<bool>& visited, int curNode)
{
	cout << (char)(curNode + 'A');
	if (tree[curNode].first != -1 && !visited[tree[curNode].first])
	{
		postorder(tree, visited, tree[curNode].first);
	}
	if (tree[curNode].second != -1 && !visited[tree[curNode].second])
	{
		postorder(tree, visited, tree[curNode].second);
	}
}

void inorder(vector<pair<int, int>>& tree, vector<bool>& visited, int curNode)
{
	if (tree[curNode].first != -1 && !visited[tree[curNode].first])
	{
		inorder(tree, visited, tree[curNode].first);
	}
	cout << (char)(curNode + 'A');
	if (tree[curNode].second != -1 && !visited[tree[curNode].second])
	{
		inorder(tree, visited, tree[curNode].second);
	}
}

void preorder(vector<pair<int, int>>& tree, vector<bool>& visited, int curNode)
{
	if (tree[curNode].first != -1 && !visited[tree[curNode].first])
	{
		preorder(tree, visited, tree[curNode].first);
	}
	if (tree[curNode].second != -1 && !visited[tree[curNode].second])
	{
		preorder(tree, visited, tree[curNode].second);
	}
	cout << (char)(curNode + 'A');
}

int main(void)
{
	int n;
	cin >> n;
	vector<pair<int, int>> tree(n, { -1, -1 });
	for (int i = 0; i < n - 1; i++)
	{
		char parent, left, right;
		cin >> parent >> left >> right;
		if (left != '.')
		{
			tree[parent - 'A'].first = left - 'A';
		}
		if (right != '.')
		{
			tree[parent - 'A'].second = right - 'A';
		}
	}
	vector<bool> visited(n, false);
	postorder(tree, visited, 0);
	cout << '\n';
	visited = vector<bool>(n, false);
	inorder(tree, visited, 0);
	cout << '\n';
	visited = vector<bool>(n, false);
	preorder(tree, visited, 0);
	cout << '\n';
}