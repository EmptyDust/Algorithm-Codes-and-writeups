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

int query(int a, int b) {
    std::cout << "?" << ' ' << a << ' ' << b << std::endl;
    int area;std::cin >> area;
    return area;
}

void solve() {
    auto l = 1, r = 1000;
    while (l < r) {
        int t1 = l + (r - l) / 3;
        int t2 = l + (r - l) / 3 * 2;
        int res = query(t1, t2);

        if (res == (t1 + 1) * (t2 + 1))r = t1;
        else if (res == t1 * (t2 + 1))l = t1 + 1, r = t2;
        else l = t2 + 1;
    }
    std::cout << "! " << l << std::endl;
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