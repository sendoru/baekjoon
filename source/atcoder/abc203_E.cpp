#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <stack>

using namespace std;
typedef unsigned long long ull;

void dfs(unordered_set<ull>& blacks, unordered_set<ull>& whites, ull whiteX, ull whiteY, ull n)
{
	stack<ull> s;
	s.push((whiteX << 32) + whiteY);
	while (!s.empty())
	{
		ull curX = s.top() >> 32;
		ull curY = s.top() - (curX << 32);
		s.pop();

		if (curX == 2 * n)
		{
			whites.insert(curY);
			continue;
		}
		if (blacks.find(((curX + 1ull) << 32) + curY) == blacks.end())
		{
			s.push(((curX + 1ull) << 32) + curY);
		}
		if (curY - 1 >= 0 && blacks.find(((curX + 1ull) << 32) + curY - 1) != blacks.end())
		{
			s.push(((curX + 1ull) << 32) + curY - 1);
		}
		if (curY + 1 <= 2 * n && blacks.find(((curX + 1ull) << 32) + curY + 1) != blacks.end())
		{
			s.push(((curX + 1ull) << 32) + curY + 1);
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ull n, m;
	cin >> n >> m;
	unordered_set<ull> blacks;
	unordered_set<ull> whites;
	
	for (int i = 0; i < m; i++)
	{
		ull tempX, tempY;
		cin >> tempX >> tempY;
		blacks.insert((tempX << 32) + tempY);
	}

	dfs(blacks, whites, 0, n, n);

	cout << whites.size() << '\n';
	return 0;
}