#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; ll cost = 0, m;
	cin >> n;
	vector<ll> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	for (int i = 0; i < n - 2; i++)
	{
		if (v[i + 1] > v[i + 2])
		{
			m = min(v[i], min(v[i + 1], v[i + 1] - v[i + 2]));
			v[i] -= m;
			v[i + 1] -= m;
			cost += m * 5;
		}
		m = min(v[i], min(v[i + 1], v[i + 2]));
		v[i] -= m;
		v[i + 1] -= m;
		v[i + 2] -= m;
		cost += m * 7;
	}
	for (int i = 0; i < n - 1; i++)
	{
		m = min(v[i], v[i + 1]);
		v[i] -= m;
		v[i + 1] -= m;
		cost += m * 5;
	}
	for (int i = 0; i < n; i++)
	{
		cost += v[i] * 3;
		v[i] = 0;
	}
	cout << cost << '\n';
	return 0;
}