#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef long double ld;
constexpr ld INF = 9876543210.l;

ll cubicFunction(ll a, ll b, ll c, ll d, ll x)
{
	return a * x * x * x + b * x * x + c * x + d;
}

ld determinant(ll a, ll b, ll c)
{
	return b * b - 4 * a * c;
}

vector<ld> solve2(ll a, ll b, ll c)
{
	ld d = determinant(a, b, c);
	if (d > 0)
	{
		return {(-b + sqrtl(d)) / (2.l * a), (-b - sqrtl(d)) / (2.l * a)};
	}
	else if (d == 0)
	{
		return {-b / (2.l * a)};
	}
	else
	{
		return {};
	}
}

vector<ld> solve3(ll a, ll b, ll c, ll d)
{
	vector<ld> ret;
	vector<ll> divisorOfD;
	if (d != 0)
	{
		for (int i = 1; i <= sqrtl(llabs(d)); i++)
		{
			if (d % i == 0)
			{
				divisorOfD.push_back(i);
				divisorOfD.push_back(d / i);
			}
		}
		for (ll elem : divisorOfD)
		{
			if (elem * cubicFunction(0, a, b, c, elem) == -d)
			{
				ret.push_back(elem);
				break;
			}
			else if (-elem * cubicFunction(0, a, b, c, -elem) == -d)
			{
				ret.push_back(-elem);
				break;
			}
		}
	}
	else
	{
		ret.push_back(0);
	}

	vector<ld> rootOfQuad = solve2(a, ret[0] * a + b, ret[0] * ret[0] * a + ret[0] * b + c);

	for (ld elem : rootOfQuad)
	{
		if (abs(ret[0] - elem) > .99e-4)
		{
			ret.push_back(elem);
		}
	}
	sort(ret.begin(), ret.end());

	return ret;
}

int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.fixed;
	cout.precision(5);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		vector<ld> root = solve3(a, b, c, d);
		for (ld elem : root)
		{
			elem *= 10000;
			elem = roundl(elem);
			elem /= 10000;
			cout << elem << ' ';
		}
		cout << '\n';
	}

	return 0;
}