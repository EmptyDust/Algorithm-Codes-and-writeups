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
    int n;std::cin >> n;
    std::vector<int> a(n), idx(n);
    for (auto& x : a)std::cin >> x;
    std::iota(idx.begin(), idx.end(), 0);
    ranges::sort(idx, [&](int x, int y) {return a[x] < a[y];});
    i64 ans = 0;
    for (int i = 1;i < n;++i) {
        int pos = idx[i];
        int pre = idx[i - 1];
        int l = 0, r = 0;
        if (pos > pre) l = pre + 1, r = pos - pre;
        else l = pre - pos, r = n - pre;
        ans += 1ll * l * r * (i + 1);
        std::cout << 1ll * l * r * (i + 1) << '\n';
    }
    int pre = idx[n - 1];
    int l = pre + 1, r = n - pre;
    ans += 1ll * l * r * (n + 1);
    std::cout << 1ll * l * r * (n + 1) << '\n';
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