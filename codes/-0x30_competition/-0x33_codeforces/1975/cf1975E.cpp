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

void solve() {
    int n, q;std::cin >> n >> q;
    std::vector<int> adj[n + 1];
    std::vector<int> col(n + 1), cnt(n + 1), fa(n + 1);
    for (int i = 1;i <= n;++i)std::cin >> col[i];
    for (int i = 1;i < n;++i) {
        int u, v;std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int faw = 0;
    int cnt2 = 0;
    int cnt_more = 0;
    int tot = 0;
    int xor_2 = 0;
    auto flip = [&](int u) {
        col[u] ^= 1;
        int d = col[u] ? 1 : -1;
        tot += d;
        if (!col[fa[u]])faw += d;
        if (cnt[u] == 2)cnt2 += d, xor_2 ^= u;
        if (cnt[u] > 2)cnt_more += d;
        faw -= d * cnt[u];
        if (col[u]) {
            if (col[fa[u]] && cnt[fa[u]] == 2)cnt2--, cnt_more++, xor_2 ^= fa[u];
            cnt[fa[u]]++;
            if (col[fa[u]] && cnt[fa[u]] == 2)cnt2++, xor_2 ^= fa[u];
        }
        else {
            if (col[fa[u]] && cnt[fa[u]] == 2)cnt2--, xor_2 ^= fa[u];
            cnt[fa[u]]--;
            if (col[fa[u]] && cnt[fa[u]] == 2)cnt2++, cnt_more--, xor_2 ^= fa[u];
        }
        };
    auto check = [&]() {
        if (!tot)return false;
        if (cnt_more)return false;
        if (cnt2 > 1)return false;
        if (faw > 1)return false;
        if (cnt2 && col[fa[xor_2]])return false;
        return true;
        };
    std::function<void(int, int)> dfs = [&](int u, int p) {
        fa[u] = p;
        for (int v : adj[u])if (v != p) {
            dfs(v, u);
            if (col[v])cnt[u]++;
        }
        if (!col[p] && col[u])faw++;
        if (col[u]) {
            tot++;
            if (cnt[u] == 2)cnt2++, xor_2 ^= u;
            if (cnt[u] >= 3)cnt_more++;
        }
        };
    dfs(1, 0);
    while (q--) {
        int u;std::cin >> u;
        flip(u);
        std::cout << (check() ? "Yes" : "No") << '\n';
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}