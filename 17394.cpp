#include <iostream>
#include <queue>
#define INF 98765432

using namespace std;

bool isPrime[1100001] = { 0, };
int visit[1100001] = { 0, };

void eratosthenes(bool* isPrime)
{
	isPrime[0] = 0;
	isPrime[1] = 0;
	for (int i = 3; i <= 1100000; i++)
	{
		isPrime[i] = 1;
	}
	for (int i = 2; i <= 10000; i++)
	{
		if (isPrime[i] == 1)
		{
			for (int j = i * 2; i * j <= 1100000; j += i)
			{
				isPrime[j] = 0;
			}
		}
	}
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	eratosthenes(isPrime);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int N, A, B;
		cin >> N >> A >> B;

		for (int i = 0; i <= 1100000; i++)
		{
			visit[i] = 0;
		}

		queue<pair<int, int>> q;
		q.push({ N, 0 });
		visit[N] = 1;
		bool flag = true;
		int n, m;

		while (!q.empty())
		{
			n = q.front().first;
			m = q.front().second;
			q.pop();

			if (A <= n && n <= B && isPrime[n])
			{
				cout << m << '\n';
				flag = false;
				break;
			}

			if (visit[n / 2] == 0)
			{
				visit[n / 2] = 1;
				q.push({ n / 2,  m + 1 });
			}
			if (visit[n / 3] == 0)
			{
				visit[n / 3] = 1;
				q.push({ n / 3, m + 1 });
			}
			if (n + 1 <= 1100000 && visit[n + 1] == 0)
			{
				visit[n + 1] = 1;
				q.push({ n + 1, m + 1 });
			}
			if (n - 1 >= 0 && visit[n - 1] == 0)
			{
				visit[n - 1] = 1;
				q.push({ n - 1, m + 1 });
			}
		}

		if (flag)
		{
			cout << -1 << '\n';
		}
		
	}

	return 0;
}
