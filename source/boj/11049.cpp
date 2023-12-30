#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<ll>sizes;
	int N;
	cin >> N;

	int temp1, temp2;
	cin >> temp1 >> temp2;
	sizes.push_back(temp1);
	sizes.push_back(temp2);

	for (int i = 1; i < N; i++)
	{
		cin >> temp1 >> temp2;
		sizes.push_back(temp2);
	}

	if (N == 1)
	{
		cout << 0 << '\n';
		return 0;
	}
	if (N == 2)
	{
		cout << sizes[0] * sizes[1] * sizes[2] << '\n';
		return 0;
	}

	vector<vector<ll> > dp(N, vector<ll>(N, 0));

	//fuck

	for (int i = 1; i < N; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (j == i - 1)
			{
				dp[i][j] = sizes[i - 1] * sizes[i] * sizes[i + 1];
			}
			else
			{
				ll minMul = 1ll << 40, t = 0;
				while (j + t != i)
				{
					minMul = min(minMul, dp[j + t][j] + dp[i][j + t + 1] + sizes[j] * sizes[j + t + 1] * sizes[i + 1]);
					t++;
				}
				dp[i][j] = minMul;
			}
		}
	}

	cout << dp[N - 1][0] << '\n';

	return 0;
}