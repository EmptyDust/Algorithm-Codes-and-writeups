#include<bits/stdc++.h>
#define int long long
#define num first
#define dis second
using namespace std;
constexpr int MAXN = 2e4;
int ans[MAXN];
using pt = pair<int, int>;
vector<pt> lj[MAXN];

struct op {
    bool operator() (pt a, pt b) {
        return a.dis > b.dis;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    int n, m, s;cin >> n >> m >> s;
    int u, v, w;
    int z = (1 << 31) - 1;
    for (int i = 0;i < m;++i) {
        cin >> u >> v >> w;
        u--, v--;
        lj[u].push_back({ v,w });
    }
    for (int i = 0;i < n;++i)ans[i] = z;
    priority_queue < pt, vector<pt>, op> pq;
    pq.push({ s - 1,0 });
    while (!pq.empty()) {
        pt cut = pq.top();
        pq.pop();
        if (ans[cut.num] != z)continue;
        ans[cut.num] = cut.dis;
        for (pt nxt : lj[cut.num]) if (ans[nxt.num] == z) {
            pq.push({ nxt.num,nxt.dis + cut.dis });
        }
    }
    for (int i = 0;i < n;++i)cout << ans[i] << ' ';
}