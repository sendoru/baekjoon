#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;



int main(void)
{
	ios::sync_with_stdio(false);

	vector<int> pre(10001);				// pre[i] := 선행 작업의 갯수
	for (int i = 0; i <= 10000; i++)
	{
		pre[i] = 0;
	}
	vector<vector<int> > suc(10001);	// suc[i] := 후행 작업 번호들 모아둔거
	for (int i = 0; i <= 10000; i++)
	{
		suc[i] = {};
	}
	vector<int> time(10001);
	for (int i = 0; i <= 10000; i++)
	{
		time[i] = 0;
	}
	vector<int> result(10001);
	for (int i = 0; i <= 10000; i++)
	{
		result[i] = 0;
	}
	queue<int> q;

	int N;
	int tempPre;
	int tempCount;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> time[i] >> tempCount;
		if (tempCount == 0)
		{
			q.push(i);
			continue;
		}
		for (int j = 0; j < tempCount; j++)
		{
			cin >> tempPre;
			suc[tempPre].push_back(i);
			pre[i]++;
		}
	}

	while (!q.empty())
	{
		int n = q.front();
		q.pop();

		bool flag = true;

		for (int i = 0; i <= N; i++)
		{
			if (pre[i] != 0)
			{
				flag = false;
			}
		}

		if (flag)
		{
			break;
		}

		for (int i = 0; i < suc[n].size(); i++)
		{
			result[suc[n][i]] = max(result[suc[n][i]], result[n] + time[n]);
			pre[suc[n][i]]--;
			if (pre[suc[n][i]] == 0)
			{
				q.push(suc[n][i]);
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		result[i] += time[i];
	}

	int maximum = 0;
	for (int i = 1; i <= N; i++)
	{
		if (result[i] > maximum)
		{
			maximum = result[i];
		}
	}

	cout << maximum << '\n';
	return 0;
}
