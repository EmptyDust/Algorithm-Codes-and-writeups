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
    std::vector<int> a(n), use(n), ans;
    int gcd = 0;
    for (int& x : a) {
        std::cin >> x;
        gcd = std::__gcd(gcd, x);
    }
    ranges::sort(a);
    use[0] = 1;
    ans.push_back(a[0]);
    int now = a[0];
    while (now != gcd) {
        int nnow = now;
        int p = -1;
        for (int i = 0;i < n;++i)if (!use[i]) {
            int g = std::__gcd(a[i], now);
            if (g < nnow) {
                nnow = g;
                p = i;
            }
        }
        ans.push_back(a[p]);
        use[p] = 1;
        now = nnow;
    }
    for (int i = 0;i < n;++i)if (!use[i]) {
        ans.push_back(a[i]);
    }
    i64 res = 0;
    for (int i = 0, g = 0;i < n;++i) {
        g = std::__gcd(g, ans[i]);
        res += g;
    }
    std::cout << res;
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