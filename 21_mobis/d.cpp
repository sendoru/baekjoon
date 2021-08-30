#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

vector<bool> solution(vector<vector<int>> p, vector<vector<int>> q)
{
    vector<bool> answer(q.size());
    for (int i = 0; i < q.size(); i++)
    {
        bool curAns = true;
        unordered_multiset<int> us;
        priority_queue<int, vector<int>, greater<int>> pqP, pqQ;
        for (auto elem : p[i])
        {
            pqP.push(elem);
        }
        for (auto elem : q[i])
        {
            pqQ.push(elem);
        }
        while (!pqQ.empty())
        {
            int cur = pqQ.top();
            pqQ.pop();
            while (pqP.top() < cur && pqP.size() > 1)
            {
                int curP1 = pqP.top();
                pqP.pop();
                int curP2 = pqP.top();
                pqP.pop();
                pqP.push(curP1 + curP2);
            }
            if (pqP.top() != cur)
            {
                curAns = false;
                break;
            }
            else
            {
                pqP.pop();
            }
        }
        answer[i] = curAns;
    }
    return answer;
}

int main(void)
{
    int n;
    cin >> n;
    vector<vector<int>> p(n);
    vector<vector<int>> q(n);
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        p[i].resize(m);
        for (int j = 0; j < m; j++)
        {
            cin >> p[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        q[i].resize(m);
        for (int j = 0; j < m; j++)
        {
            cin >> q[i][j];
        }
    }
    auto a = solution(p, q);
    return 0;
}