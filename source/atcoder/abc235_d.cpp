#include <iostream>
#include <vector>
#include <queue>
#include <string>
typedef long long ll;
constexpr int MAX = 1e6 - 1;
using namespace std;

int bfs(int a, int n)
{
	queue<pair<int, int>> q;
	vector<int> visited(MAX + 100, -1);
	visited[1] = 0;
	q.push({ 1, 0 });
	while (!q.empty())
	{
		int curNum = q.front().first, curDist = q.front().second;
		q.pop();
		if (curNum == n)
		{
			return curDist;
		}
		ll nextNum = (ll)curNum * a;
		if (nextNum <= MAX && visited[nextNum] == -1)
		{
			visited[nextNum] = curDist + 1;
			q.push({ nextNum, curDist + 1 });
		}
		if (curNum % 10 != 0)
		{
			nextNum = stoi(to_string(curNum % 10) + to_string(curNum / 10));
			if (nextNum <= MAX && visited[nextNum] == -1)
			{
				visited[nextNum] = curDist + 1;
				q.push({ nextNum, curDist + 1 });
			}
		}
	}

	return -1;
}

int main(void)
{
	int a, n;
	cin >> a >> n;
	cout << bfs(a, n);

	return 0;
}