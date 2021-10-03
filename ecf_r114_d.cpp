#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;
constexpr ll INF = 3e18;
set<vector<int>> visited;
set<vector<int>> banned;
pair<ll, vector<int>> ans = { -INF, {} };

void dfs(vector<int> curRoute, vector<vector<int>>& a)
{
	visited.insert(curRoute);

	if (banned.find(curRoute) == banned.end())
	{
		ll curLost = 0;
		for (int i = 0; i < curRoute.size(); i++)
		{
			curLost += a[i][curRoute[i]];
		}
		if (ans.first < curLost)
		{
			ans = make_pair(curLost, curRoute);
		}
		return;
	}

	for (int i = 0; i < curRoute.size(); i++)
	{
		if (curRoute[i] > 1)
		{
			curRoute[i]--;
			if (visited.find(curRoute) == visited.end())
			{
				dfs(curRoute, a);
			}
			curRoute[i]++;
		}
	}

}

int main(void)
{
	int n;
	cin >> n;
	vector<int> c(n);
	vector<vector<int>> a(n);

	for (int i = 0; i < n; i++)
	{
		cin >> c[i];
		a[i] = vector<int>(c[i] + 1);
		for (int j = 1; j <= c[i]; j++)
		{
			cin >> a[i][j];
		}
		for (int j = 1; j <= c[i]; j++)
		{
			a[i][j] -= a[i][c[i]];
		}
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		vector<int> b(n);
		for (int j = 0; j < n; j++)
		{
			cin >> b[j];
		}
		banned.insert(b);
	}

	dfs(c, a);
	for (int elem : ans.second) cout << elem << '\n';
	return 0;
}

