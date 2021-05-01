#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int N, Q;
	cin >> N >> Q;
	vector<int> v(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	int pointer = 0;
	for (int i = 0; i < Q; i++)
	{
		int q1, q2, x;
		cin >> q1 >> q2;
		if (q1 == 1)
		{
			cin >> x;
			v[(q2 + pointer - 1) % N] += x;
		}
		else if (q1 == 2)
		{
			pointer += N;
			pointer -= q2;
			pointer %= N;
		}
		else
		{
			pointer += q2;
			pointer %= N;
		}
	}

	for (int i = pointer; i < N; i++)
	{
		cout << v[i] << ' ';
	}
	for (int i = 0; i < pointer; i++)
	{
		cout << v[i] << ' ';
	}

	cout << '\n';

	return 0;

}