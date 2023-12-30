#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

int main(void)
{
	ll n, w, coins = 0;
	cin >> n >> w, coins = 0;
	vector<ll> prices(n);
	for (int i = 0; i < n; i++)
	{
		cin >> prices[i];
	}
	if (n == 0)
	{
		cout << w;
		return 0;
	}
	for (int i = 0; i < n - 1; i++)
	{
		w += coins * prices[i];
		coins = 0;
		if (prices[i] < prices[i + 1])
		{
			coins += w / prices[i];
			w %= prices[i];
		}
	}
	w += coins * prices.back();
	cout << w;
	return 0;

}