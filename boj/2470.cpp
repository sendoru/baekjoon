#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int countofSolutions;
	cin >> countofSolutions;

	vector<ll> solutions(countofSolutions);

	for (int i = 0; i < countofSolutions; i++)
	{
		cin >> solutions[i];
	}

	sort(solutions.begin(), solutions.end());
	int ptr1 = 0, ptr2 = countofSolutions - 1;
	int ret1 = ptr1, ret2 = ptr2;
	ll sum, minimum = 1ll << 50;
	while (ptr1 < ptr2)
	{
		sum = solutions[ptr1] + solutions[ptr2];
		if (llabs(sum) < minimum)
		{
			ret1 = ptr1;
			ret2 = ptr2;
			minimum = llabs(sum);
		}
		if (sum < 0)
		{
			ptr1++;
		}
		else
		{
			ptr2--;
		}
	}

	cout << solutions[ret1] << ' ' << solutions[ret2] << '\n';
	return 0;
}