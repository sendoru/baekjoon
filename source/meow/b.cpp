#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD9 = 998244353;
const ll MOD1 = (ll)1e9 + 7;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int r, c;
        cin >> r >> c;
        vector<string> s(r);
        for(string& i : s) {
            cin >> i;
        }

        vector<string> base(r);
        for (string& elem : base) {
            for(int i = 0; i < c; i++) {
                elem += '.';
            }
        }

        bool ans = false;

        for(int n = 1; n <= min(r, c); n++) {
            for(int m = 1; m < n; m++) {
                for(int d = 0; d < 4; d++) {
                    // 위 3개 루프에서 하트 모양 결정
                    for(int r_min = 0; r_min <= r - n; r_min++) {
                        for(int c_min = 0; c_min <= c - n; c_min++) {
                            // 위 2개 루프에서 위치 결정
                            auto cur = base;
                            for(int r_cur = r_min; r_cur < n + r_min; r_cur++) {
                                for(int c_cur = c_min; c_cur < n + c_min; c_cur++) {
                                    cur[r_cur][c_cur] = '#';
                                }
                            }
                            int r_m_min, c_m_min;
                            switch (d) {
                                case 0:
                                    r_m_min = r_min;
                                    c_m_min = c_min;
                                    break;
                                case 1:
                                    r_m_min = r_min;
                                    c_m_min = n + c_min - m;
                                    break;
                                case 2:
                                    r_m_min = n + r_min - m;
                                    c_m_min = c_min;
                                    break;
                                case 3:
                                    r_m_min = n + r_min - m;
                                    c_m_min = n + c_min - m;
                            }

                            for(int r_cur = r_m_min; r_cur < m + r_m_min; r_cur++) {
                                for(int c_cur = c_m_min; c_cur < m + c_m_min; c_cur++) {
                                    cur[r_cur][c_cur] = '.';
                                }
                            }

                            if (cur == s) {
                                ans = true;
                                break;
                            }
                        }
                    }
                }
            }
        }

    cout << (ans ? 1 : 0) << '\n';
    }
}