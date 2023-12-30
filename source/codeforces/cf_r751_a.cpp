#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
typedef long long ll;
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        char minS = 'z';
        int minIndex = -1;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] <= minS)
            {
                minS = s[i];
                minIndex = i;
            }
        }

        cout << minS << ' ';
        for (int i = 0; i < s.length(); i++)
        {
            if (i != minIndex)
            {
                cout << s[i];
            }
        }
        cout << '\n';
    }
    return 0;
}