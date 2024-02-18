#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6 + 10;
using pt = pair<int, int>;
int dsu[MAXN];
vector<int> lj[MAXN];
bool color[MAXN];
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
    for (auto nxt : lj[to])if (color[nxt]) {
        dfs(nxt);
    }
    tmp.pop();
    color[to] = true;
}

int get_root(int x) {
    return dsu[x] = (x == dsu[x] ? x : get_root(dsu[x]));
}

void solve() {
    int n, m;cin >> n >> m;
    for (int i = 1;i <= n;++i) {
        lj[i].clear();
        color[i] = true;
    }
    vector<array<int, 3>> edges(m);
    iota(dsu, dsu + n + 1, 0);
    int u, v, w;
    for (int i = 0;i < m;++i) {
        cin >> u >> v >> w;
        edges[i] = { w,u,v };
    }
    sort(edges.begin(), edges.end(), [&](auto a, auto b) {return a[0] > b[0];});

    int ansu, ansv, answ;
    for (auto [w, u, v] : edges) {
        if (get_root(u) == get_root(v)) {
            ansu = u;
            ansv = v;
            answ = w;
        }
        else {
            dsu[get_root(u)] = get_root(v);
            lj[u].push_back(v);
            lj[v].push_back(u);
        }
    }

    f = false;
    from = ansu;
    dfs(ansv);
    cout << answ << ' ' << ans.size() << '\n';
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