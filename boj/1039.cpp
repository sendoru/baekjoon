#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <string>
using namespace std;

string bfs(string n, int k)
{
    set<string> evens, odds;
    queue<pair<string, int>> q;
    q.push({ n, 0 });
    while (!q.empty())
    {
        string curN = q.front().first;
        int curDepth = q.front().second;
        q.pop();
        if (curDepth >= k) continue;

        for (int i = 0; i < n.length(); i++)
        {
            for (int j = i + 1; j < n.length(); j++)
            {
                string nextN = curN;
                swap(nextN[i], nextN[j]);
                int nextDepth = curDepth + 1;
                if (nextN[0] != '0')
                {
                    if (nextDepth % 2 == 1)
                    {
                        if (odds.find(nextN) == odds.end())
                        {
                            odds.insert(nextN);
                            q.push({ nextN, nextDepth });
                        }
                    }
                    else
                    {
                        if (evens.find(nextN) == evens.end())
                        {
                            evens.insert(nextN);
                            q.push({ nextN, nextDepth });
                        }
                    }
                }
            }
        }
    }

    if (k % 2 == 1)
    {
        return odds.empty() ? "-1" : *(--odds.end());
    }
    return evens.empty() ? "-1" : *(--evens.end());
}

int main(void)
{
    string n;
    int k;
    cin >> n >> k;

    cout << bfs(n, k);
    return 0;
}