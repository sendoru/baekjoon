#include <iostream>
#include <vector>
using namespace std;
typedef unsigned int uint;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> x(n), y(n), s(n);
		for (int i = 0; i < n; i++)
		{
			cin >> x[i];
		}
		s[0] = x[0];
		for (int i = 1; i < n; i++)
		{
			vector<bool> bitField(31);
			for (int j = 0; j < 30; j++)
			{
				bool curXBit = (x[i] >> j) & 1;
				bool prevSBit = (s[i - 1] >> j) & 1;
				if (prevSBit)
				{
					bitField[j] = prevSBit ^ curXBit;
					y[i] += (bitField[j] << j);
				}
			}
			s[i] = x[i] | y[i];
		}
		for (int i = 0; i < n; i++)
		{
			cout << y[i] << ' ';
		}
		cout << '\n';
	}
}