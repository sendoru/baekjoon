#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e12;

template <typename T, typename op, T e>
class SegTree {
    vector<T> data;
    ll n;
public:
    SegTree(ll _n) {
        ll h = 0;
        while ((1 << h) < 2 * _n)
            h++;
        
        data = vector<T>(1 << h, e);
        n = 1 << (h - 1);
    }
    
    SegTree(vector<T>& v) {
        ll _n = v.size();
        ll h = 0;
        while ((1 << h) < 2 * _n)
            h++;
        
        data = vector<T>(1 << h, e);
        n = 1 << (h - 1);
        
        for(int i = 0; i < v.size(); i++)
            data[i + n] = v[i];
        for(int i = n - 1; i >= 1; i--)
            data[i] = op()(data[2 * i], data[2 * i + 1]);
    }
    
    void set(ll idx, T val) {
        idx += n;
        data[idx] = val;
        while (idx != 1) {
            idx >>= 1;
            data[idx] = op()(data[2 * idx], data[2 * idx + 1]);
        }
    }
    
    T get(ll idx) {
        return data[idx + n];
    }
    
    T get(ll l, ll r) {
        l += n;
        r += n + 1;
        ll ret = e;
        while (l < r) {
            if (l & 1) {
                ret = op()(ret, data[l]);
                l++;
            }
            if (r & 1) {
                r--;
                ret = op()(data[r], ret);
            }
            l >>= 1;
            r >>= 1;
        }
        return ret;
    }
    
    
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    
    vector<vector<ll>> people(n, vector<ll>(4, -1));
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < n; j++) {
            // i번째 시험에서 j등을 한 사람의 번호
            int temp;
            cin >> temp;
            temp--;
            people[temp][i] = j;
        }
    }
    
    struct op {
        int operator()(int a, int b) {
            return min(a, b);
        }
    };
    SegTree<int, op, (int)2e9> seg(n);
    int ret = 0;
    sort(people.begin(), people.end());
    // A 과목에서 i등 한 사람을 체크할 때, A 과목에서 0 ~ i - 1등을 한 사람들은 전부 세그트리에 이미 들어가 있음
    // 이미 세그트리에 들어간 사람 중, 지금 체크하는 i번째 사람보다 B 과목 등수가 높은 사람들 중 C과목의 등수가 가장 높은 사람을 보면 됨
    for(int i = 0; i < n; i++)
    {
        if (seg.get(0, people[i][1] - 1) > people[i][2])
            ret++;
        seg.set(people[i][1], people[i][2]);
    }
    
    cout << ret;
    
    return 0;
}