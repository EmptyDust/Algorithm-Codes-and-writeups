#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pt = std::pair<int, int>;

int query(int l, int x) {
    std::cout << "? " << l << ' ' << x << std::endl;
    int ret;
    std::cin >> ret;
    return ret;
}

int answer(int m) {
    std::cout << "! " << m << std::endl;
    int ret;
    std::cin >> ret;
    return ret;
}

void solve() {
    int n, k;
    std::cin >> n >> k;
    int x = n;
    for (;x > 0;--x)if (query(1, x * n) != n + 1)break;
    if (x == -1) {
        answer(-1);
        return;
    }
    for (int m = n / k;m > 0;--m) {
        int l = 1;
        for (int i = 0;i < k;++i) {
            if (l > n)break;
            l = query(l, m * x);
            if (l == n + 1)
                break;
            if (i == k - 1 && l == n) {
                answer(m * x);
                return;
            }
            l++;
        }
    }
    answer(-1);
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