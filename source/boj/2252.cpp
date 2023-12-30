#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void)
{
	// pre[i] := i번 문제보다 먼저 푸는 게 좋은 문제들의 갯수
	vector<int> pre(32001);
	// suc[i] := i번 문제 이후에 풀면 좋은 문제들의 번호들
	vector<vector<int> > suc(32001);

	// N := 총 문제, M := 정보의 갯수
	int N, M;					
	cin >> N >> M;

	for (int i = 1; i <= M; i++)
	{
		int tempPre, tempSuc;
		cin >> tempPre >> tempSuc;
		suc[tempPre].push_back(tempSuc);
		pre[tempSuc]++;
	}

	vector<int> result(32001);

	priority_queue<int, vector<int>, greater<int> > pq;

	for (int i = 1; i <= N; i++)
	{
		if (!pre[i])
		{
			pq.push(i);
		}
	}

	while (!pq.empty())
	{
		int n = pq.top();
		pq.pop();

		cout << n << ' ';

		for (int there : suc[n])
		{
			pre[there]--;
			if (pre[there] == 0)
			{
				pq.push(there);
			}
		}
	}

	return 0;
}