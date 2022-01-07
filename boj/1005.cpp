#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void)
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		vector<int> pre(1001);				// pre[i] := 선행 건물의 갯수
		vector<vector<int>> suc(1001);		// suc[i] := 후행 건물 번호들 모아둔거
		vector<int> time(1001);

		int N, K;
		cin >> N >> K;
		for (int i = 1; i <= N; i++)
		{
			cin >> time[i];
		}

		for (int i = 0; i < K; i++)
		{
			int tempPre, tempSuc;
			cin >> tempPre >> tempSuc;
			suc[tempPre].push_back(tempSuc);
			pre[tempSuc]++;
		}

		int W;
		cin >> W;

		vector<int> result(1001);

		queue<int> q;

		for (int i = 1; i <= N; i++)
		{
			if (!pre[i])
			{
				q.push(i);
			}
		}

		while (pre[W] > 0)
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
		cout << result[W] + time[W] << '\n';
	}

	return 0;
}