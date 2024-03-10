#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD9 = 998244353;
const ll MOD1 = (ll)1e9 + 7;
const ll BUCKET_SIZE = 500;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;

    vector<pii> aa(n);
    for (int i = 0; i < n; i++) {
        aa[i].first = a[i];
        aa[i].second = i;
    }

    for (int i = 0; i < aa.size(); i += BUCKET_SIZE)
        sort(aa.begin() + i, min(aa.begin() + i + BUCKET_SIZE, aa.end()));

    while (m--) {
        int q;
        cin >> q;
        if (q == 2) {
            int s, e;
            cin >> s >> e;
            s--;
            e--;

            // 일단 제일 큰 값과 두 번째로 큰 값을 찾는다
            int largest = 0;

            auto iter_s = aa.begin() + (s / BUCKET_SIZE * BUCKET_SIZE),
                 iter_e = min(aa.begin() + ((e + BUCKET_SIZE) / BUCKET_SIZE * BUCKET_SIZE), aa.end());

            // 버킷이랑 완전히 겹치는 구간
            for (auto iter = iter_s + BUCKET_SIZE; iter < iter_e - BUCKET_SIZE; iter += BUCKET_SIZE) {
                largest = max(largest, (*(iter + BUCKET_SIZE - 1)).first);
            }

            // 버킷이랑 일부만 겹치는 구간
            for (auto iter = iter_s; iter < min(iter_s + BUCKET_SIZE, aa.end()); iter++) {
                if ((*iter).second >= s && (*iter).second <= e && (*iter).first > largest) {
                    largest = (*iter).first;
                }
            }
            for (auto iter = max(iter_e - BUCKET_SIZE, aa.begin()); iter < iter_e; iter++) {
                if ((*iter).second >= s && (*iter).second <= e && (*iter).first > largest) {
                    largest = (*iter).first;
                }
            }

            int second_largest = -1;
            // 각 버킷마다 largest보다 작은 값 중 제일 큰 값
            // 버킷이랑 완전히 겹치는 구간
            for (auto iter = iter_s + BUCKET_SIZE; iter < iter_e - BUCKET_SIZE; iter += BUCKET_SIZE) {
                auto lb = lower_bound(iter, iter + BUCKET_SIZE, make_pair(largest, -(int)MOD1));
                if (lb > iter) {
                    second_largest = max(second_largest, (*(lb - 1)).first);
                }
            }

            // 일부만 겹치는 구간
            for (auto iter = iter_s; iter < min(iter_s + BUCKET_SIZE, aa.end()); iter++) {
                if ((*iter).second >= s && (*iter).second <= e && (*iter).first > second_largest && (*iter).first < largest) {
                    second_largest = (*iter).first;
                }
            }
            for (auto iter = max(iter_e - BUCKET_SIZE, aa.begin()); iter < iter_e; iter++) {
                if ((*iter).second >= s && (*iter).second <= e && (*iter).first > second_largest && (*iter).first < largest) {
                    second_largest = (*iter).first;
                }
            }

            if (second_largest == -1) {
                cout << 0 << '\n';
            }
            else {
                // (second largest 이상 값 갯수) - (first largest 이상 값 갯수)
                int cnt_gt_second_largest = 0, cnt_gt_largest = 0;

                for (auto iter = iter_s; iter < iter_e; iter += BUCKET_SIZE) {
                    cnt_gt_largest += min(iter + BUCKET_SIZE, iter_e) - lower_bound(iter, min(iter + BUCKET_SIZE, iter_e), make_pair(largest, -(int)MOD1));
                }

                for (auto iter = iter_s; iter < min(iter_s + BUCKET_SIZE, aa.end()); iter++) {
                    if ((*iter).second < s && (*iter).first >= largest) {
                        cnt_gt_largest--;
                    }
                }
                for (auto iter = max(iter_e - BUCKET_SIZE, aa.begin()); iter < iter_e; iter++) {
                    if ((*iter).second > e && (*iter).first >= largest) {
                        cnt_gt_largest--;
                    }
                }

                for (auto iter = iter_s; iter < iter_e; iter += BUCKET_SIZE) {
                    cnt_gt_second_largest += min(iter + BUCKET_SIZE, iter_e) - lower_bound(iter, min(iter + BUCKET_SIZE, iter_e), make_pair(second_largest, -(int)MOD1));
                }

                for (auto iter = iter_s; iter < min(iter_s + BUCKET_SIZE, aa.end()); iter++) {
                    if ((*iter).second < s && (*iter).first >= second_largest) {
                        cnt_gt_second_largest--;
                    }
                }
                for (auto iter = max(iter_e - BUCKET_SIZE, aa.begin()); iter < iter_e; iter++) {
                    if ((*iter).second > e && (*iter).first >= second_largest) {
                        cnt_gt_second_largest--;
                    }
                }

                cout << cnt_gt_second_largest - cnt_gt_largest << '\n';
            }
        }

        else {
            int pos, k;
            cin >> pos >> k;
            pos--;
            auto iter_s = aa.begin() + (pos / BUCKET_SIZE * BUCKET_SIZE),
                 iter_e = min(iter_s + BUCKET_SIZE, aa.end());
            for (auto iter = iter_s; iter < iter_e; iter++) {
                if ((*iter).second == pos) {
                    (*iter).first = k;
                    break;
                }
            }
            sort(iter_s, iter_e);
        }
    }

    return 0;
}