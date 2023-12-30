#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		priority_queue<int, vector<int>, greater<int>> pq;
		vector<int> ans;
		int h = 1;
		int n;
		cin >> n;

		for (int j = 0; j < n; j++)
		{
			int c;
			cin >> c;
			pq.push(c);
			h = min(pq.top(), (int)pq.size());
			while (pq.top() < pq.size())
			{
				pq.pop();
				h = min(pq.top(), (int)pq.size());
			}
			ans.push_back(h);
		}
		cout << "Case #" << i << ": ";
		for (int elem : ans)
			cout << elem << ' ';
		cout << '\n';
	}
	return 0;
}