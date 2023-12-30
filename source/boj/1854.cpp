#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> solve(vector<vector<pair<ll, ll>>>& adjList, int k)
{
	vector<ll> ret(adjList.size(), -1);
	vector<priority_queue<ll>> dists(adjList.size());
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
	dists[1].push(0);
	pq.push({ 0, 1 });

	while (!pq.empty())
	{
		ll curNode = pq.top().second, curDist = pq.top().first;
		pq.pop();
		for (auto edge : adjList[curNode])
		{
			ll nextNode = edge.first, nextDist = curDist + edge.second;
			if (dists[nextNode].size() < k)
			{
				dists[nextNode].push(nextDist);
				pq.push({ nextDist, nextNode });
			}
			else if (dists[nextNode].top() > nextDist)
			{
				dists[nextNode].pop();
				dists[nextNode].push(nextDist);
				pq.push({ nextDist, nextNode });
			}
		}
	}

	for (int i = 1; i < adjList.size(); i++)
	{
		if (dists[i].size() == k)
		{
			ret[i] = dists[i].top();
		}
	}
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<pair<ll, ll>>> adjList(n + 1);
	for (int i = 0; i < m; i++)
	{
		int s, e, c;
		cin >> s >> e >> c;
		adjList[s].push_back({ e, c });
	}

	auto ans = solve(adjList, k);

	for (int i = 1; i <= n; i++)
	{
		cout << ans[i] << '\n';
	}

	return 0;
}