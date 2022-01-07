#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int n, xorSum = 0, cntNot1 = 0, maxRocks = 0;
	cin >> n;
	vector<int> rocks(n);
	for (int i = 0; i < n; i++)
	{
		cin >> rocks[i];
		if (rocks[i] > 1)
			cntNot1++;
		xorSum ^= rocks[i];
		maxRocks = max(maxRocks, rocks[i]);
	}
	
	if (cntNot1 <= 1)
	{
		if (maxRocks == 1 && rocks.size() % 2 == 1)
		{
			cout << "cubelover";
			return 0;
		}
		else
		{
			cout << "koosaga";
			return 0;
		}
	}

	cout << (xorSum == 0 ? "cubelover" : "koosaga");
	return 0;
}