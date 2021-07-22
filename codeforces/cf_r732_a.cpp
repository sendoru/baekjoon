#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, aSum = 0, bSum = 0;
		cin >> n;
		vector<int> a(n + 1), b(n + 1), opI, opJ;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			aSum += a[i];
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> b[i];
			bSum += b[i];
		}
		if (aSum != bSum)
		{
			cout << -1 << '\n';
			continue;
		}
		for (int i = 1; i <= n; i++)
		{
			if (a[i] > b[i])
			{
				for (int j = 0; j < a[i] - b[i]; j++)
				{
					opI.push_back(i);
				}
			}
			else if (a[i] < b[i])
			{
				for (int j = 0; j < b[i] - a[i]; j++)
				{
					opJ.push_back(i);
				}
			}
		}
		cout << opI.size() << '\n';
		for (int i = 0; i < opI.size(); i++)
		{
			cout << opI[i] << ' ' << opJ[i] << '\n';
		}
	}
}