#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int N, temp;
	cin >> N;

	vector<int> P;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		P.push_back(temp);
	}

	sort(P.begin(), P.end());

	int ref = 0;
	for (int i = 0; i < N; i++)
	{
		ref += P[i] * (N - i);
	}

	cout << ref << endl;

	return 0;
}