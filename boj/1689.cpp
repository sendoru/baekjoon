#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, maxLines = 0, curLines = 0;
	cin >> n;

	vector<pair<int, int> > lines(2 * n);
	for (int i = 0; i < n; i++)
	{
		cin >> lines[i].first >> lines[i + n].first;
		lines[i].second = 1;
		lines[i + n].second = -1;
	}

	sort(lines.begin(), lines.end());

	for (int i = 0; i < 2 * n; i++)
	{
		curLines += lines[i].second;
		maxLines = max(maxLines, curLines);
	}

	cout << maxLines << '\n';
	return 0;
}