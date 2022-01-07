#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// first는 방문까지 걸리는 횟수, second는 부모 노드
// second가 0이면 루트 노드임을 뜻함
vector<pair<int, int> > v(1000001);

void bfs(queue<int>& q)
{
	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		if (x % 3 == 0 && !v[x / 3].first)
		{
			v[x / 3] = { v[x].first + 1, x };
			q.push(x / 3);
		}
		if (x % 2 == 0 && !v[x / 2].first)
		{
			v[x / 2] = { v[x].first + 1, x };
			q.push(x / 2);
		}
		if(x - 1 > 0 && !v[x - 1].first)
		{
			v[x - 1] = { v[x].first + 1, x };
			q.push(x - 1);
		}

	}
}

int main()
{
	int N;
	cin >> N;
	if (N == 1)
	{
		cout << 0 << '\n';
		cout << 1 << '\n';
		return 0;
	}
	else
	{
		queue<int> q;
		q.push(N);
		bfs(q);
		cout << v[1].first << '\n';
		vector<int> route;
		int cur = 1;
		while (true)
		{
			route.push_back(cur);
			cur = v[cur].second;

			if (cur == N)
			{
				break;
			}
		}

		cout << N << ' ';
		for (int i = route.size() - 1; i >= 0; i--)
		{
			cout << route[i] << ' ';
		}
		cout << '\n';
	}


	return 0;

}

