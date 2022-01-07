#include <iostream>
#include <vector>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <random>
using namespace std;
typedef long long ll;
int trie1[4000100][26] = { 0, }, trie2[4000100][26] = { 0, };
vector<bool> terminal1(4000100), terminal2(4000100);
int trie1Size = 0, trie2Size = 0;

void insert(int trie[][26], int& treeSize, vector<bool>& terminal, string& tempStr, bool reversed)
{
	ll node = 0;
	for (int j = 0; j < tempStr.length(); j++)
	{
		if (reversed) j = tempStr.length() - j - 1;
		while (node >= treeSize)
		{
			treeSize++;
		}
		if (trie[node][tempStr[j] - 'a'] == 0)
		{
			trie[node][tempStr[j] - 'a'] = treeSize;
			treeSize++;
		}
		node = trie[node][tempStr[j] - 'a'];
		if (reversed) j = tempStr.length() - j - 1;
	}
	terminal[node] = true;
}

void find(int trie[][26], vector<bool>& terminal, bitset<2001>& found, string& tempStr, bool reversed)
{
	int node = 0;
	for (int i = 0; i < tempStr.size(); i++)
	{
		if (reversed) i = tempStr.length() - i - 1;
		node = trie[node][tempStr[i] - 'a'];
		if (node == 0)
		{
			return;
		}
		if (terminal[node])
		{
			found[i] = true;
		}
		if (reversed) i = tempStr.length() - i - 1;
	}

}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int c, n;
	cin >> c >> n;
	// n = 4000; c = 4000;
	string tempStr;
	int treeSize = 0;
	for (int i = 0; i < c; i++)
	{
		cin >> tempStr;
		// tempStr.clear();
		// for (int i = 0; i < 800; i++) tempStr.push_back('a' + rand() % 26);
		insert(trie1, trie1Size, terminal1, tempStr, false);
	}

	for (int i = 0; i < n; i++)
	{
		cin >> tempStr;
		// tempStr.clear();
		// for (int i = 0; i < 800; i++) tempStr.push_back('a' + rand() % 26);
		insert(trie2, trie2Size, terminal2, tempStr, true);
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> tempStr;
		bitset<2001> prefix, suffix;
		find(trie1, terminal1, prefix, tempStr, false);
		find(trie2, terminal2, suffix, tempStr, true);
		bool ans = false;
		for (int i = 0; i < tempStr.size() - 1; i++)
		{
			if (prefix[i] && suffix[i + 1])
			{
				ans = true;
			}
		}
		cout << (ans ? "Yes" : "No") << '\n';
	}

	return 0;
}