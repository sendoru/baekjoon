#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main(void)
{
	int n;
	cin >> n;
	vector<vector<vector<ll> > > v(n + 1, vector<vector<ll> >(10, vector<ll>(1 << 10)));
	for (int i = 1; i < 10; i++)
	{
		v[1][i][1ll << i] = 1;
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int size = 1; size <= 10; size++)
			{
				for (int start = 0; start < 10 - size + 1; start++)
				{
					int bitField = 0;
					for (int k = start; k < start + size; k++)
					{
						bitField += 1 << k;
					}
					if (j - 1 > 0)
					{
						v[i + 1][j - 1][bitField | (1 << (j - 1))] += v[i][j][bitField];
						v[i + 1][j - 1][bitField | (1 << (j - 1))] %= 1000000000;
					}
					if (j + 1 < 10)
					{
						v[i + 1][j + 1][bitField | (1 << (j + 1))] += v[i][j][bitField];
						v[i + 1][j + 1][bitField | (1 << (j + 1))] %= 1000000000;
					}
				}
			}
		}
	}

	ll ans = 0;
	for (int i = 0; i < 10; i++)
	{
		ans += v[n][i][(1 << 10) - 1];
	}
	cout << ans % 1000000000 << '\n';
	return 0;
}