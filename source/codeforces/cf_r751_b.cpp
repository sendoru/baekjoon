#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
typedef long long ll;
constexpr int MAX_OP = 100'001;
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
        int n;
        cin >> n;
        vector<vector<int>> arr(1, vector<int>(n));
        for (int i = 0; i < n; i++) cin >> arr[0][i];
        int q;
        cin >> q;

        vector<pair<int, int>> queries(q);
        for (int i = 0; i < q; i++) cin >> queries[i].first >> queries[i].second;

        vector<vector<int>> occ(1, vector<int>(n + 1));
        for (int i = 0; i < n; i++) occ[0][arr[0][i]]++;

        int curPtr = 0;

        for(int i = 1; i < 0x3fffffff; i++)
        {
            int isEnd = true;
            occ.push_back(vector<int>(n + 1));
            arr.push_back(vector<int>(n));
            for (int j = 1; j <= n; j++)
            {
                occ[i][occ[i - 1][j]] += occ[i - 1][j];
            }
            for (int j = 0; j < n; j++)
            {
                arr[i][j] = occ[i - 1][arr[i - 1][j]];
            }
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] != arr[i - 1][j])
                {
                    isEnd = false;
                    break;
                }
            }

            if (isEnd) break;
        }

        for (int i = 0; i < q; i++)
        {
            if (queries[i].second < occ.size())
            {
                cout << arr[queries[i].second][queries[i].first - 1] << '\n';
            }
            else
            {
                cout << arr.back()[queries[i].first - 1] << '\n';
            }
        }
    }
    return 0;
}