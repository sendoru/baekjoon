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
	int ptr1, ptr2, ptr3;
	int ret1, ret2, ret3;
	ll sum, minimum = 1ll << 50;
	for (ptr1 = 0; ptr1 < countofSolutions - 2; ptr1++)
	{
		ptr2 = ptr1 + 1;
		ptr3 = countofSolutions - 1;
		while (ptr2 < ptr3)
		{
			sum = solutions[ptr1] + solutions[ptr2] + solutions[ptr3];
			if (llabs(sum) < minimum)
			{
				ret1 = ptr1;
				ret2 = ptr2;
				ret3 = ptr3;
				minimum = llabs(sum);
			}
			if (sum < 0)
			{
				ptr2++;
			}
			else
			{
				ptr3--;
			}
		}
	}


	cout << solutions[ret1] << ' ' << solutions[ret2] << ' ' << solutions[ret3] << '\n';
	return 0;
}