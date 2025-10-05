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
    int n, q;std::cin >> n >> q;
    std::vector<int> a(n + 1), base(n + 1), cnt(n + 1);
    for (int i = 1;i <= n;++i) {
        std::cin >> a[i];
        int x = std::__lg(a[i]);
        base[i] = x + (a[i] != (1 << x) && a[i] != (1 << x) + 1);
        if (a[i] == (1 << x) + 1) cnt[i]++;
        base[i] += base[i - 1];
        cnt[i] += cnt[i - 1];
    }
    while (q--) {
        int l, r;std::cin >> l >> r;
        l--;
        int ans = base[r] - base[l] + (cnt[r] - cnt[l]) / 2;
        std::cout << ans << '\n';
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