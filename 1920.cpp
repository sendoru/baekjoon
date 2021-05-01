#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M, temp;
	set<int> nums1;
	vector<int> nums2;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		nums1.insert(temp);
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> temp;
		nums2.push_back(temp);
	}
	for (int i = 0; i < M; i++)
	{
		if (nums1.find(nums2[i]) != nums1.end())
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
	return 0;

}