#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

typedef struct _dot
{
	ll x = 0;
	ll y = 0;
} dot;

int ccw(dot d1, dot d2, dot d3)
{
	ll cross = (d2.x - d1.x) * (d3.y - d1.y) - (d3.x - d1.x) * (d2.y - d1.y);
	if (cross > 0)
	{
		return 1;
	}
	if (cross == 0)
	{
		return 0;
	}
	return -1;
}

int main(void)
{
	int N;
	cin >> N;
	
	vector<dot> buildings(N);
	for (int i = 0; i < N; i++)
	{
		buildings[i].x = i;
		cin >> buildings[i].y;
	}

	int ans = 0;

	for (int i = 0; i < N; i++)
	{
		int cnt = 0;
		dot currentBuilding = buildings[i];
		dot highest;

		highest.x = (ll)i - 1ll;
		highest.y = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			if (ccw(currentBuilding, highest, buildings[j]) == -1)
			{
				highest = buildings[j];
				cnt++;
			}
		}

		highest.x = (ll)i + 1ll;
		highest.y = 0;
		for (int j = i + 1; j < N; j++)
		{
			if (ccw(currentBuilding, highest, buildings[j]) == 1)
			{
				highest = buildings[j];
				cnt++;
			}
		}

		if (ans < cnt)
		{
			ans = cnt;
		}
	}
	
	cout << ans << endl;
}

