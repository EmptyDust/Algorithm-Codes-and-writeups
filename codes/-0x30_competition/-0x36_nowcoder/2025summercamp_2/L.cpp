#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<int, 2>;
using a3 = std::array<i64, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

struct info
{
    a3 unselected;
    a3 selected;
};


void solve() {
    int n;std::cin >> n;
    std::vector next(n, std::vector<int>());
    for (int i = 0;i < n;++i) {
        int fa;std::cin >> fa;fa--;
        next[fa].push_back(i);
    }
    std::vector<int> vis(n), on_c(n), in_stack(n), stack;
    auto find_cir = [&](auto&& find_cir, int u)->bool {
        if (in_stack[u]) {
            for (auto x : stack) on_c[x] = 1, in_stack[x] = 0;
            stack.clear();
            return 1;
        }
        if (vis[u]) return 0;
        vis[u] = 1;
        in_stack[u] = 1;
        stack.push_back(u);
        for (auto v : next[u]) {
            if (find_cir(find_cir, v)) {
                return 1;
            }
        }
        stack.pop_back();
        in_stack[u] = 0;
        return 0;
        };
    for (int i = 0;i < n;++i) if (!vis[i]) {
        find_cir(find_cir, i);
    }
    vis.assign(n, 0);
    std::vector<info> res;
    std::vector<int> color(n), cnt(n), size(n);
    i64 res0 = 1, res1 = 2, res0_2 = 1;
    int cnt = 0;
    auto dfs = [&](auto&& dfs, int u) ->int {
        for (auto v : next[u])if (!on_c[v]) {
            cnt[u] += dfs(dfs, v);
            if (!color[v]) color[u]++;
        }
        return cnt[u] += std::max(0, color[u] - 1);
        };
    for (int i = 0;i < n;++i) if (on_c[i]) {
        dfs(dfs, i);
        // cnt[i] == 0 => res0&yes = 1, res1&no = 1
        // cnt[i] == 1 => res1&yes = 2, res2&no = 1
    }
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
