#include <iostream>
#include <unordered_set>

using namespace std;

int main(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	unordered_multiset<int> A;
	int M;
	long long int sum = 0;
	long long int xorSum = 0;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int q1, q2;
		cin >> q1;
		if (q1 == 1 || q1 == 2)
		{
			cin >> q2;
			if (q1 == 1)
			{
				A.insert(q2);
				sum += q2;
				xorSum ^= q2;
			}
			else
			{
				if (A.find(q2) != A.end())
				{
					A.erase(A.find(q2));
					sum -= q2;
					xorSum ^= q2;
				}
			}
		}
		else if (q1 == 3)
		{
			cout << sum << '\n';
		}
		else
		{
			cout << xorSum << '\n';
		}
	}

	return 0;
}