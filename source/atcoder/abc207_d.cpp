#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#define PI 3.1415926535897932
using namespace std;

int distanceSquare(pair<int, int> a, pair<int, int>b)
{
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

double arg(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
	{
		if (a.first >= b.first)
		{
			return PI / 2;
		}
		else
		{
			return -PI / 2;
		}
	}
	return atan((a.first - b.first) / (a.second - b.second));
}

int ccw(pair<int, int> d1, pair<int, int> d2, pair<int, int> d3)
{
	int x1 = d1.first, y1 = d1.second,
		x2 = d2.first, y2 = d2.second,
		x3 = d3.first, y3 = d3.second;
	int tmp = (x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1);
	if (tmp > 0)	return 1;
	if (tmp == 0)	return 0;
	if (tmp < 0)	return -1;
}


int main(void)
{
	int n;
	cin >> n;
	vector<pair<int, int>> s(n);
	vector<pair<int, int>> t(n);
	for (int i = 0; i < n; i++)
	{
		cin >> s[i].first >> s[i].second;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> t[i].first >> t[i].second;
	}

	multiset<multiset<int>> sDistancesSet;
	multiset<multiset<int>> tDistancesSet;
	vector<multiset<int>> sDistancesVec(n);
	vector<multiset<int>> tDistancesVec(n);
	vector<int> mapStoT(n);
	set<int> mapped;


	for (int i = 0; i < n; i++)
	{
		multiset<int> tempSetS;
		multiset<int> tempSetT;
		for (int j = 0; j < n; j++)
		{
			tempSetS.insert(distanceSquare(s[i], s[j]));
			tempSetT.insert(distanceSquare(t[i], t[j]));
		}
		sDistancesSet.insert(tempSetS);
		tDistancesSet.insert(tempSetT);
		sDistancesVec[i] = tempSetS;
		tDistancesVec[i] = tempSetT;
	}

	if (sDistancesSet != tDistancesSet)
	{
		cout << "No" << '\n';
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (sDistancesVec[i] == tDistancesVec[j] && mapped.find(j) == mapped.end())
			{
				mapped.insert(j);
				mapStoT[i] = j;
				break;
			}
		}
	}

	for (int i = 2; i < n; i++)
	{
		if (ccw(s[0], s[i], s[i - 1]) != ccw(t[mapStoT[0]], t[mapStoT[i]], t[mapStoT[i - 1]]))
		{
			break;
		}
		if (i == n - 1)
		{
			cout << "Yes" << '\n';
			return 0;
		}
	}

	mapped.clear();
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = n - 1; j >= 0; j--)
		{
			if (sDistancesVec[i] == tDistancesVec[j] && mapped.find(j) == mapped.end())
			{
				mapped.insert(j);
				mapStoT[i] = j;
				break;
			}
		}
	}

	for (int i = 2; i < n; i++)
	{
		if (ccw(s[0], s[i], s[i - 1]) != ccw(t[mapStoT[0]], t[mapStoT[i]], t[mapStoT[i - 1]]))
		{
			cout << "No" << '\n';
			return 0;
		}
	}

	cout << "Yes" << '\n';
	return 0;
}