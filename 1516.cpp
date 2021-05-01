#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void)
{
	vector<int> pre(1001);				// pre[i] := 선행 건물의 갯수
	vector<vector<int>> suc(1001);		// suc[i] := 후행 건물 번호들 모아둔거
	vector<int> time(1001);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> time[i];
		int tempSuc;
		cin >> tempSuc;
		while (tempSuc != -1)
		{
			suc[tempSuc].push_back(i);
			pre[i]++;
			cin >> tempSuc;
		}
	}

	vector<int> result(1001);

	queue<int> q;

	for (int i = 1; i <= N; i++)
	{
		if (!pre[i])
		{
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int n = q.front();
		q.pop();

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
		cout << result[i] + time[i] << '\n';
	}




	return 0;
}