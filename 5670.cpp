#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
using namespace std;
vector<unordered_map<char, int>> trie;
unordered_set<int> terminal;
int n, ans;

void solve(int curNode, int typeCnt)
{
	if (terminal.find(curNode) != terminal.end())
	{
		ans += typeCnt;
	}
	if (trie[curNode].size() > 1 || terminal.find(curNode) != terminal.end() || curNode == 0)
	{
		typeCnt++;
	}
	for (auto nextNode : trie[curNode])
	{
		if (nextNode.second != 0)
		{
			solve(nextNode.second, typeCnt);
		}
	}
	return;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout.precision(2);
	
	while (true)
	{
		cin >> n;
		ans = 0;
		if (cin.eof())
		{
			return 0;
		}
		auto& trieRep = trie;
		string tempStr;
		int treeSize = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> tempStr;
			int node = 0;
			for (int j = 0; j < tempStr.length(); j++)
			{
				while (node >= trie.size())
				{
					trie.push_back(unordered_map<char, int>());
				}
				if (trie[node].find(tempStr[j]) == trie[node].end())
				{
					treeSize++;
					trie[node].insert({ tempStr[j] ,treeSize });
				}
				node = trie[node][tempStr[j]];
			}
			while (treeSize >= trie.size())
			{
				trie.push_back(unordered_map<char, int>());
			}
			terminal.insert(node);
		}

		solve(0, 0);
		cout << ans / (double)n << '\n';
		trie.clear();
		terminal.clear();
	}
	return 0;
}