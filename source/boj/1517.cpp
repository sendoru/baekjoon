#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

ll solve(vector<ll>& v)
{
	ll ans = 0;

	function<void(ll,ll)> mergeSort = [&](ll l, ll r)
	{
		if (l == r || l == r - 1) return;
		
		mergeSort(l, (l + r) / 2);
		mergeSort((l + r) / 2, r);

		vector<ll> temp;
		ll lPtr = l, rPtr = (l + r) / 2;
		while (lPtr != (l + r) / 2 || rPtr != r)
		{
			// 왼쪽 걸 다 썼거나 오른쪽 게 더 클 경우
			if (lPtr == (l + r) / 2 || (rPtr != r && v[lPtr] > v[rPtr]))
			{
				temp.push_back(v[rPtr]);
				ans += (l + r) / 2 - lPtr;
				rPtr++;
			}
			else
			{
				temp.push_back(v[lPtr]);
				lPtr++;
			}
		}

		for (ll i = l; i < r; i++)
		{
			v[i] = temp[i - l];
		}
	};

	mergeSort(0, v.size());

	return ans;
}

ll naiveSolve(vector<ll> v)
{
	ll ans = 0;
	bool stop = true;
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v.size() - 1; j++)
		{
			if (v[j] > v[j + 1])
			{
				stop = false;
				ans++;
				swap(v[j], v[j + 1]);
			}
		}
		if (stop) break;
	}
	return ans;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n;
	cin >> n;
	vector<ll> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	cout << solve(v) << '\n';
	// cout << naiveSolve(v) << '\n';
	return 0;
}