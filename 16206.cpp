#include <iostream>
#include <queue>

using namespace std;

struct Compare
{
	bool operator()(int a, int b)
	{
		if (a % 10 != 0 && b % 10 == 0)
		{
			return true;
		}
		if (((a % 10 == 0 && b % 10 == 0) || (a % 10 != 0 && b % 10 != 0)) && a > b)
		{
			return true;
		}
		return false;
	}
};

int main(void)
{
	int N, M;
	cin >> N >> M;
	priority_queue<int, vector<int>, Compare> pq;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		if (temp >= 10)
		{
			pq.push(temp);
		}
	}

	int cnt = 0;
	int i = 0;

	while (M >= 0 && !pq.empty())
	{
		if (pq.top() % 10 == 0 && pq.top() / 10 - 1 <= M)
		{
			cnt += pq.top() / 10;
			M -= (pq.top() / 10 - 1);
			pq.pop();
		}
		else if (pq.top() % 10 == 0)
		{
			cnt += M;
			M = 0;
			break;
		}
		else if (pq.top() % 10 != 0 && pq.top() / 10 <= M)
		{
			cnt += pq.top() / 10;
			M -= pq.top() / 10;
			pq.pop();
		}
		else
		{
			cnt += M;
			M = 0;
			break;
		}
	}
	cout << cnt << endl;
	return 0;
}