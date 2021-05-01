#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N, tmp;
	cin >> N;
	vector<int> asdf;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		asdf.push_back(tmp);
	}

	sort(asdf.begin(), asdf.end());

	for (int i = 0; i < N; i++)
	{
		cout << asdf[i] << '\n';
	}

	return 0;
}