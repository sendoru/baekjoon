#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
constexpr int INF = 0x3fffffff;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	int minDist = INF;
	vector<int> midNode;

	// 1-3-2, 1-4-2, ... 1-n-2까지의 거리 모두 알아내기
	for (int i = 3; i <= n; i++)
	{
		int d1i, d2i;
		cout << "? " << 1 << ' ' << i << endl;
		cin >> d1i;
		cout << "? " << 2 << ' ' << i << endl;
		cin >> d2i;

		if (d1i + d2i < minDist)
		{
			minDist = d1i + d2i;
			midNode.clear();
			midNode.push_back(i);
		}
		else if (d1i + d2i == minDist)
		{
			midNode.push_back(i);
		}
	}

	if (minDist != 3)
	{
		cout << "! " << minDist << endl;
	}

	else
	{
		if (midNode.size() != 2)
		{
			cout << "! " << 1 << endl;
		}
		else
		{
			int lastDist;
			cout << "? " << midNode[0] << ' ' << midNode[1] << endl;
			cin >> lastDist;
			if (lastDist == 1)
			{
				cout << "! " << 3 << endl;
			}
			else
			{
				cout << "! " << 1 << endl;
			}
		}
	}

	return 0;
}