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

int ask(i64 y, i64 n) {
    if (y > n) return 1;
    std::cout << "? " << y << std::endl;
    int r;std::cin >> r;
    return r;
}

void solve() {
    i64 n;std::cin >> n;
    std::vector<i64> a(32);
    a[1] = 2;
    for (int i = 2;i < 32;++i) {
        if (i % 2)a[i] = (a[i - 1] + 1) * 2;
        else a[i] = a[i - 1] * 2;
        std::cout << a[i] << '\n';
    }
    auto l = 1, r = 32;
    int cnt = 0;
    while (l < r) {
        cnt++;
        auto mid = l + r >> 1;
        if (ask(a[mid], n))r = mid;
        else l = mid + 1;
        if (cnt == 4)break;
    }
    std::cout << "! " << std::min(n, a[l]) << std::endl;
}

signed main() {
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}