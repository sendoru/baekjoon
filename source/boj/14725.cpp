#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

void dfs(map<string, set<string>>& trie, map<string, bool>& visited, string curNode, int depth)
{
	for (auto nextNode : trie[curNode])
	{
		if (!visited[nextNode])
		{
			visited[nextNode] = true;
			for (int i = 0; i < depth; i++)
			{
				cout << "--";
			}
			for (int i = curNode.length(); i < nextNode.length(); i++)
			{
				cout << nextNode[i];
			}
			cout << '\n';
			dfs(trie, visited, nextNode, depth + 1);
		}
	}
}

int main(void)
{
	int n;
	cin >> n;
	map<string, set<string>> trie;
	map<string, bool> visited;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		string prevStr, curStr;
		for (int j = 0; j < k; j++)
		{
			prevStr += curStr;
			cin >> curStr;
			trie[prevStr].insert(prevStr + curStr);
		}
	}
	dfs(trie, visited, "", 0);
	return 0;
}