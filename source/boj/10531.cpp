#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <cmath>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<ld> cpx;
constexpr ll MAX = 200001;
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

int solve(vector<cpx> k, vector<int> d)
{
	int n = 1;
	while (k.size() > n)
	{
		n <<= 1;
	}
	n <<= 1;
	k.resize(n);
	cpx w = cpx(cos(2 * pi / n), -sin(2 * pi / n));
	fft(k, w);
	for (int i = 0; i < k.size(); i++)
	{
		k[i] *= k[i];
	}
	w = cpx(1) / w;
	fft(k, w);
	for (int i = 0; i < k.size(); i++)
	{
		k[i] /= cpx(k.size());
	}

	int ans = 0;
	for (auto elem : d)
	{
		if (k[elem].real() > 1e-5)
		{
			ans++;
		}
	}
	return ans;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<cpx> k(MAX);
	vector<int> d;
	k[0] = 1;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int pos;
		cin >> pos;
		k[pos] = 1;
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int pos;
		cin >> pos;
		d.push_back(pos);
	}
	
	cout << solve(k, d);
	return 0;
}