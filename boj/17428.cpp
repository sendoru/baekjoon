#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<vector<ll>> a(26, vector<ll>(26));
vector<ll> b(26);

void solve(int n, int k)
{
	if (k >= b[n])
	{
		cout << -1;
		return;
	}

	if (n == 0)
		return;
	if (n == 1)
	{
		cout << "()";
		return;
	}

	auto iter = upper_bound(a[n].begin(), a[n].end(), k);
	int idx = iter - a[n].begin();
	// (S)T¿¡¼­ S = n - idx - 1, T = idx
	cout << "(";
	if (idx == 0)
	{
		solve(n - 1, k);
		cout << ")";
	}
	else
	{
		k -= *(iter - 1);
		solve(n - idx - 1, k / b[idx]);
		cout << ")";
		solve(idx, k % b[idx]);
	}
}

int main(void)
{

	a[0] = vector<ll>(26, 1);
	a[1] = vector<ll>(26, 1);
	b[0] = 1;
	b[1] = 1;
	for (int i = 2; i <= 25; i++)
	{
		a[i][0] = b[i - 1] * b[0];
		b[i] += b[i - 1] * b[0];
		for (int j = 1; j < i; j++)
		{
			a[i][j] = a[i][j - 1] + b[i - j - 1] * b[j];
			b[i] += b[i - j - 1] * b[j];
		}
		for (int j = i; j <= 25; j++)
		{
			a[i][j] = a[i][j - 1];
		}
	}

	int t;
	cin >> t;
	while (t--)
	{
		ll n, k;
		cin >> n >> k;
		n /= 2;


		solve(n, k);
		cout << '\n';
	}

	return 0;
}