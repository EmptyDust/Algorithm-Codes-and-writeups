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
    int n, l;std::cin >> n >> l;
    if (l % 3) {
        std::cout << 0;
        return;
    }
    std::vector<int> cnt(l);
    int p = 0;
    cnt[p] = 1;
    for (int i = 0;i < n - 1;++i) {
        int x;std::cin >> x;
        p = (p + x) % l;
        cnt[p]++;
        // std::cout << p << ' ';
    }
    // for (auto x : cnt)std::cout << x << " ";
    i64 ans = 0;
    for (int i = 0;i < l / 3;++i) {
        int j = (i + l / 3) % l;
        int k = (i + l / 3 * 2) % l;
        ans += 1ll * cnt[i] * cnt[j] * cnt[k];
    }
    std::cout << ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}