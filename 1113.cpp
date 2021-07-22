#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;
	vector<vector<int> > pool(n, vector < vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> pool[i][j];
		}
	}


}