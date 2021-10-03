#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(void)
{
	int l, q;
	cin >> l >> q;
	set<int> s;
	s.insert(0);
	s.insert(l);
	while (q--)
	{
		int c, x;
		cin >> c >> x;
		if (c == 1)
		{
			s.insert(x);
		}
		else if (c == 2)
		{
			cout << *s.upper_bound(x) - *(--s.upper_bound(x)) << '\n';
		}
	}
	return 0;
}
