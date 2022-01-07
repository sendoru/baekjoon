#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <cmath>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<ld> cpx;
constexpr ll MAX = 1 << 17;
const ld pi = acos(-1);

void fft(vector<cpx>& v, cpx w)
{
	int n = v.size();
	if (n == 1)
	{
		return;
	}

	vector<cpx> even(n / 2), odd(n / 2);
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			even[i / 2] = v[i];
		}
		else
		{
			odd[i / 2] = v[i];
		}
	}
	fft(even, w * w);
	fft(odd, w * w);

	cpx wp(1, 0);
	for (int i = 0; i < n / 2; i++)
	{
		v[i] = even[i] + wp * odd[i];
		v[i + n / 2] = even[i] - wp * odd[i];
		wp *= w;
	}
}

vector<cpx> mul(vector<cpx> a, vector<cpx> b)
{
	int n = 1;
	while (n <= a.size() || n <= b.size())
	{
		n <<= 1;
	}

	a.resize(n);
	b.resize(n);
	vector<cpx> c(n);
	cpx w(cos(2 * pi / n), sin(2 * pi / n));

	fft(a, w);
	fft(b, w);

	for (int i = 0; i < n; i++)
	{
		c[i] = a[i] * b[i];
	}

	fft(c, cpx(1, 0) / w);

	for (int i = 0; i < n; i++)
	{
		c[i] /= cpx(n, 0);
	}

	return c;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;

	vector<ll> a(n * 2), b(n);

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = n - 1; i >= 0; i--)
	{
		cin >> b[i];
	}
	for (int i = 0; i < n; i++)
	{
		a[i + n] = a[i];
	}

	vector<cpx> aCpx, bCpx;
	for (ll elem : a)
	{
		aCpx.push_back(cpx(elem, 0));
	}
	for (ll elem : b)
	{
		bCpx.push_back(cpx(elem, 0));
	}

	vector<cpx> c = mul(aCpx, bCpx);

	ll ans = 0;
	for (int i = 0; i < c.size(); i++)
	{
		ans = max(ans, llround(c[i].real()));
	}

	cout << ans << '\n';

	return 0;
}