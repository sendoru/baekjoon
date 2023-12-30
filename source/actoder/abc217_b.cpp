#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

int main(void)
{
	set<string> s;
	s.insert("ABC");
	s.insert("ARC");
	s.insert("AGC");
	s.insert("AHC");
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	s.erase(s1);
	s.erase(s2);
	s.erase(s3);
	cout << *s.begin();
	return 0;
}