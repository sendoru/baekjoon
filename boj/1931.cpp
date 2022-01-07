#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

bool compareByEndTime(vector<int> x, vector<int> y)
{
	if (x[1] == y[1]) return x[0] < y[0];
	return x[1] < y[1];
}

int main(void)
{
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<vector<int>> conferences;
	int tempStart = 0, tempEnd = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> tempStart >> tempEnd;
		conferences.push_back({tempStart, tempEnd });
	}

	sort(conferences.begin(), conferences.end(), compareByEndTime);

	int conferencesCount = 1;
	int endTime = conferences[0][1];

	for (int i = 1; i < conferences.size(); i++)
	{
		if (conferences[i][0] >= endTime)
		{
			endTime = conferences[i][1];
			conferencesCount += 1;
		}
	}

	cout << conferencesCount << endl;

	return 0;
}