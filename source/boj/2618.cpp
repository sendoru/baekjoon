#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
const int INF = 0x3fffffff;
const int MAX = 1002;

int n, w;
int totalLength[MAX][MAX];
int route[MAX][MAX];
pair<int, int> events[MAX];

int taxiDist(pair<int, int> p1, pair<int, int> p2)
{
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int calcMinDistance(int curP1, int curP2)
{
	if (curP1 == w)
	{
		return 0;
	}
	if (curP2 == w)
	{
		return 0;
	}
	if (totalLength[curP1][curP2] != 0)
	{
		return totalLength[curP1][curP2];
	}
	int nextP = max(curP1, curP2) + 1;
	int nextP1Dist = 0;
	int nextP2Dist = 0;
	if (curP1 == 0)
	{
		nextP1Dist = taxiDist({ 1, 1 }, events[nextP]);
	}
	else
	{
		nextP1Dist = taxiDist(events[curP1], events[nextP]);
	}
	if (curP2 == 0)
	{
		nextP2Dist = taxiDist({ n, n }, events[nextP]);
	}
	else
	{
		nextP2Dist = taxiDist(events[curP2], events[nextP]);
	}
	calcMinDistance(nextP, curP2);
	calcMinDistance(curP1, nextP);
	if (totalLength[nextP][curP2] + nextP1Dist < totalLength[curP1][nextP] + nextP2Dist)
	{
		totalLength[curP1][curP2] = totalLength[nextP][curP2] + nextP1Dist;
		route[curP1][curP2] = 1;
	}
	else
	{
		totalLength[curP1][curP2] = totalLength[curP1][nextP] + nextP2Dist;
		route[curP1][curP2] = 2;
	}
	return totalLength[curP1][curP2];
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> n >> w;
	for (int i = 1; i <= w; i++)
	{
		cin >> events[i].first >> events[i].second;
	}

	cout << calcMinDistance(0, 0) << '\n';
	int p1 = 0, p2 = 0;
	for (int i = 1; i <= w; i++)
	{
		cout << route[p1][p2] << '\n';
		if (route[p1][p2] == 1)
		{
			p1 = i;
		}
		else
		{
			p2 = i;
		}
	}

	return 0;
}