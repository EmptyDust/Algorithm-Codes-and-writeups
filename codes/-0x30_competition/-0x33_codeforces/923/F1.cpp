#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6 + 10;
int cnts[MAXN], n;
using pt = pair<int, int>;
using pat = pair<int, pt>;
pat pts[MAXN];
vector<pt> lj[MAXN];
bool canuse[MAXN], color[MAXN];
#define x first
#define wt first
#define y second

stack<int> ans, tmp;
bool f;
int from;
void dfs(int to) {
    if (f)return;
    if (to == from) {
        if (tmp.size() == 1)return;
        f = true;
        ans = tmp;
        ans.push(to);
        return;
    }
    color[to] = false;
    tmp.push(to);
    for (auto [nxt, num] : lj[to])if (color[nxt]) {
        dfs(nxt);
    }
    tmp.pop();
    color[to] = true;
}

void solve() {
    int n, m;cin >> n >> m;
    for (int i = 1;i <= n;++i) {
        lj[i].clear();
        color[i] = true;
    }
    int u, v, w;
    for (int i = 0;i < m;++i) {
        cin >> u >> v >> w;
        pts[i].second.x = u;
        pts[i].second.y = v;
        pts[i].wt = w;
        lj[u].push_back({ v,i });
        lj[v].push_back({ u,i });
        cnts[v]++, cnts[u]++;
        canuse[i] = true;
    }
    vector<int> leaves;
    for (int i = 1;i <= n;++i)if (cnts[i] == 1) {
        leaves.push_back(i);
    }
    for (int i = 0;i < leaves.size();++i) {
        auto leave = leaves[i];
        for (auto [nxt, num] : lj[leave])if (canuse[num]) {
            canuse[num] = false;
            cnts[nxt]--;
            if (cnts[nxt] == 1)leaves.push_back(nxt);
        }
        color[leave] = false;
    }
    int sm = -1, now = INT_MAX;
    for (int i = 0;i < m;++i)if (canuse[i]) {
        if (now > pts[i].wt) {
            now = pts[i].wt;
            sm = i;
        }
    }
    f = false;
    from = pts[sm].second.x;
    dfs(pts[sm].second.y);
    cout << pts[sm].wt << ' ' << ans.size() << '\n';
    while (!ans.empty()) {
        cout << ans.top() << ' ';
        ans.pop();
    }
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