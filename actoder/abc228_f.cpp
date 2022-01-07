#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

int main(void)
{
	int h, w, h1, w1, h2, w2;
	cin >> h >> w >> h1 >> w1 >> h2 >> w2;
	vector<vector<ll>> a(h + 1, vector<ll>(w + 1));

	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
			cin >> a[i][j];

	vector<vector<ll>> prefixSum = a;
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			
		}
	}
}