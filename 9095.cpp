#include <iostream>
#include <vector>

using namespace std;

int asdf(int n)
{
	int ref[12];
	ref[0] = 1;
	ref[1] = 1;
	ref[2] = 2;

	for (int i = 3; i <= n; i++)
	{
		ref[i] = (ref[i - 1] + ref[i - 2] + ref[i - 3]);
	}
	return ref[n];
}

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	vector<int> cases;
	int tmp;

	for (int i = 0; i < T; i++)
	{
		cin >> tmp;
		cases.push_back(tmp);
	}


	for (int i = 0; i < T; i++)
	{
		cout << asdf(cases[i]) << '\n';
	}

	return 0;
}