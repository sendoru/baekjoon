#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long int>> getPartialSum(vector<vector<long long int>> vec)
{
	vector<vector<long long int>> rowPartialSum;

	rowPartialSum.push_back({});
	rowPartialSum[0].push_back(vec[0][0]);

	for (int j = 1; j < vec[0].size(); j++)
	{
		rowPartialSum[0].push_back(rowPartialSum[0][j - 1] + vec[0][j]);
	}

	for (int i = 1; i < vec.size(); i++)
	{
		rowPartialSum.push_back({});
		rowPartialSum[i].push_back(vec[i][0]);
		for (int j = 1; j < vec[i].size(); j++)
		{
			rowPartialSum[i].push_back(rowPartialSum[i][j - 1] + vec[i][j]);
		}
	}

	vector<vector<long long int>> partialSum(vec.size());
	copy(rowPartialSum.begin(), rowPartialSum.end(), partialSum.begin());

	for (int i = 1; i < partialSum.size(); i++)
	{
		for (int j = 0; j < partialSum[i].size(); j++)
		{
			partialSum[i][j] += partialSum[i - 1][j];
		}
	}

	return partialSum;
}

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M, temp;
	cin >> N >> M;

	vector<vector<long long int>> vec1;
	for (int i = 0; i < N; i++)
	{
		vec1.push_back({});
		for (int j = 0; j < N; j++)
		{
			cin >> temp;
			vec1[i].push_back(temp);
		}
	}

	vector<vector<long long int>>partialSum = getPartialSum(vec1);


	for (int i = 0; i < M; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1--; y1--; x2--; y2--;
		if (x1 == 0 && y1 == 0)
			cout << partialSum[x2][y2]<< '\n';
		else if (x1 == 0)
			cout << partialSum[x2][y2] - partialSum[x2][y1 - 1] << '\n';
		else if (y1 == 0)
			cout << partialSum[x2][y2] - partialSum[x1 - 1][y2] << '\n';
		else
			cout << partialSum[x2][y2] - partialSum[x2][y1 - 1] - partialSum[x1 - 1][y2] + partialSum[x1 - 1][y1 - 1] << '\n';
	}
}


