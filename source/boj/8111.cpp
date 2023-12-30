#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
typedef long long ll;
using namespace std;

string solve(int n)
{
	if (n == 1) return "1";
	// 나머지가 i일때, first는 1의 자릿수, second는 1의 자리를 떼어 버렸을 때 나머지
	vector<pair<int, int>> v(n, { 0, -1 });
	v[1].first = 1;
	v[1].second = -2;
	// 1의 자릿수, 나머지
	queue<pair<int, int>> q;
	q.push({ 1, 1 });
	while (!q.empty())
	{
		int curRem = q.front().second;
		q.pop();
		if (v[(10 * curRem) % n].second == -1)
		{
			v[(10 * curRem) % n].first = 0;
			v[(10 * curRem) % n].second = curRem;
			q.push({ 0, (10 * curRem) % n });
		}
		if (v[(10 * curRem + 1) % n].second == -1)
		{
			v[(10 * curRem + 1) % n].first = 1;
			v[(10 * curRem + 1) % n].second = curRem;
			q.push({ 1, (10 * curRem + 1) % n });
		}
	}

	if (v[0].second == -1)
	{
		return "BRAK";
	}
	else
	{
		string ret;
		int curIdx = 0;
		while (curIdx != -2)
		{
			ret += v[curIdx].first + '0';
			curIdx = v[curIdx].second;
		}
		reverse(ret.begin(), ret.end());
		return ret;
	}
}

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout << solve(n) << '\n';
	}

	return 0;
}