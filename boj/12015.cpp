#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
constexpr auto INF = (ll)10e+9 + 7;

int main(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<ll> vec(N);
	for (int i = 0; i < N; i++)
	{
		cin >> vec[i];
	}

	vector<ll> lis(1, -INF);
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		if (lis.back() < vec[i])
		{
			lis.push_back(vec[i]);
			ans++;
		}
		else
		{
			auto it = lower_bound(lis.begin(), lis.end(), vec[i]);
			*it = vec[i];
		}
	}

	cout << ans << '\n';

	return 0;
}

