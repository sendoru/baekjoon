#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> makePrimeTable(int n)
{
	vector<bool> ret(n + 1, true);
	ret[0] = false;
	ret[1] = false;
	for (int i = 2; i * i <= n; i++)
	{
		if (!ret[i]) continue;
		for (int j = 2; i * j <= n; j++)
		{
			ret[i * j] = false;
		}
	}

	return ret;
}

bool dfs(vector<int>& evens, vector<int>& odds, vector<bool>& primeTable, vector<bool>& visited, vector<int>& from, int curNode)
{
	for (int nextNode = 0; nextNode < odds.size(); nextNode++)
	{
		if (from[nextNode] == -1 && primeTable[evens[curNode] + odds[nextNode]])
		{
			from[nextNode] = curNode;
			return true;
		}
	}

	for (int nextNode = 0; nextNode < evens.size(); nextNode++)
	{
		if (!visited[nextNode] && primeTable[evens[curNode] + odds[nextNode]])
		{
			visited[nextNode] = true;
			if (dfs(evens, odds, primeTable, visited, from, from[nextNode]))
			{
				from[nextNode] = curNode;
				return true;
			}
		}
	}


	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<bool> primeTable = makePrimeTable(2222);
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
		cin >> nums[i];

	vector<int> ans;
	for (int i = 1; i < n; i++)
	{
		if (!primeTable[nums[0] + nums[i]])
			continue;
		int matched = 1;
		vector<int> odds, evens;
		for (int j = 0; j < n; j++)
		{
			if (j != 0 && j != i)
			{
				if (nums[j] % 2 == 0)
				{
					evens.push_back(nums[j]);
				}
				else
				{
					odds.push_back(nums[j]);
				}
			}
		}

		if (evens.size() != odds.size())
			continue;

		vector<int> from(odds.size(), -1);
		for (int j = 0; j < evens.size(); j++)
		{
			if (true)
			{
				vector<bool> visited(odds.size(), false);
				if (dfs(evens, odds, primeTable, visited, from, j))
				{
					matched++;
				}
			}
		}
		if (matched == n / 2)
		{
			ans.push_back(nums[i]);
		}
	}

	if (ans.size() == 0)
	{
		cout << -1;
	}
	else
	{
		sort(ans.begin(), ans.end());
		for (auto elem : ans)
		{
			cout << elem << ' ';
		}
	}
	return 0;
}