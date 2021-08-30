#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
constexpr double INF = 2000000000.;

double calcDist(pair<double, double> a, pair<double, double> b)
{
	return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(12);
	int n;
	cin >> n;
	vector<pair<int, int>> dots(n);
	vector<vector<double>> dist(n, vector<double>(n));
	vector<double> maxDist(n);
	int ansIndex = -1;
	int ansDist = INF;
	for (int i = 0; i < n; i++)
	{
		cin >> dots[i].first >> dots[i].second;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dist[i][j] = calcDist(dots[i], dots[j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			maxDist[i] = max(maxDist[i], dist[i][j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (maxDist[i] <= ansDist)
		{
			ansIndex = i;
			ansDist = maxDist[i];
		}
	}
	cout << dots[ansIndex].first << ' ' << dots[ansIndex].second;
	return 0;
}