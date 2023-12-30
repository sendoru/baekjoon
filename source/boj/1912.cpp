#include <iostream>
#include <vector>



const int MIN = -1000000000;

using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}

int maxSum(vector<int> vec)
{
	int ret = MIN;
	int tempSum = 0;

	for (int i = 0; i < vec.size(); i++)
	{
		tempSum = max(tempSum, 0) + vec[i];
		ret = max(tempSum, ret);
	}

	return ret;
}

int main(void)
{
	int N;
	cin >> N;

	vector<int> vec(N);
	for (int i = 0; i < N; i++)
		cin >> vec[i];

	cout << maxSum(vec) << endl;
	

	return 0;
}