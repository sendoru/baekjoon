#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

int bfs(vector<vector<bool>>& graph, vector<int>& init)
{
	vector<int> target = { 1,2,3,4,5,6,7,8 };
	set<vector<int>> visited;
	visited.insert(init);
	queue<pair<vector<int>, int>> q;
	q.push(make_pair(init, 0));
	while (!q.empty())
	{
		vector<int> curState = q.front().first;
		int curMove = q.front().second;
		if (curState == target) return curMove;
		q.pop();
		int emptyNode = 45;
		for (int elem : curState) emptyNode -= elem;
		for (int i = 0; i < 8; i++)
		{
			if (graph[curState[i]][emptyNode])
			{
				auto nextState = curState;
				nextState[i] = emptyNode;
				if (visited.find(nextState) == visited.end())
				{
					visited.insert(nextState);
					q.push(make_pair(nextState, curMove + 1));
				}
			}
		}
	}

	return -1;
}

int main(void)
{
	int m;
	cin >> m;
	vector<vector<bool>> graph(10, vector<bool>(10));
	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;
		graph[s][e] = true;
		graph[e][s] = true;
	}

	vector<int> init(8);
	for (int i = 0; i < 8; i++) cin >> init[i];

	cout << bfs(graph, init);
	return 0;
}