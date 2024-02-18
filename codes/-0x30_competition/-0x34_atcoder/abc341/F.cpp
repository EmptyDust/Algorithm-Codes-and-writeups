#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e4 + 10;
int w[MAXN], a[MAXN], c[MAXN], f[MAXN];
using pt = pair<int, int>;
vector<int> adj[MAXN];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m;cin >> n >> m;
    int u, v;
    for (int i = 0;i < m;++i) {
        cin >> u >> v;u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0;i < n;++i)cin >> w[i];
    iota(c, c + n, 0);
    sort(c, c + n, [&](int a, int b) {return w[a] < w[b];});
    for (int i = 0;i < n;++i) {
        int& cur = c[i];
        vector<int> bag(w[cur] + 1, 0);
        for (int nxt : adj[cur])
            for (int j = w[cur];j > w[nxt];--j)
                bag[j] = max(bag[j], bag[j - w[nxt]] + f[nxt]);
        f[cur] = bag[w[cur]] + 1;
    }
    int ans = 0;
    for (int i = 0;i < n;++i) {
        cin >> a[i];
        ans += a[i] * f[i];
        //cout << f[i] << ' ';
    }
    cout << ans;
    return 0;
}