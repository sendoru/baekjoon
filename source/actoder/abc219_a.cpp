#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int x, ans;
	cin >> x;
	if (x >= 0 && x < 40)
		ans = 40 - x;
	else if (x >= 40 && x < 70)
		ans = 70 - x;
	else if (x >= 70 && x < 90)
		ans = 90 - x;
	else
		ans = -1;

	if (ans == -1)
		cout << "expert";
	else
		cout << ans;

	return 0;
}