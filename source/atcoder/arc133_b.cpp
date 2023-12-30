#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> p(n), q(n), pInv(n + 1), qInv(n + 1);
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
		pInv[p[i]] = i;
	}

	for (int i = 0; i < n; i++)
	{
		cin >> q[i];
		qInv[q[i]] = i;
	}
	
	vector<pair<ld, ld>> edges;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; i * j <= n; j++)
		{
			edges.push_back({ i, i * j });
		}
	}

	for (int i = 0; i < edges.size(); i++)
	{
		edges[i].first = pInv[edges[i].first];
		edges[i].second = qInv[edges[i].second];
		edges[i].first -= (edges[i].second - edges[i].first) * 1e-8;
	}

	sort(edges.begin(), edges.end());

	vector<ld> lisStack;
	for (int i = 0; i < edges.size(); i++)
	{
		if (lisStack.empty() || lisStack.back() < edges[i].second)
		{
			lisStack.push_back(edges[i].second);
		}
		else
		{
			auto iter = lower_bound(lisStack.begin(), lisStack.end(), edges[i].second);
			*iter = edges[i].second;
		}
	}

	cout << lisStack.size();

	return 0;
}