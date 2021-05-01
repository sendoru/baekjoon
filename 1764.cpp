#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;



int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	vector<string> unlistened;
	vector<string> unseen;
	vector<string> dbj;
	string cmp;

	for (int i = 0; i < N; i++)
	{
		cin >> cmp;
		unlistened.push_back(cmp);
	}

	for (int i = 0; i < M; i++)
	{
		cin >> cmp;
		unseen.push_back(cmp);
	}

	sort(unlistened.begin(), unlistened.end(), less<string>());
	sort(unseen.begin(), unseen.end(), less<string>());

	for (int i = 0; i < M; i++)
		if (binary_search(unlistened.begin(), unlistened.end(), unseen[i]))
			dbj.push_back(unseen[i]);

	cout << dbj.size() << '\n';

	for (int i = 0; i < dbj.size(); i++)
		cout << dbj[i] << '\n';

	return 0;
}

