#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long double ld;
typedef long long ll;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, g, k;
	cin >> n >> g >> k;
	vector<vector<ll>> v(n, vector<ll>(3));
	for (int i = 0; i < n; i++)
	{
		cin >> v[i][0] >> v[i][1] >> v[i][2];
	}

	vector<vector<ll>> unnecessary;
	ll num = g, den = 0;
	for (int i = 0; i < n; i++)
	{
		if (v[i][2] == 0)
		{
			num += v[i][1] * v[i][0];
			den += v[i][0];
		}
		else
		{
			unnecessary.push_back(v[i]);
		}
	}

	sort(unnecessary.begin(), unnecessary.end(), [num, den](vector<ll> a, vector<ll> b) -> bool {
		return ((num + a[1] * a[0]) * (den + b[0])) > ((num + b[1] * b[0]) * (den + a[0]));
		});

	// 재료를 k개 뺀다 == n - k개를 넣는다
	for (int i = 0; i < max(unnecessary.size() - k, 0ull); i++)
	{
		num += unnecessary[i][1] * unnecessary[i][0];
		den += unnecessary[i][0];
	}
	cout << num / den;
	return 0;
}