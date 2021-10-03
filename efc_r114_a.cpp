#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;

string getB(int r, int c)
{
	if (r == 1)
	{
		return "()";
	}
	
	if (r == c)
	{
		return "()" + getB(r - 1, 1);
	}
	return "(" + getB(r - 1, c) +")";

}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cout << getB(n, i) << '\n';
		}
	}
}