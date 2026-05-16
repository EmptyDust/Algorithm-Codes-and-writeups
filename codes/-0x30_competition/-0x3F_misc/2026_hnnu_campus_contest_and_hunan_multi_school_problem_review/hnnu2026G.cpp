#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<int, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &x : a)
        std::cin >> x;
    ranges::sort(a);
    std::vector<int> ok(1 << 20);
    std::vector<int> exist(1 << 20);
    for (auto x : a)
        exist[x] = 1;
    auto dfs = [&](this auto &&dfs, int p) -> void {
        if (ok[p])
            return;
        ok[p] = 1;
        if (exist[p])
            dfs(((1 << 20) - 1) ^ p);
        for (int i = 0; i < 20; ++i) {
            if (p >> i & 1) {
                dfs(p ^ (1 << i));
            }
        }
    };
    i64 ans = 0;
    for (auto x : a) {
        if (ok[x]) {
            ans += x;
        } else {
            dfs(((1 << 20) - 1) ^ x);
        }
    }
    std::cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}