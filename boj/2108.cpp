#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, temp;
	vector<int> nums;
	cin >> N;

	for (int i = 0; i <= N; i++)
	{
		cin >> temp;
		nums.push_back(temp);
	}

	sort(nums.begin(), nums.end());

	cout << round(average(nums)) << '\n';
	cout << nums[nums.size() / 2] << '\n';
	cout << << '\n';                  // TODO 최빈값 구하기
	cout << nums.back() - nums[0] << '\n'
}