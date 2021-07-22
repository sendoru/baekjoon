#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n, a, b;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	if (n == 1 || (n == 2 && v[1] != v[0]))
	{
		cout << 'A' << '\n';
	}
	else
	{
		if (v[1] == v[0])
		{
			bool flagB = false;
			for (int i = 2; i < n; i++)
			{
				if (v[i] != v[0])
				{
					cout << 'B' << '\n';
					flagB = true;
					break;
				}
			}
			if (!flagB)
			{
				cout << v[0] << '\n';
			}
		}
		else
		{
			if ((v[2] - v[1]) % (v[1] - v[0]) != 0 || (v[1] * v[1] - v[0] * v[2]) % (v[1] - v[0]) != 0)
			{
				cout << 'B' << '\n';
			}
			else
			{
				a = (v[2] - v[1]) / (v[1] - v[0]);
				b = (v[1] * v[1] - v[0] * v[2]) / (v[1] - v[0]);
				bool flagB = false;
				for (int i = 3; i < n; i++)
				{
					if (v[i] != a * v[i - 1] + b)
					{
						cout << 'B' << '\n';
						flagB = true;
						break;
					}
				}
				if (!flagB)
				{
					cout << a * v[n - 1] + b << '\n';
				}
			}
		}
	}

	return 0;
}