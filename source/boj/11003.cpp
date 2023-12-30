#include <iostream>
#include <queue>
#include <vector>
#include <deque>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int l, n;
	cin >> l >> n;
	vector<int> a(l);
	for (int i = 0; i < l; i++)
		cin >> a[i];

	priority_queue<int, vector<int>, greater<int>> d, throwed;
	for (int i = 0; i < l; i++)
	{
		if (i - n >= 0)
		{
			throwed.push(a[i - n]);
		}
		d.push(a[i]);
		while (!d.empty() && !throwed.empty() && d.top() == throwed.top())
		{
			d.pop();
			throwed.pop();
		}
		cout << d.top() << ' ';
	}
	return 0;
}