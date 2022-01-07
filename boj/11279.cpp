#include <iostream>
#include <queue>

using namespace std;

int execution(priority_queue<int>& pq, int x)
{
	if (x == 0)
	{
		if (pq.size() == 0)
		{
			cout << 0 << '\n';
		}
		else
		{
			cout << pq.top() << '\n';
			pq.pop();
		}
		return 0;
	}
	else
	{
		pq.push(x);
		return 0;
	}
}

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, tmp;
	priority_queue<int> pq;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		execution(pq, tmp);
	}
	return 0;
}