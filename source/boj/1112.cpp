#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int x, b;
	cin >> x >> b;
	if (x == 0)
	{
		cout << 0 << '\n';
	}
	else
	{
		if (b > 0)
		{
			vector<int> ans;
			if (x < 0)
			{
				cout << '-';
				x = -x;
			}
			while (x > 0)
			{
				ans.push_back(x % b);
				x /= b;
			}
			for (int i = ans.size() - 1; i >= 0; i--)
			{
				cout << ans[i];
			}
			cout << '\n';
		}
		else
		{
			vector<int> ans;
			while (x != 0)
			{
				if (x % b >= 0)
				{
					ans.push_back(x % b);
					x /= b;
				}
				else
				{
					ans.push_back(x % b - b);
					x = x / b + 1;
				}
			}
			for (int i = ans.size() - 1; i >= 0; i--)
			{
				cout << ans[i];
			}
			cout << '\n';
		}
	}

	return 0;
}