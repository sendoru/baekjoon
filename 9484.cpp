#include <iostream>
#define INF 987654321

using namespace std;

int x[2000];
int y[2000];
int minS, maxS;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout.precision(1);

	int n;
	cin >> n;
	while (n != 0)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> x[i] >> y[i];
		}
		minS = INF, maxS = 0;
		for (int i = 0; i < n - 2; i++)
		{
			for (int j = i + 1; j < n - 1; j++)
			{
				for (int k = j + 1; k < n; k++)
				{
					int s = abs(x[i] * y[j]
							+ x[j] * y[k]
							+ x[k] * y[i]
							- x[j] * y[i]
							- x[k] * y[j]
							- x[i] * y[k]);
					if (s < minS)
						minS = s;
					if (s > maxS)
						maxS = s;
				}
			}
		}
		cout << minS / 2.0 << ' ' << maxS / 2.0 << '\n';
		cin >> n;
	}
	return 0;
}