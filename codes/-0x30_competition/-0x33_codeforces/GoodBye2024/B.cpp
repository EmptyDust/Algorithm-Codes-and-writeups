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
    int n;std::cin >> n;
    std::vector<pii> info(n);
    std::vector<int> cnt(2 * n + 1);
    std::vector<int> f(2 * n + 1);
    for (auto& [l, r] : info) {
        std::cin >> l >> r;
        if (l == r) cnt[l]++;
    }
    for (int i = 1;i <= 2 * n;++i)f[i] = (cnt[i] > 0) + f[i - 1];
    std::string ans;
    for (auto& [l, r] : info) {
        if (l == r)ans += cnt[l] > 1 ? '0' : '1';
        else {
            ans += f[r] - f[l - 1] != r - l + 1 ? '1' : '0';
        }
    }
    std::cout << ans;
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