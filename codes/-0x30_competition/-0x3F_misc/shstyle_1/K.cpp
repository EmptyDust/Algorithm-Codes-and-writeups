#include <bits/stdc++.h>
// #include<bits/extc++.h>

// using namespace __gnu_pbds;

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

// using int_rb_tree = tree<int, null_type, std::less<int>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n;std::cin >> n;
    std::vector<i64> a(n), idx(n);
    for (i64& x : a)std::cin >> x;
    std::set<int> t1, t2;
    std::iota(idx.begin(), idx.end(), 0);
    ranges::sort(idx, [&](int x, int y) {return a[x] > a[y];});
    i64 ans = 0;
    for (i64 x : idx) {
        auto p = t1.lower_bound(x);
        i64 tmp = 1e9;
        if (p != t1.end()) {
            tmp = std::min(tmp, std::abs(*p - x));
        }
        p = t2.lower_bound(-x);
        if (p != t2.end()) {
            // std::cout << (*p) << ' ';
            tmp = std::min(tmp, std::abs(*p + x));
        }
        if (tmp != 1e9)
            ans += tmp;
        t1.insert(x);
        t2.insert(-x);
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