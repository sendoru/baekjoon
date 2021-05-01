#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<ll> A(n), B(n), C(n), D(n);

	for (int i = 0; i < n; i++)
	{
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}

	vector<ll> arr1, arr2;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr1.push_back(A[i] + B[j]);
			arr2.push_back(C[i] + D[j]);
		}
	}

	sort(arr2.begin(), arr2.end());

	ll ans = 0;

	for (int i = 0; i < arr1.size(); i++)
	{
		ll n = arr1[i];
		ll cnt = upper_bound(arr2.begin(), arr2.end(), -n) - lower_bound(arr2.begin(), arr2.end(), -n);
		ans += cnt;
	}

	cout << ans << '\n';
	return 0;
}