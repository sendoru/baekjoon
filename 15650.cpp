#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// 처음 주어지는 picked는 {}
void pick(int n, vector<int> sortedVector, vector<int>& picked, int toPick)
{
	// 더 고를 게 없으면 고른거 전부 뱉어내기
	if (toPick == 0)
	{
		for (int i = 0; i < picked.size(); i++)
			cout << sortedVector[picked[i]] << ' ';
		cout << '\n';
		return;
	}

	// int smallest = picked.empty() ? 0 : picked.back();

	for (int next = 0; next < n; next++)
	{
		if (find(picked.begin(), picked.end(), next) == picked.end())
		{
			picked.push_back(next);
			pick(n, sortedVector, picked, toPick - 1);
			picked.pop_back();
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	vector<int> emptyVector;
	vector<int> givenVector;
	int temp;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		// if (givenVector.empty() || find(givenVector.begin(), givenVector.end(), temp) == givenVector.end())
		{
			givenVector.push_back(temp);
		}
	}

	sort(givenVector.begin(), givenVector.end());
	pick(givenVector.size(), givenVector, emptyVector, M);
	return 0;
}