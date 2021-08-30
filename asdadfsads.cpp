#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;

struct linkedList
{
    ll data;
    char op;
    linkedList* next = nullptr;

    linkedList(ll _data, char _op)
    {
        data = _data;
        op = _op;
    }
};

ll solution(string expression) {
    ll answer = -(1ll << 50);
    map<char, int> op;
    op.insert({ '+', 0 });
    op.insert({ '-', 1 });
    op.insert({ '*', 2 });
    vector<vector<int>> priority
        = { {0, 1, 2},
           {0, 2, 1},
           {1, 0, 2},
           {1, 2, 0},
           {2, 0, 1},
           {2, 1, 0} };
    vector<ll> opIndexs;
    for (int i = 0; i < expression.length(); i++)
    {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*')
        {
            opIndexs.push_back(i);
        }
    }
    for (auto elem : priority)
    {
        vector<linkedList> v;
        v.push_back(linkedList(stoi(expression.substr(0, opIndexs[0])), expression[opIndexs[0]]));
        for (int i = 1; i < opIndexs.size(); i++)
        {
            v.push_back(linkedList(stoi(expression.substr(opIndexs[i - 1] + 1, opIndexs[i] - opIndexs[i - 1] - 1)), expression[opIndexs[i]]));
        }
        v.push_back(linkedList(stoi(expression.substr(opIndexs.back() + 1, expression.size())), 0));
        for (int i = 0; i < v.size() - 1; i++)
        {
            v[i].next = &(v[i + 1]);
        }
        for (int i = 0; i < 3; i++)
        {
            linkedList* curNode = &(v[0]);
            while (curNode->next != nullptr)
            {
                if (elem[op[curNode->op]] == i)
                {
                    if (curNode->op == '+')
                    {
                        curNode->data += curNode->next->data;
                    }
                    else if (curNode->op == '-')
                    {
                        curNode->data -= curNode->next->data;
                    }
                    else
                    {
                        curNode->data *= curNode->next->data;
                    }
                    curNode->op = curNode->next->op;
                    curNode->next = curNode->next->next;
                }
                else
                {
                    curNode = curNode->next;
                }
            }
        }
        answer = max(answer, abs(v[0].data));
    }
    return answer;
}

int main(void)
{
    cout << solution("100-200*300-500+20") << '\n';
    return 0;
}