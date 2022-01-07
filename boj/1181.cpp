#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int countOfA, N, tmp;
	vector<int> As;
	cin >> countOfA;
	for (int i = 0; i < countOfA; i++)
	{
		cin >> tmp;
		As.push_back(tmp);
	}

	sort(As.begin(), As.end());

	cout << As[0] * As[As.size() - 1] << endl;

	return 0;
}