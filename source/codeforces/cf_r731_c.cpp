#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		int k, n, m;
		cin >> k >> n >> m;
		vector<int> mono(n), poly(m), seq;
		for (int i = 0; i < n; i++)
		{
			cin >> mono[i];
		}
		for (int i = 0; i < m; i++)
		{
			cin >> poly[i];
		}
		int monoIndex = 0, polyIndex = 0;
		while (monoIndex != n || polyIndex != m)
		{
			if (monoIndex != n && mono[monoIndex] == 0)
			{
				seq.push_back(0);
				k++;
				monoIndex++;
				continue;
			}
			if (polyIndex != m && poly[polyIndex] == 0)
			{
				seq.push_back(0);
				k++;
				polyIndex++;
				continue;
			}
			if (polyIndex == m || (monoIndex != n && mono[monoIndex] <= poly[polyIndex]))
			{
				if (k < mono[monoIndex])
				{
					break;
				}
				else
				{
					seq.push_back(mono[monoIndex]);
					monoIndex++;
					continue;
				}
			}
			if (monoIndex == n || (polyIndex != m && mono[monoIndex] >=poly[polyIndex]))
			{
				if (k < poly[polyIndex])
				{
					break;
				}
				else
				{
					seq.push_back(poly[polyIndex]);
					polyIndex++;
					continue;
				}
			}
		}
		if (seq.size() == n + m)
		{
			for (int elem : seq)
			{
				cout << elem << ' ';
			}
			cout << '\n';
		}
		else
		{
			cout << -1 << '\n';
		}
	}
}