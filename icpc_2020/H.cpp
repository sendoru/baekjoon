#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
using namespace std;
bool possible = false;

vector<pair<int, int>> bfs(vector<vector<pair<int, int>>>& graph, vector<pair<int, int>>& parents, vector<int>& roots, int root)
{
	int n = graph.size() - 1;
	queue<pair<int, int>> q;
	parents[root].first = root;
	parents[root].second = root;
	roots[root] = root;
	q.push({ root, 1 });
	while (!q.empty())
	{
		int curNode = q.front().first, curSign = q.front().second;
		q.pop();
		bool finished = false;
		for (auto elem : graph[abs(curNode)])
		{
			int nextNode = elem.first, nextSign = curSign * elem.second;
			if (nextSign == 1)
			{
				if (parents[nextNode].first == 0)
				{
					roots[nextNode] = root;
					parents[nextNode].first = curNode;
					q.push({ nextNode, nextSign });
				}
			}
			else
			{
				if (parents[nextNode].second == 0)
				{
					roots[nextNode] = root;
					parents[nextNode].second = curNode;
					q.push({ -nextNode, nextSign });
				}
			}
			if (parents[nextNode].first != 0 && parents[nextNode].second != 0 && nextNode != root)
			{
				finished = true;
				break;
			}
		}

		if (finished)
		{
			possible = true;
			break;
		}
	}

	return parents;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> graph(n + 1);
	vector<pair<int, int>> parents(n + 1);
	vector<int> roots(n + 1);
	for (int i = 0; i < m; i++)
	{
		int s, e, c;
		cin >> s >> e >> c;
		graph[s].push_back({ e, c });
		graph[e].push_back({ s, c });
	}

	for (int i = 1; i <= n; i++)
	{
		if (parents[i].first == 0 && parents[i].second == 0)
		{
			bfs(graph, parents, roots, i);
		}
		if (possible)
		{
			break;
		}
	}

	int negVertex = 0;
	for (int i = 1; i <= n; i++)
	{
		if (roots[i] == i) continue;
		if (parents[i].first != 0 && parents[i].second != 0)
		{
			negVertex = i;
			break;
		}
	}

	if (!possible)
	{
		cout << -1;
		return 0;
	}

	deque<int> ans;
	ans.push_back(negVertex);
	int curNode = parents[negVertex].first;
	while (abs(curNode) != roots[negVertex])
	{
		if (curNode > 0)
		{
			ans.push_back(curNode);
			curNode = parents[curNode].first;
		}
		else
		{
			ans.push_back(-curNode);
			curNode = parents[-curNode].second;
		}
	}
	ans.push_back(roots[negVertex]);
	curNode = parents[negVertex].second;
	while (abs(curNode) != roots[negVertex])
	{
		if (curNode > 0)
		{
			ans.push_front(curNode);
			curNode = parents[curNode].first;
		}
		else
		{
			ans.push_front(-curNode);
			curNode = parents[-curNode].second;
		}
	}
	ans.push_front(roots[negVertex]);
	while (ans[1] == ans[ans.size() - 2])
	{
		ans.pop_back();
		ans.pop_front();
	}
	ans.pop_front();

	cout << 1 << '\n';
	cout << ans.size() << '\n';
	for (auto elem : ans)
	{
		cout << elem << '\n';
	}

	

	return 0;

	

}