#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int l = 1, r = distance, ans = 0;
    rocks.push_back(0);
    rocks.push_back(distance);
    sort(rocks.begin(), rocks.end());
    while (r >= l)
    {
        int m = (l + r) / 2, removed = 0, curDist = rocks[1];
        for (int i = 1; i < rocks.size() - 1; i++)
        {
            if (curDist < m)
            {
                curDist += rocks[i + 1] - rocks[i];
                removed++;
            }
            else
            {
                curDist = rocks[i + 1] - rocks[i];
            }
        }
        if (removed > n)
        {
            r = m - 1;
        }
        else
        {
            ans = max(ans, m);
            l = m + 1;
        }
    }
    return ans;
}

int main(void)
{
    cout << solution(25, { 2, 14, 11, 21, 17 }, 2);
    return 0;
}