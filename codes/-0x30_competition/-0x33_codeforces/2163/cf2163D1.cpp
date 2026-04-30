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
    std::vector<a2> info(q);
    for (auto& [l, r] : info)std::cin >> l >> r;
    ranges::sort(info);
    std::vector<int> f(n + 1);
    std::vector<a2> wait;
    for (auto [l, r] : info) f[l] = r;
    for (int i = 1, j = 0;i <= n;++i) {
        if (j < f[i]) {
            j = f[i];
            wait.push_back({ i, j });
        }
    }
    auto ask = [&](int L, int R) {
        // std::cout << L << " " << R << "\n";
        std::cout << "? " << wait[L][0] << ' ' << wait[R - 1][1] << std::endl;
        int x;std::cin >> x;
        return x;
        };
    std::vector<int> pow2(20);
    pow2[0] = 1;
    for (int i = 1;i < 20;++i) pow2[i] = 2 * pow2[i - 1];
    int m = wait.size();
    int l = 0, r = m;
    int ans = 0;
    // if (m == 1) {
    //     ans = ask(0, 1);
    //     std::cout << "! " << ans << std::endl;
    //     return;
    // }
    for (int i = std::__lg(m);i >= 0;--i) {
        int mid = l + pow2[i];
        if (mid > r)continue;
        if (mid == r) {
            ans = ask(l, mid);
            continue;
        }
        int x = ask(l, mid);
        int y = ask(mid, r);
        if (x > y) r = mid, ans = x;
        else l = mid, ans = y;
    }
    std::cout << "! " << ans << std::endl;
}

signed main() {
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}