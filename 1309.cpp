#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int N;
	cin >> N;

	vector<vector<int>> vec(N+1);

	vec[0].push_back(1);
	vec[0].push_back(0);
	vec[0].push_back(0);

	for (int i = 1; i <= N; i++)
	{
		vec[i].push_back((vec[i - 1][0] + vec[i - 1][1] + vec[i - 1][2]) % 9901);
		vec[i].push_back((vec[i - 1][0] + vec[i - 1][2]) % 9901);
		vec[i].push_back((vec[i - 1][0] + vec[i - 1][1]) % 9901);
	}

	cout << (vec[N][0] + vec[N][1] + vec[N][2]) % 9901 << endl;
}