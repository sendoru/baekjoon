#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		priority_queue<pair<int, int>> pq;
		for (int i = 1; i <= n; i++)
		{
			int a;
			cin >> a;
			if (a > 0) pq.push(make_pair(a, i));
		}
		int maxTalk = 0;
		vector<pair<int, int>> talks;
		while (pq.size() >= 2)
		{
			auto p1 = pq.top();
			pq.pop();
			auto p2 = pq.top();
			pq.pop();
			maxTalk++;
			talks.push_back({ p1.second, p2.second });
			if (p1.first >= 2) pq.push(make_pair(p1.first - 1, p1.second));
			if (p2.first >= 2) pq.push(make_pair(p2.first - 1, p2.second));
		}

		cout << maxTalk << '\n';
		for (auto elem : talks)
			cout << elem.first << ' ' << elem.second << '\n';
	}

	return 0;
}