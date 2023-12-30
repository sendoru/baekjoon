#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD9 = 998244353;
const ll MOD1 = (ll)1e9 + 7;

struct Info {
    ll person_no, x, y;
    Info(ll a, ll b, ll c) : person_no(a), x(b), y(c) {}
};

struct Person {
    bool visited = false;
    ll x = 0, y = 0;
    vector<Info> infos;
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<Person> p(n + 1);
    for(int i = 0; i < m; i++) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        p[a].infos.push_back(Info(b, x, y));
        p[b].infos.push_back(Info(a, -x, -y));
    }

    p[1].visited = true;

    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(auto& info : p[cur].infos){
            if (!p[info.person_no].visited) {
                p[info.person_no].visited = true;
                p[info.person_no].x = p[cur].x + info.x;
                p[info.person_no].y = p[cur].y + info.y;
                q.push(info.person_no);
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        if (p[i].visited) {
            cout << p[i].x << ' ' << p[i].y << '\n';
        }
        else {
            cout << "undecidable\n";
        }
    }

    return 0;
}