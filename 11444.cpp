#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

typedef long long ll;

vector<vector<ll> > fibPow(ll n)
{
	vector<vector<ll> > t(2);
	t[0] = { 1, 1 };
	t[1] = { 1, 0 };
	if (n == 1)
	{
		return t;
	}
	t = fibPow(n / 2);
	vector<vector<ll> > t2(2);
	t2[0] = { (t[0][0] * t[0][0] + t[0][1] * t[1][0]) % MOD, (t[0][0] * t[0][1] + t[0][1] * t[1][1]) % MOD };
	t2[1] = { (t[1][0] * t[0][0] + t[1][1] * t[1][0]) % MOD, (t[1][0] * t[0][1] + t[1][1] * t[1][1]) % MOD };

	if (n % 2)
	{
		t[0][0] = (t2[0][0] + t2[1][0]) % MOD;
		t[0][1] = (t2[0][1] + t2[1][1]) % MOD;
		t[1][0] = t2[0][0];
		t[1][1] = t2[0][1];
		return t;
	}
	return t2;
}

int main() {
	ll N;
	cin >> N;

	vector<vector<ll> > t = fibPow(N);

	cout << t[0][1] << endl;

	return 0;
}
