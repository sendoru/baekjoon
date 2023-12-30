#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#define DEBUG

using namespace std;
typedef long long ll;
typedef long double ld;
constexpr ll INF = 1e14;

ll solve(vector<vector<pair<ll, ll>>>& adjList, ll m)
{
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
	pq.push({ 0, 1 });
	vector<ll> dists(adjList.size(), INF);
	
	while (!pq.empty())
	{
		auto curDist = pq.top().first, curNode = pq.top().second;
		pq.pop();

		if (dists[curNode] < curDist)
			continue;


		for (auto elem : adjList[curNode])
		{
			// nextDist: (curDist 이상이면서 m으로 나눈 나머지가 i인 제일 작은 정수) + 1
			ll nextDist = (curDist / m) * m + elem.first;
			if (nextDist < curDist)
				nextDist += m;
			nextDist++;

			ll nextNode = elem.second;
			if (nextDist < dists[nextNode])
			{
				dists[nextNode] = nextDist;
				pq.push({ nextDist, nextNode });
			}
		}
	}


	return dists.back();
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<vector<pair<ll, ll>>> adjList(n + 1);
	for (ll i = 0; i < m; i++)
	{
		ll s, e;
		cin >> s >> e;
		adjList[s].push_back(make_pair(i, e));
		adjList[e].push_back(make_pair(i, s));
	}

	cout << solve(adjList, m);

	return 0;
}