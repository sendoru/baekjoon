#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    if (s[0] != s[1] && s[1] != s[2])
        cout << 6;

    else if (s[0] == s[1] && s[1] == s[2])
        cout << 1;

    else
        cout << 3;

    return 0;
}