#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


// 처음 주어지는 picked는 {}
void pick(int n, vector<int> sortedVector, vector<int>& picked, int toPick, set<vector<int>>& set1)
{
	// 더 고를 게 없으면 고른거 전부 뱉어내기
	if (toPick == 0)
	{
		vector<int> generatedVector;
		for (int i = 0; i < picked.size(); i++)
			generatedVector.push_back(sortedVector[picked[i]]);
		set1.insert(generatedVector);
		return;
	}

	for (int next = 0; next < n; next++)
	{
		if (find(picked.begin(), picked.end(), next) == picked.end())
		{
			picked.push_back(next);
			pick(n, sortedVector, picked, toPick - 1, set1);
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
	set<vector<int>> set1;
	int temp;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		givenVector.push_back(temp);
	}

	sort(givenVector.begin(), givenVector.end());

	pick(N, givenVector, emptyVector, M, set1);
	for (auto iter = set1.begin(); iter != set1.end(); iter++)
	{
		vector<int> vec1 = *iter;
		for (int j = 0; j < M; j++)
		{
			cout << vec1[j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}