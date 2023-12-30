#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

pair<int, int> bfs(int start, vector<map<int, int> >& tree, vector<int>& distance)
{
	queue<pair<int, int> > q;
	q.push({ start, 0 });
	int curNode = start;
	int maxDistance = 0;
	int farthestNode = 0;
	distance[curNode] = 0;

	while (!q.empty())
	{
		int curNode = q.front().first;
		int curDistance = q.front().second;
		q.pop();

		for (auto iter = tree[curNode].begin(); iter != tree[curNode].end(); iter++)
		{
			int nextNode = (*iter).first;
			int nextCost = (*iter).second;
			if (distance[nextNode] == -1)
			{
				distance[nextNode] = curDistance + nextCost;
				if (distance[nextNode] > maxDistance)
				{
					farthestNode = nextNode;
					maxDistance = distance[nextNode];
				}
				q.push({ nextNode, distance[nextNode] });
			}
		}
	}

	return { farthestNode, maxDistance };
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<map<int, int> > tree(n + 1, map<int, int>());
	vector<int> distance(n + 1, -1);

	for (int i = 0; i < n; i++)
	{
		int start, end, cost;
		cin >> start;
		cin >> end;
		while (end != -1)
		{
			cin >> cost;
			tree[start].insert({ end ,cost });
			tree[end].insert({ start, cost });
			cin >> end;
		}
	}

	int farthestNode = bfs(1, tree, distance).first;
	fill(distance.begin(), distance.end(), -1);
	int maxDistance = bfs(farthestNode, tree, distance).second;
	cout << maxDistance << '\n';

	return 0;
}