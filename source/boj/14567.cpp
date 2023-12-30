#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void)
{
	vector<int> pre(1001);				// pre[i] := 선수과목의 갯수
	vector<vector<int>> suc(1001);		// suc[i] := 후수과목 번호들 모아둔거
	vector<int> time(1001, 1);

	int N, M;							// N := 총 과목 갯수, M := 선수 조건의 수
	cin >> N >> M;
	for (int i = 1; i <= M; i++)
	{
		int tempPre, tempSuc;
		cin >> tempPre >> tempSuc;
		suc[tempPre].push_back(tempSuc);
		pre[tempSuc]++;
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
		cout << result[i] + time[i] << ' ';
	}




	return 0;
}