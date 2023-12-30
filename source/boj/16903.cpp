#include <iostream>
#include <vector>
#include <bitset>
#include <map>
#include <set>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;

void insert(vector<vector<int>>& trie, set<int>& terminal, string& tempStr)
{
	ll node = 0, treeSize = trie.size();
	for (int j = 0; j < tempStr.length(); j++)
	{
		while (node >= trie.size())
		{
			trie.push_back(vector<int>(2, -1));
		}
		if (trie[node][tempStr[j]] == -1)
		{
			treeSize++;
			trie[node][tempStr[j]] = treeSize;
		}
		node = trie[node][tempStr[j]];
	}
	while (treeSize >= trie.size())
	{
		trie.push_back(vector<int>(2, -1));
	}
	terminal.insert(node);
}

void find(vector<vector<int>>& trie, set<int>& terminal, string& tempStr)
{
	int node = 0;
	for (int i = 0; i < tempStr.size(); i++)
	{
		if (terminal.find(node) != terminal.end())
		{
			return;
		}
		if (trie[node][tempStr[i]] == -1)
		{
			return;
		}
		else
		{
			node = trie[node][tempStr[i]];
		}
	}
}

void erase(vector<vector<int>>& trie, set<int>& terminal, string& tempStr)
{
	int node = 0;
	vector<int> nodes = { 0 };
	for (int i = 0; i < tempStr.length(); i++)
	{
		node = trie[node][tempStr[i]];
		nodes.push_back(node);
	}
	terminal.erase(nodes.back());
	for (int i = nodes.size() - 2; i >= 0; i--)
	{
		trie[nodes[i]][tempStr[i]] = -1;
		if (trie[nodes[i]][0] != -1 || trie[nodes[i]][1] != -1)
		{
			break;
		}
	}
	return;
}

string solveXorQuery(vector<vector<int>>& trie, set<int>& terminal, string& tempStr)
{
	int node = 0;
	string ret;
	for (int i = 0; i < tempStr.size(); i++)
	{
		if (trie[node][!tempStr[i]] != -1)
		{
			ret.push_back(1);
			node = trie[node][!tempStr[i]];
		}
		else
		{
			ret.push_back(0);
			node = trie[node][tempStr[i]];
		}
	}
	return ret;
}

string toBinary(int n)
{
	string ret;
	for (int i = 30; i >= 0; i--)
	{
		ret.push_back(n & (1 << i) ? 1 : 0);
	}
	return ret;
}

int toDecimal(string n)
{
	int ret = 0;
	for (int i = 0; i < n.size(); i++)
	{
		ret += n[n.size() - i - 1] * (1 << i);
	}
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m;
	cin >> m;
	vector<vector<int>> trie;
	set<int> terminal;
	map<int, int> numCnt;
	string zeroStr = toBinary(0);
	insert(trie, terminal, zeroStr);
	for (int i = 0; i < m; i++)
	{
		int q, x;
		cin >> q >> x;
		string xStr = toBinary(x);
		if (q == 1)
		{
			if (numCnt[x] == 0)
			{
				insert(trie, terminal, xStr);
			}
			numCnt[x]++;
		}
		else if (q == 2)
		{
			if (numCnt[x] == 1)
			{
				erase(trie, terminal, xStr);
			}
			numCnt[x]--;
		}
		else
		{
			string ansStr = solveXorQuery(trie, terminal, xStr);
			int ans = toDecimal(ansStr);
			cout << ans << '\n';
		}
	}

	return 0;
}