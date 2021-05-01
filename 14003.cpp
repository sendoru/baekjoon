#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
typedef long long ll;
constexpr auto INF = (ll)10e+9 + 7;

int main(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, tmpIndex = -1, lenofLIS = 0;
	stack<ll> lis;
	vector<ll> vt;
	vector<ll> index;

	cin >> N;
	vector<ll> givenSequence(N);
	vector<ll> backTracking(N, -1);
	for (int i = 0; i < N; i++)
	{
		cin >> givenSequence[i];
	}
	
	for (int i = 0; i < N; i++)
	{
		if (vt.size() == 0 || vt.back() < givenSequence[i])
		{
			vt.push_back(givenSequence[i]);
			index.push_back(i);
			lenofLIS++;
			if (lenofLIS == 1)
			{
				backTracking[i] = -1;
			}
			else
			{
				backTracking[i] = index[lenofLIS - 2];
			}
		}
		else
		{
			auto it = lower_bound(vt.begin(), vt.end(), givenSequence[i]);
			*it = givenSequence[i];
			index[it - vt.begin()] = i;
			if (it == vt.begin())
			{
				backTracking[i] = -1;
			}
			else
			{
				backTracking[i] = index[it - vt.begin() - 1];
			}
		}
	}

	cout << vt.size() << '\n';
	int start = index.back();

	while (start != -1)
	{
		lis.push(givenSequence[start]);
		start = backTracking[start];
	}
	while (!lis.empty())
	{
		cout << lis.top() << ' ';
		lis.pop();
	}
	cout << '\n';

	return 0;
}