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

int query(int l, int r) {
    std::cout << "? " << l << ' ' << r << std::endl;
    int rt;std::cin >> rt;
    return rt;
}

void solve() {
    int n;std::cin >> n;
    int lg = std::__lg(n);
    int ans = 0;
    if (query(1, n / 2)) {
        int le = query(1, n / 4);
        int ri = query(n / 4 + 1, n / 2);
        if (le && ri) {
            // k < n / 4 && one > n / 2
            for (int i = lg - 2;i > 0;--i) {
                if (!query(ans, ans + (1 << i))) {
                    ans |= 1 << i;
                }
            }
        }
        else if (le || ri) {
            // k > n / 2 && one < n / 2
        }
        else if (!le && !ri) {
            // n / 4 < k <= n / 2 && one < n / 2

        }
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