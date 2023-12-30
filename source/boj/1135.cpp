#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(vector<vector<int>>& tree, int curNode)
{
	if (tree[curNode].empty())
	{
		return 0;
	}
	vector<int> v;
	for (int nextNode : tree[curNode])
	{
		v.push_back(solve(tree, nextNode));
	}
	sort(v.begin(), v.end(), greater<int>());
	for (int i = 0; i < v.size(); i++)
	{
		v[i] += i + 1;
	}
	sort(v.begin(), v.end(), greater<int>());
	return v[0];
}

int main(void)
{
	int n;
	cin >> n;
	vector<vector<int>> tree(n);
	for (int i = 0; i < n; i++)
	{
		int parent;
		cin >> parent;
		if (parent != -1)
		{
			tree[parent].push_back(i);
		}
	}

	cout << solve(tree, 0);
	return 0;
}