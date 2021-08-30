#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> m, vector<int> b)
{
    vector<vector<int>> a(m.size());
    vector<int> ans(m.size());
    int pt = 0;
    for (int i = 0; i < m.size(); i++)
    {
        for (int j = 0; j < m[i]; j++)
        {
            a[i].push_back(b[pt]);
            pt++;
        }
    }
    for (int i = 0; i < a.size(); i++)
    {
        int bitAnd = (1ll << 31) - 1;
        for (int j = 0; j < a[i].size(); j++)
        {
            bitAnd &= a[i][j];
        }
        if (bitAnd == 0)
        {
            ans[i] = 0;
            continue;
        }
        if (bitAnd == 1)
        {
            ans[i] = 1;
            continue;
        }
        int mod = 1;
        while (mod <= bitAnd)
        {
            mod <<= 1;
        }
        while (mod != 0)
        {
            for (int j = 0; j < a[i].size(); j++)
            {
                a[i][j] %= mod;
            }
            int minAIndex = 0;
            for (int j = 0; j < a[i].size(); j++)
            {
                if (a[i][j] < a[i][minAIndex])
                {
                    minAIndex = j;
                }
            }
            if (a[i][minAIndex] == 0)
            {
                break;
            }
            if (a[i][minAIndex] < mod / 2)
            {
                mod >>= 1;
                continue;
            }
            ans[i] += a[i][minAIndex] - (mod / 2 - 1);
            a[i][minAIndex] = (mod / 2 - 1);
            mod >>= 1;
        }
    }


    return ans;
}
int main(void)
{
    int mSize, bSize = 0;
    cin >> mSize;
    vector<int> m(mSize);
    for (int i = 0; i < mSize; i++)
    {
        cin >> m[i];
        bSize += m[i];
    }
    vector<int> b(bSize);
    for (int i = 0; i < bSize; i++)
    {
        cin >> b[i];
    }
    auto ans = solution(m, b);
    return 0;
}