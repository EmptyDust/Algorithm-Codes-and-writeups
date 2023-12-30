#include <bits/stdc++.h>
#define int long long 
#define nxt first
#define wt second
using namespace std;

constexpr int MAXN = 2e3;
using vt = vector<int>;
using pt = pair<int, int>;
vector<pt> mp[MAXN];
int s[MAXN], dis[MAXN][1001];
bool vis[MAXN][1001];

struct cmp {
    bool operator()(vt a, vt b) {
        if (a[1] == b[1])return a[2] > b[2];
        return a[1] > b[1];
    }
};

void solve() {
    int n, m;cin >> n >> m;
    int x, y, w;
    for (int i = 0;i < n;++i)mp[i].clear();
    for (int i = 0;i < m;++i) {
        cin >> x >> y >> w;
        x--, y--;
        mp[x].push_back({ y,w });
        mp[y].push_back({ x,w });
    }
    for (int i = 0;i < n;++i)cin >> s[i];
    for (int i = 0;i < n;++i)for (int j = 0;j < 1001;++j)dis[i][j] = -1, vis[i][j] = false;

    priority_queue<vt, vector<vt>, cmp> pq;
    dis[0][s[0]] = 0;
    pq.push({ 0,0,s[0] });//to dis s
    while (!pq.empty()) {
        int cut = pq.top()[0], v = pq.top()[2];
        pq.pop();
        if (vis[cut][v])
            continue;
        vis[cut][v] = true;

        for (auto [nxt, ndis] : mp[cut]) {
            int nv = min(s[nxt], v);
            if (dis[nxt][nv] == -1 || dis[nxt][nv] > dis[cut][v] + ndis * v) {
                dis[nxt][nv] = dis[cut][v] + ndis * v;
                pq.push({ nxt,dis[nxt][nv], nv });
            }
        }
    }
    int ans = LLONG_MAX;
    for (int i = 0;i < 1001;++i)if (dis[n - 1][i] != -1)ans = min(ans, dis[n - 1][i]);
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    int t;cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
    return 0;
}