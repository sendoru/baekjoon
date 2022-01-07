#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}

void bfs(int k, deque<int>& q, vector<int>& visit)
{

	int n = 1;
	bool flag;

	while (!q.empty())
	{
		flag = true;
		n = q.front();
		q.pop_front();
		if (n * 2 >= 0 && n * 2 <= 100000 && visit[n * 2] == -1)
		{
			visit[n * 2] = visit[n];
			q.push_front(n * 2);
		}
		if (n + 1 >= 0 && n + 1 <= 100000 && visit[n + 1] == -1)
		{
			visit[n + 1] = visit[n] + 1;
			q.push_back(n + 1);
		}
		if (n - 1 >= 0 && n - 1 <= 100000 && visit[n - 1] == -1)
		{
			visit[n - 1] = visit[n] + 1;
			q.push_back(n - 1);
		}
	}
}

int main(void)
{
	int N, K;
	cin >> N >> K;
	vector<int> visit(100001);
	for (int i = 0; i < 100001; i++)
	{
		visit[i] = -1;
	}
	visit[N] = 1;
	deque<int> q;
	q.push_back(N);
	bfs(K, q, visit);
	int result = 0;
	cout << visit[K] - 1 << endl;
	return 0;
}