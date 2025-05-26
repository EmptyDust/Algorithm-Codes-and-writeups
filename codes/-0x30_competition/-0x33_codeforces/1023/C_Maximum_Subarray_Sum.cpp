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
    i64 n, k;std::cin >> n >> k;
    std::string mem;std::cin >> mem;
    std::vector<i64> a(n), p(n), tag(n);
    for (auto& x : a)std::cin >> x;

    i64 max = 0, cur = 0;
    for (int i = 0, j = 0;i < n;++i) {
        cur += a[i];
        if (cur < 0) tag[i] = -cur;
        cur = std::max(0ll, cur);
        p[i] = cur;
    }
    i64 c = 1e18;
    for (int i = n - 1;i >= 0;--i) {
        c = std::min(c, k - p[i]);
        if (tag[i]) {
            c += tag[i];
        }
        if (mem[i] == '0') {
            a[i] = c;
            c = 0;
        }
    }
    max = 0, cur = 0;
    for (int i = 0, j = 0;i < n;++i) {
        cur += a[i];
        cur = std::max(0ll, cur);
        max = std::max(max, cur);
    }
    if (max == k) {
        std::cout << "Yes\n";
        for (auto x : a)std::cout << x << ' ';
    }
    else std::cout << "No";
    // for (auto x : a)std::cout << x << ' ';
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