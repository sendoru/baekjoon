#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<int> h(n);
	for (int i = 0; i < n; i++) cin >> h[i];
	int ans = h[0];
	for (int i = 1; i < n; i++)
	{
		if (ans >= h[i]) break;
		ans = h[i];
	}

	cout << ans;
	return 0;
}