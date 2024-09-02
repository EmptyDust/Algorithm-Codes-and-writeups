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

bool query(int u, int v) {
    std::cout << "? " << u << ' ' << v << std::endl;
    int ret;std::cin >> ret;
    return ret;
}

void solve() {
    int n;std::cin >> n;
    for (int i = 1;i <= n;i += 2) {
        if (i != n) {
            int u = i, v = i + 1;
            if (query(u, v)) {
                int w;
                for (int i = 1;i <= n;++i)if (i != v && i != u) {
                    w = i;
                    break;
                }
                if (query(u, w)) {
                    int x;
                    for (int i = 1;i <= n;++i)if (i != v && i != u && i != w) {
                        x = i;
                        break;
                    }
                    if (query(u, x)) {
                        std::cout << "! 2" << std::endl;
                        return;
                    }
                    std::cout << "! 1" << std::endl;
                    return;
                }
                if (query(v, w)) {
                    int x;
                    for (int i = 1;i <= n;++i)if (i != v && i != u && i != w) {
                        x = i;
                        break;
                    }
                    if (query(v, x)) {
                        std::cout << "! 2" << std::endl;
                        return;
                    }
                    std::cout << "! 1" << std::endl;
                    return;
                }
                std::cout << "! 1" << std::endl;
                return;
            }
        }
        else {
            int u = i, v = 1, w = 2;
            if (query(u, v)) {
                if (query(u, w)) {
                    int x;
                    for (int i = 1;i <= n;++i)if (i != v && i != u && i != w) {
                        x = i;
                        break;
                    }
                    if (query(u, x)) {
                        std::cout << "! 2" << std::endl;
                        return;
                    }
                    std::cout << "! 1" << std::endl;
                    return;
                }
            }
        }
    }
    std::cout << "! 1" << std::endl;
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