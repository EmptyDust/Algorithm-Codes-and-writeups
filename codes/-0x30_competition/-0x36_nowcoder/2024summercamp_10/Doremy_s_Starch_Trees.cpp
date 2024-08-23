#include <bits/stdc++.h>

// #pragma GCC optimize("O2")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC target("sse4,popcnt,abm,mmx")


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

char buf[1 << 20], * p1, * p2;
#define GC (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?0:*p1++)
inline int read() {
    int x = 0, f = 1;char ch = GC;
    while (ch < '0' || ch>'9') { if (ch == '-')f = -1;ch = GC; }
    while (ch >= '0' && ch <= '9') { x = (x << 1) + (x << 3) + (ch ^ 48);ch = GC; }
    return x * f;
}

void solve() {
    int n = read();
    std::vector<int> px[n];
    std::vector<int> py[n];
    for (int i = 1;i < n;++i) {
        int a = read();a--;
        px[i].push_back(a);
        px[a].push_back(i);
    }
    for (int i = 1;i < n;++i) {
        int a = read();a--;
        py[i].push_back(a);
        py[a].push_back(i);
    }
    //
    std::vector<int> alld(n);
    for (int u = 0;u < n;++u) {
        for (int v : px[u]) {
            alld[v]++;
        }
    }
    //pair<
    std::vector<pii> dfsx(n);
    int idx = 1;
    std::function<int(int, int)> dfs2 = [&](int u, int p) {
        dfsx[u].first = dfsx[u].second = idx++;
        for (int v : py[u])if (v != p) {
            dfsx[u].second = std::max(dfsx[u].second, dfs2(v, u));
        }
        return dfsx[u].second;
        };
    dfs2(0, -1);
    //计算root == 0情况
    std::unordered_map<int, int> st[n];
    auto merge = [&](int x, int y) {//x -> y
        if (st[x].size() > st[y].size())std::swap(st[x], st[y]);
        for (auto [x, cnt] : st[x])st[y][x] += cnt;
        st[x].clear();
        };
    std::vector<int> cf(n + 2);
    std::function<void(int, int)> dfs = [&](int u, int p) {
        for (int x : px[u]) {
            st[u][x]++;
        }
        for (int v : py[u])if (v != p) {
            dfs(v, u);
            merge(v, u);
        }
        if (p != -1) {
            if (st[u].count(p)) {
                cf[1]++;
                cf[dfsx[u].first]--;
                cf[dfsx[u].second + 1]++;
                cf[n + 1]--;
            }
            if (alld[u] - st[u][u] > 0) {
                cf[dfsx[u].first]++;
                cf[dfsx[u].second + 1]--;
            }
        }
        // if (p != -1)
        //     for (int x : px[u])if (st[u].count(x)) {

        //     }
        };
    dfs(0, -1);
    for (int i = 1;i <= n;++i)cf[i] += cf[i - 1];
    // for (int i = 1;i <= n;++i) {
    //     std::cout << i << ' ' << cf[i] << '\n';
    // }
    for (int u = 0;u < n;++u) {
        if (cf[dfsx[u].first] == n - 1) {
            std::cout << u + 1 << '\n';
            return;
        }
    }
    std::cout << -1 << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = read();
    while (t--) {
        solve();
    }
    return 0;
}