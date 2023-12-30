#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(void)
{
	int h, w;
	cin >> h >> w;
	vector<vector<int>> vec(h, vector<int>(w));
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			cin >> vec[i][j];

	bool ans = true;
	for (int i1 = 0; i1 < h; i1++)
	{
		for (int j1 = 0; j1 < w; j1++)
		{
			for (int i2 = i1 + 1; i2 < h; i2++)
			{
				for (int j2 = j1 + 1; j2 < w; j2++)
				{
					if (vec[i1][j1] + vec[i2][j2] > vec[i2][j1] + vec[i1][j2])
					{
						ans = false;
						break;
					}
				}
			}
		}
	}
	cout << (ans ? "Yes" : "No");
	return 0;
}