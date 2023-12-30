#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int r, c;
	cin >> r >> c;
	vector<vector<int> > v(r, vector<int>(c));

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> v[i][j];
		}
	}

	if (r & 1)
	{
		for (int i = 0; i < r / 2; i++)
		{
			for (int j = 0; j < c - 1; j++)
			{
				cout << 'R';
			}
			cout << 'D';
			for (int j = 0; j < c - 1; j++)
			{
				cout << 'L';
			}
			cout << 'D';
		}
		for (int i = 0; i < c - 1; i++)
		{
			cout << 'R';
		}
	}
	else if (c & 1)
	{
		for (int i = 0; i < c / 2; i++)
		{
			for (int j = 0; j < r - 1; j++)
			{
				cout << 'D';
			}
			cout << 'R';
			for (int j = 0; j < r - 1; j++)
			{
				cout << 'U';
			}
			cout << 'R';
		}
		for (int i = 0; i < r - 1; i++)
		{
			cout << 'D';
		}
	}

	else
	{
		int minValue = 1001, minR = 0, minC = 0;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if ((i + j) % 2 == 1 && v[i][j] < minValue)
				{
					minValue = v[i][j];
					minR = i;
					minC = j;
				}
			}
		}

		if (minR == r - 1)
		{
			for (int i = 0; i < minC / 2; i++)
			{
				for (int j = 0; j < r - 1; j++)
				{
					cout << 'D';
				}
				cout << 'R';
				for (int j = 0; j < r - 1; j++)
				{
					cout << 'U';
				}
				cout << 'R';
			}
			for (int i = 0; i < r / 2 - 1; i++)
			{
				cout << "RDLD";
			}
			cout << "RD";
			c = c - minC - 1;
			for (int i = 0; i < c / 2; i++)
			{
				cout << 'R';
				for (int j = 0; j < r - 1; j++)
				{
					cout << 'U';
				}
				cout << 'R';
				for (int j = 0; j < r - 1; j++)
				{
					cout << 'D';
				}
			}
		}

		else if (minC == c - 1)
		{
			for (int i = 0; i < minR / 2; i++)
			{
				for (int j = 0; j < c - 1; j++)
				{
					cout << 'R';
				}
				cout << 'D';
				for (int j = 0; j < c - 1; j++)
				{
					cout << 'L';
				}
				cout << 'D';
			}
			for (int i = 0; i < c / 2 - 1; i++)
			{
				cout << "DRUR";
			}
			cout << "DR";
			r = r - minR - 1;
			for (int i = 0; i < r / 2; i++)
			{
				cout << 'D';
				for (int j = 0; j < c - 1; j++)
				{
					cout << 'L';
				}
				cout << 'D';
				for (int j = 0; j < c - 1; j++)
				{
					cout << 'R';
				}
			}
		}

		else if (minR % 2 == 0)
		{
			for (int i = 0; i < minR / 2; i++)
			{
				for (int j = 0; j < c - 1; j++)
				{
					cout << 'R';
				}
				cout << 'D';
				for (int j = 0; j < c - 1; j++)
				{
					cout << 'L';
				}
				cout << 'D';
			}
			r -= minR;
			for (int i = 0; i < minC / 2; i++)
			{
				for (int j = 0; j < r - 1; j++)
				{
					cout << 'D';
				}
				cout << 'R';
				for (int j = 0; j < r - 1; j++)
				{
					cout << 'U';
				}
				cout << 'R';
			}
			for (int i = 0; i < r / 2 - 1; i++)
			{
				cout << "DRDL";
			}
			cout << "DR";
			c = c - minC - 1;
			for (int i = 0; i < c / 2; i++)
			{
				cout << 'R';
				for (int j = 0; j < r - 1; j++)
				{
					cout << 'U';
				}
				cout << 'R';
				for (int j = 0; j < r - 1; j++)
				{
					cout << 'D';
				}
			}
		}

		else if (minC % 2 == 0)
		{
			for (int i = 0; i < minC / 2; i++)
			{
				for (int j = 0; j < r - 1; j++)
				{
					cout << 'D';
				}
				cout << 'R';
				for (int j = 0; j < r - 1; j++)
				{
					cout << 'U';
				}
				cout << 'R';
			}
			c -= minC;
			for (int i = 0; i < minR / 2; i++)
			{
				for (int j = 0; j < c - 1; j++)
				{
					cout << 'R';
				}
				cout << 'D';
				for (int j = 0; j < c - 1; j++)
				{
					cout << 'L';
				}
				cout << 'D';
			}
			for (int i = 0; i < c / 2 - 1; i++)
			{
				cout << "RDRU";
			}
			cout << "RD";
			r = r - minR - 1;

			for (int i = 0; i < r / 2; i++)
			{
				cout << 'D';
				for (int j = 0; j < c - 1; j++)
				{
					cout << 'L';
				}
				cout << 'D';
				for (int j = 0; j < c - 1; j++)
				{
					cout << 'R';
				}
			}
		}


	}

	return 0;
}