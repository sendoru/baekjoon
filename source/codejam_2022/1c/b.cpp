#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <deque>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(void)
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		int n, k;
		cin >> n >> k;
		vector<int> e(n);
		for (auto& elem : e) cin >> elem;

		ll sumOfSquare = 0, sum = 0;
		for (int i = 0; i < e.size(); i++)
		{
			sumOfSquare += e[i] * e[i];
			sum += e[i];
		}

		cout << "Case #" << t << ": ";
		if (sumOfSquare == sum * sum)
		{
			cout << 0;
		}
		else if (sum == 0 || (sumOfSquare - sum * sum) % (2 * sum) != 0)
		{
			if (k == 1)
			{
				cout << "IMPOSSIBLE";
			}
			else
			{
				ll k = (sumOfSquare + sum * sum) / 2;
				cout << k - sum << ' ' << 1 - sum;
				// cout << ' ';
				// cout << sumOfSquare + (k - sum) * (k - sum) + (1 - sum) * (1 - sum) << ' ';
				// cout << (sum + k - sum + 1 - sum) * (sum + k - sum + 1 - sum);
			}
		}
		else
		{
			cout << (sumOfSquare - sum * sum) / (2 * sum);
		}
		cout << '\n';
	}

	return 0;
}