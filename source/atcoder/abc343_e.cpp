#include <bits/stdc++.h>

#include "atcoder/all"

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD9 = 998244353;
const ll MOD1 = (ll)1e9 + 7;

int intersect_volume_2(int x1, int y1, int z1, int x2, int y2, int z2)
{
    int dx = max(0, min(x1 + 7, x2 + 7) - max(x1, x2));
    int dy = max(0, min(y1 + 7, y2 + 7) - max(y1, y2));
    int dz = max(0, min(z1 + 7, z2 + 7) - max(z1, z2));
    return dx * dy * dz;
}

int intersect_volume_3(int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3)
{
    int dx = max(0, min(x1 + 7, min(x2 + 7, x3 + 7)) - max(x1, max(x2, x3)));
    int dy = max(0, min(y1 + 7, min(y2 + 7, y3 + 7)) - max(y1, max(y2, y3)));
    int dz = max(0, min(z1 + 7, min(z2 + 7, z3 + 7)) - max(z1, max(z2, z3)));
    return dx * dy * dz;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll v1, v2, v3;
    cin >> v1 >> v2 >> v3;

    // In a coordinate space, we want to place three cubes with a side length of 7 so that the volumes of the regions contained in exactly one, two, three cube(s) are v1, v2, and v3, respectively.
    // Plus, the coords of corner of the cubes should be integers.

    // brute force
    // fix the first cube at (0, 0, 0)
    for (int x2 = -7; x2 <= 7; x2++) {
        for (int y2 = -7; y2 <= 7; y2++) {
            for (int z2 = -7; z2 <= 7; z2++) {
                for (int x3 = -7; x3 <= 7; x3++) {
                    for (int y3 = -7; y3 <= 7; y3++) {
                        for (int z3 = -7; z3 <= 7; z3++) {
                            int intersect_12 = intersect_volume_2(0, 0, 0, x2, y2, z2),
                                intersect_13 = intersect_volume_2(0, 0, 0, x3, y3, z3),
                                intersect_23 = intersect_volume_2(x2, y2, z2, x3, y3, z3),
                                intersect_123 = intersect_volume_3(0, 0, 0, x2, y2, z2, x3, y3, z3);
                            int cur_v1 = 3 * 7 * 7 * 7 - 2 * intersect_12 - 2 * intersect_13 - 2 * intersect_23 + 3 * intersect_123,
                                cur_v2 = intersect_12 + intersect_13 + intersect_23 - 3 * intersect_123,
                                cur_v3 = intersect_123;
                            if (cur_v1 == v1 && cur_v2 == v2 && cur_v3 == v3) {
                                cout << "Yes\n";
                                cout << "0 0 0\n"
                                     << x2 << ' ' << y2 << ' ' << z2 << '\n'
                                     << x3 << ' ' << y3 << ' ' << z3 << '\n';
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << "No\n";
    return 0;
}