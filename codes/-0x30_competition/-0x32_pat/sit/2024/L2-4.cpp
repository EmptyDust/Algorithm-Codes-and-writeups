#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e5 + 10;
int dsu[MAXN], n, m;
using pt = pair<int, int>;
vector<pt> adj[MAXN];

int get_root(int x) {
    return dsu[x] = (x == dsu[x] ? x : get_root(dsu[x]));
}
int ed;
bool f;
vector<int> ans;
bool dfs(int x, int pre) {
    if (x == ed)return f = true;
    for (auto [nxt, num] : adj[x])if (pre != nxt && dfs(nxt, x)) {
        ans.push_back(num);
        return true;
    }
    return false;
}

void solve() {
    cin >> n >> m;
    iota(dsu, dsu + n + 1, 0);
    ans.clear();
    int u, v;
    f = false;
    for (int i = 1;i <= m;++i) {
        cin >> u >> v;
        if (f)continue;
        if (get_root(u) == get_root(v)) {
            ed = v;
            dfs(u, -1);
            ans.push_back(i);
            sort(ans.begin(), ans.end());
            for (int j = 0;j < ans.size() - 1;++j)cout << ans[j] << ' ';
            cout << ans[ans.size() - 1];
            continue;
        }
        adj[u].push_back({ v,i });
        adj[v].push_back({ u,i });
        dsu[get_root(u)] = get_root(v);
    }
    if (!f)cout << -1;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
    return 0;
}