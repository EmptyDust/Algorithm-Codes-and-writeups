#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

int query(int u, int v){
    std::cout << "? " << u << ' ' << v << std::endl;
    int res;std::cin >> res;
    if (res == 1)res = 2;
    else if (res == 2)res = 1;
    return res;
}

void solve() {
    int n;std::cin >> n;
    std::vector<a3> adj(n + 1);
    for (int i = 1;i <= n;++i){
        int u, v;std::cin >> u >> v;
        adj[i][0] = u;
        adj[i][1] = v;
        adj[u][2] = i;
        adj[v][2] = i;
    }
    int root = -1;
    for (int i = 1;i <= n;++i){
        if (adj[i][2] == 0)root = i;
    }
    std::vector<int> tag(n + 1, 1);tag[0] = 0;
    std::vector<a3> count(n + 1);
    auto dfs1 = [&](auto&& self, int u)->int{
        if (!u)return 0;
        if (!tag[u])return 0;
        count[u][0] = self(self, adj[u][0]);
        count[u][1] = self(self, adj[u][1]);
        return count[u][0] + count[u][1] + 1;
        };
    auto dfs2 = [&](auto&& self, int u, int cnt)->void{
        if (!u)return;
        if (!tag[u])return;
        count[u][2] = cnt;
        self(self, adj[u][0], cnt + count[u][1] + 1);
        self(self, adj[u][1], cnt + count[u][0] + 1);
        };
    auto dfs3 = [&](auto&& self, int u)->int{
        if (!u)return -1;
        if (tag[u])return u;
        return std::max(self(self, adj[u][0]), self(self, adj[u][1]));
        };
    auto dfs4 = [&](auto&& self, int u, int p)->void{
        if (!u)return;
        if (!tag[u])return;
        tag[u] = 0;
        for (int x : adj[u])if (x != p){
            self(self, x, u);
        }
        };
    while (1){
        int cnt = std::accumulate(tag.begin(), tag.end(), 0);
        if (cnt == 1)break;
        if (cnt == 2){
            int x = -1, y = -1;
            for (int i = 1;i <= n;++i){
                if (tag[i]){
                    if (x != -1)y = i;
                    else x = i;
                }
            }
            int r = query(x, y);
            if (r == 0)tag[y] = 0;
            else tag[x] = 0;
            break;
        }
        count.assign(n, a3());
        int rt = dfs3(dfs3, root);
        // std::cout << rt << ' ';
        dfs1(dfs1, rt);
        dfs2(dfs2, rt, 0);
        int min = inf, minp = -1;
        for (int i = 1;i <= n;++i)if (tag[i]){
            int c = std::max({ count[i][0],count[i][1],count[i][2] });
            if (c < min){
                minp = i;
                min = c;
            }
        }
        // std::cout << minp << ' ';
        // for (int x : count[minp])std::cout << x << ' ';
        std::vector<int> tmp(3);std::iota(tmp.begin(), tmp.end(), 0);
        std::sort(tmp.begin(), tmp.end(), [&](auto a, auto b){return count[minp][a] > count[minp][b];});
        int x = query(adj[minp][tmp[0]], adj[minp][tmp[1]]);
        // std::cout << x << ' ';break;
        for (int i = 0;i < 3;++i){
            if (x != i){
                // std::cout << adj[minp][tmp[i]] << ' ';
                dfs4(dfs4, adj[minp][tmp[i]], minp);
                // std::cout << tag[adj[minp][tmp[i]]] << ' ';
            }
        }
        if (x != 2)tag[minp] = 0;
        // break;
        // for (int x : tag)std::cout << x << " ";std::cout << std::endl;
    }
    int ans = std::find(tag.begin(), tag.end(), 1) - tag.begin();
    std::cout << "! " << ans << std::endl;
}

signed main() {
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}