#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		vector<string> original(n + 1), reordered(n);
		vector<ll> strSum(m);
		for (int i = 1; i <= n; i++)
		{
			cin >> original[i];
		}
		for (int i = 1; i <= n - 1; i++)
		{
			cin >> reordered[i];
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				strSum[j] += original[i][j];
			}
		}
		for (int i = 1; i <= n - 1; i++)
		{
			for (int j = 0; j < m; j++)
			{
				strSum[j] -= reordered[i][j];
			}
		}
		for (int i = 0; i < m; i++)
		{
			cout << (char)strSum[i];
		}
		cout << '\n' << flush;
	}
}