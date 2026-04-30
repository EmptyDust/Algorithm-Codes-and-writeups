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

std::vector<int> get_path(std::vector<int>& fa, int v) {
    std::vector<int> res;
    while (v != -1) {
        res.push_back(v);
        v = fa[v];
    }
    std::reverse(res.begin(), res.end());
    return res;
}

struct Info
{
    int a;
    Info operator+(Info x) {
        return Info(std::max(a, x.a));
    }
};

struct sparse_table
{
    std::vector<std::vector<Info>> vt;
    sparse_table(std::vector<Info> a) {
        int n = a.size();
        vt.assign(n, std::vector<Info>(30));
        for (int i = 0;i < n;++i)
            vt[i][0] = a[i];
        for (int s = 1;s < 30;++s) {
            for (int i = 0;i < n;++i) {
                int j = i + (1 << s - 1);
                if (j < n) {
                    vt[i][s] = vt[i][s - 1] + vt[i + (1 << s - 1)][s - 1];
                }
                else vt[i][s] = vt[i][s - 1];
            }
        }
    }
    Info query(int l, int r) {//[l,r)
        int len = r - l;
        int x = std::__lg(len);
        return vt[l][x] + vt[r - (1 << x)][x];
    }
};

void solve() {
    int n;std::cin >> n;
    std::vector g(n, std::vector<int>());
    for (int i = 1;i < n;++i) {
        int u, v;std::cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    std::vector<int> fa(n);
    std::function<void(int, int)> dfs = [&](int x, int p) {
        fa[x] = p;
        for (int v : g[x])if (v != p) {
            dfs(v, x);
        }
        };
    dfs(0, -1);
    int u, v;std::cin >> u >> v;
    u--, v--;
    auto path = get_path(fa, u);
    std::vector<int> use(n);
    for (int x : path)use[x] = 1;
    int pz = path.size();
    std::function<int(int)> another_dfs = [&](int x) {
        use[x] = 1;
        int ret = 1;
        for (int v : g[x])if (!use[v]) {
            ret = std::max(ret, another_dfs(v) + 1);
        }
        return ret;
        };
    std::vector<int> ctri(pz);
    std::vector<Info> max0ct(pz), maxuct(pz);
    for (int i = 0;i < pz;++i) {
        ctri[i] = another_dfs(path[i]);
        max0ct[i] = Info(ctri[i] + i);
        maxuct[i] = Info(ctri[i] + pz - 1 - i);
        // std::cout << path[i] + 1 << ' ';
    }

    sparse_table st0(max0ct), stu(maxuct);
    for (int i = 0, j = pz - 1;i < j;) {
        // std::cout << i << ' ' << j << '\n';
        // if (i == 1)std::cout << 'a';
        if (ctri[i] + i > stu.query(i + 1, j + 1).a) {
            std::cout << "Alice";
            return;
        }
        else ++i;
        if (i < j && ctri[j] + pz - 1 - j >= st0.query(i, j).a) {
            std::cout << "Bob";
            return;
        }
        else --j;
        if (i == j) {
            std::cout << "Alice";
            return;
        }
    }
    std::cout << "Bob";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}