#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD9 = 998244353;
const ll MOD1 = (ll)1e9 + 7;

vector<int> dr = {-1, 0, 1, 0}, dc = {0, 1, 0, -1};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(12);

    int n, k, m;
    cin >> n >> k >> m;

    // 콘센트는 구멍 많은거부터 bfs식으로 연결하고
    // 전자기기는 허용 거리 긴거부터 가져가는게 이득
    // 파라메트릭으로 전자기기 갯수 찾기

    vector<int> a(n);
    for(int& i : a) {
        cin >> i;
    }
    sort(a.begin(), a.end(), greater<>());

    vector<int> d(m);
    for(int& i : d) {
        cin >> i;
    }
    sort(d.begin(), d.end(), greater<>());

    int l = 0, r = m, ans = 0;
    while(l <= r) {
        int mid = (l + r) / 2;
        // 벽에서부터 거리 i인 콘센트 갯수
        vector<int> socket_cnt(d.size() + 1);
        socket_cnt[0] = k;
        int d_ptr = mid - 1, a_ptr = 0, socket_cnt_ptr = 0;
        bool possible = true;

        for(int dist = 0; dist <= d[0]; dist++) {
            if (!possible) {
                break;
            }
            if (d_ptr == -1) {
                break;
            }
            while (d_ptr >= 0 && d[d_ptr] <= dist) {
                while (socket_cnt[socket_cnt_ptr] == 0 && socket_cnt_ptr < dist) {
                    socket_cnt_ptr++;
                }
                if (socket_cnt_ptr == dist && socket_cnt[dist] == 0) {
                    possible = false;
                    break;
                }

                socket_cnt[socket_cnt_ptr]--;
                d_ptr--;
            }

            if (!possible) {
                break;
            }

            while(a_ptr != a.size()) {
                while (socket_cnt[socket_cnt_ptr] == 0 && socket_cnt_ptr < dist) {
                    socket_cnt_ptr++;
                }
                if (socket_cnt[socket_cnt_ptr] == 0) {
                    break;
                }
                socket_cnt[socket_cnt_ptr]--;
                socket_cnt[socket_cnt_ptr + 1] += a[a_ptr];
                a_ptr++;
            }
        }

        if (possible) {
            ans = max(ans, mid);
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    cout << ans;

    return 0;
}