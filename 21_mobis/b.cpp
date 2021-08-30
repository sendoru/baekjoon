#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<bool> solution(vector<string> a) {
    vector<bool> answer(a.size());
    for (int i = 0; i < a.size(); i++)
    {
        string& curStr = a[i];
        int aCnt = 0;
        for (int j = 0; j < curStr.length(); j++)
        {
            if (curStr[j] == 'a')
            {
                aCnt++;
            }
        }
        bool curAns = true;
        if (curStr == "a")
        {
            curAns = true;
            answer[i] = curAns;
            continue;
        }
        if (curStr == "b")
        {
            curAns = false;
            answer[i] = curAns;
            continue;
        }
        int l = 0, r = curStr.length() - 1;
        while (r > l)
        {
            if (curStr[l] == 'a')
            {
                l++;
                aCnt--;
            }
            else if (curStr[r] == 'a')
            {
                r--;
                aCnt--;
            }
            else if (curStr[l] == 'b' || curStr[r] == 'b')
            {
                if (aCnt == 0)
                {
                    curAns = false;
                    break;
                }
                for (int j = 0; j < aCnt; j++)
                {
                    if (curStr[l] != 'b' || curStr[r] != 'b' || r < l)
                    {
                        curAns = false;
                        break;
                    }
                    else
                    {
                        l++;
                        r--;
                    }
                }
            }
            if (!curAns)
            {
                break;
            }
        }
        if (r != l || curStr[r] != 'a')
        {
            curAns = false;
        }
        answer[i] = curAns;
    }
    return answer;
}


int main(void)
{
    int n;
    cin >> n;

    vector<string> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    auto ans = solution(a);
    return 0;
}