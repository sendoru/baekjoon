#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
const int INF = 0x3fffffff;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int ans = INF;
        for (char c = 'a'; c <= 'z'; c++)
        {
            string newS;
            vector<int> occurrence(s.length() + 1);
            for (int i = 0; i < s.length(); i++)
            {
                if (s[i] != c) newS += s[i];
                else occurrence[newS.length()]++;
            }
            occurrence.resize(newS.length() + 1);

            // 팰린드롬인지 체크
            bool valid = true;
            for (int i = 0; i < (newS.length() + 1) / 2; i++)
            {
                if (newS[i] != newS[newS.length() - 1 - i])
                {
                    valid = false;
                    break;
                }
            }

            if (!valid) continue;
            int curLen = newS.length();
            for (int i = 0; i < occurrence.size() / 2; i++)
            {
                curLen += 2 * min(occurrence[i], occurrence[occurrence.size() - 1 - i]);
            }
            if (occurrence.size() % 2 == 1)
            {
                curLen += occurrence[occurrence.size() / 2];
            }
            ans = min(ans, (int)s.length() - curLen);
        }

        cout << (ans == INF ? -1 : ans) << '\n';
    }

    return 0;
}