#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
typedef long long ll;
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int ab = 0, ba = 0;
        for (int i = 0; i < s.length() - 1; i++)
        {
            if (s[i] == 'a' && s[i + 1] == 'b')
            {
                ab++;
            }
            else if (s[i] == 'b' && s[i + 1] == 'a')
            {
                ba++;
            }
        }
        if (ab == ba)
        {
            cout << s << '\n';
        }
        else
        {
            s[0] = (s[0] == 'a' ? 'b' : 'a');
            cout << s << '\n';
        }
    }

    return 0;
}