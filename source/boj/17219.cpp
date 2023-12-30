#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;


int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	string temp1, temp2;
	unordered_map<string, string> dictMap;
	dictMap.reserve(100000);

	for (int i = 0; i < N; i++)
	{
		cin >> temp1 >> temp2;
		dictMap.insert(pair<string, string>(temp1, temp2));
	}

	vector<string> questions;

	for (int i = 0; i < M; i++)
	{
		cin >> temp1;
		questions.push_back(temp1);
	}

	for (int i = 0; i < M; i++)
	{
		cout << dictMap[questions[i]] << '\n';
	}

	return 0;
}