#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;


int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	string temp;
	vector<string> dictVec;
	unordered_map<string, int> dictMap;
	dictVec.reserve(100000);
	dictMap.reserve(100000);

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		dictVec.push_back(temp);
		dictMap.insert(pair<string, int>(temp, i + 1));
	}

	vector<string> questions;
	for (int i = 0; i < M; i++)
	{
		cin >> temp;
		questions.push_back(temp);
	}

	for (int i = 0; i < M; i++)
	{
		if (questions[i][0] >= 'A')
			cout << dictMap[questions[i]] << '\n';
		else
			cout << dictVec[stoi(questions[i]) - 1] << '\n';
	}

	return 0;
}