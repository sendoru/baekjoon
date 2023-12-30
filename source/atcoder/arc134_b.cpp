#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <algorithm>
typedef long long ll;
using namespace std;

struct comp
{
	bool operator() (pair<char, int>& a, pair<char, int>& b)
	{
		if (a.first == b.first) return a.second < b.second;
		return a.first > b.first;
	}
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	string s;
	cin >> n >> s;
	int lEnd = 0, rEnd = n - 1;

	priority_queue<pair<char, int>, vector<pair<char, int>>, comp> pq;
	for (int i = 0; i < s.length(); i++)
	{
		pq.push({ s[i], i });
	}


	while (lEnd < rEnd)
	{
		while (!pq.empty() && pq.top().second < lEnd)
			pq.pop();

		if (pq.empty() || pq.top().first >= s[lEnd])
		{
			lEnd++;
			continue;
		}

		while (!pq.empty() && (pq.top().second > rEnd || pq.top().second < lEnd))
			pq.pop();

		if (pq.empty())
			break;

		if (pq.top().first >= s[lEnd])
		{
			lEnd++;
			continue;
		}
		
		rEnd = pq.top().second;
		if (lEnd >= rEnd)
			break;
		swap(s[lEnd], s[rEnd]);
		rEnd--;
		lEnd++;
		pq.pop();
	}


	cout << s;
	return 0;
}

/*
aaaaaaabbbbcbbbc
aaaaaaabbbbcbbbc

effwpnwipsusiwkzo
effwpnwipsusiwkzo
*/