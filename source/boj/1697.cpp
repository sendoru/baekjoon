#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int k, queue<int>& q, vector<int>& visit, vector<int>& count)
{

	int n;

	while (!q.empty())
	{
		n = q.front();
		q.pop();

		if (n + 1 >= 0 && n + 1 <= 100000)
		{
			if (visit[n + 1] == 0)
			{
				visit[n + 1] = visit[n] + 1;
				count[n + 1] = 1;
				q.push(n + 1);
			}
			else if (visit[n + 1] == visit[n] + 1)
			{
				count[n + 1] += 1;
				q.push(n + 1);
			}

		}
		if (n - 1 >= 0 && n - 1 <= 100000)
		{
			if (visit[n - 1] == 0)
			{
				visit[n - 1] = visit[n] + 1;
				count[n - 1] = 1;
				q.push(n - 1);
			}
			else if (visit[n - 1] == visit[n] + 1)
			{
				count[n - 1] += 1;
				q.push(n - 1);
			}


		}
		if (n * 2 >= 0 && n * 2 <= 100000)
		{
			if (visit[n * 2] == 0)
			{
				visit[n * 2] = visit[n] + 1;
				count[n * 2] = 1;
				q.push(n * 2);
			}
			else if (visit[n * 2] == visit[n] + 1)
			{
				count[n * 2] += 1;
				q.push(n * 2);
			}


		}
	}
}

int main(void)
{
	int N, K;
	cin >> N >> K;
	vector<int> visit(100001);
	vector<int> count(100001);
	visit[N] = 1;
	count[N] = 1;
	queue<int> q;
	q.push(N);
	bfs(K, q, visit, count);
	int result = 0;
	if (N >= K)
	{
		cout << N - K << endl;
		cout << 1 << endl;
		return 0;
	}
	cout << visit[K] - 1 << endl;
	cout << count[K] << endl;
	return 0;
}