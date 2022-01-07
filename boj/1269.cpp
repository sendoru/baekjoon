#include <iostream>
#include <unordered_set>

using namespace std;

int main(void)
{
	int N, M, cnt = 0, temp;
	cin >> N >> M;
	unordered_set<int> A, B;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		A.insert(temp);
	}

	for (int i = 0; i < M; i++)
	{
		cin >> temp;
		B.insert(temp);
	}

	for (const auto& elem : A)
	{
		if (B.find(elem) != B.end())
		{
			cnt++;
		}
	}

	cout << A.size() + B.size() - (2 * cnt) << endl;
}