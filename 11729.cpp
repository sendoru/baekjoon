#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<vector<int>> tree(100001);
	bool check[100001] = { 0, };
	int result[100001] = { 0, };

	queue<int> q;
	int N;
	cin >> N;

	for (int i = 0; i < N - 1; i++)
	{
		int start, end;
		cin >> start >> end;
		tree[start].push_back(end);
		tree[end].push_back(start);
	}

	q.push(1);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 0; i < tree[x].size(); i++)
		{
			int y = tree[x][i];
			if (!check[y])
			{
				q.push(y);
				check[y] = 1;
				result[y] = x;
			}
		}
	}

	for (int i = 2; i <= N; i++)
	{
		cout << result[i] << '\n';
	}
	
	return 0;
}