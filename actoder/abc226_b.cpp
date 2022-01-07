#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    set<vector<int>> s;
    for (int i = 0; i < n; i++)
    {
        int l;
        cin >> l;
        vector<int> a(l);
        for (int j = 0; j < l; j++)
        {
            cin >> a[j];
        }
        s.insert(a);
    }
    cout << s.size();
    return 0;
}