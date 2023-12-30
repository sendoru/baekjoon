#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;

bool bfs(vector<string>& lv)
{
	int n = lv[0].length();
	if (lv[0][0] == '1' || lv[1][n - 1] == '1') return false;
	vector<vector<bool>> reachable(2, vector<bool>(n));
	reachable[0][0] = true;
	if (lv[1][0] == '0') reachable[1][0] = true;
	for (int i = 1; i < n; i++)
	{
		if ((reachable[0][i - 1] == true) || (reachable[1][i - 1] == true))
		{
			if (lv[0][i] == '0') reachable[0][i] = true;
			if (lv[1][i] == '0') reachable[1][i] = true;
		}
	}
	return reachable[1][n - 1];
}

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<string> lv(2);
		cin >> lv[0];
		cin >> lv[1];
		cout << (bfs(lv) ? "YES" : "NO") << '\n';
	}
	return 0;
}