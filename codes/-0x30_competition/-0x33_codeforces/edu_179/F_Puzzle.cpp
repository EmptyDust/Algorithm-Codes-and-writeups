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
    int D, S;std::cin >> D >> S;
    for (int a = 1;a * a <= 5e4;++a) {
        for (int b = 1;a * b <= 5e4;++b) {
            int d = (a + b) * 2;
            int s = a * b;
            if (d * S % D == 0) {
                int cnt = d * S / D;
                if (a + b - 1 <= cnt && cnt <= s) {
                    std::cout << cnt << '\n';
                    for (int i = 0;i < a;++i)std::cout << i << ' ' << 0 << '\n';
                    for (int i = 1;i < b;++i)std::cout << 0 << ' ' << i << '\n';
                    int c = cnt - a - b + 1;
                    for (int i = 1;i < a && c;++i) {
                        for (int j = 1;j < b && c;++j) {
                            std::cout << i << ' ' << j << '\n';
                            c--;
                        }
                    }
                    return;
                }
            }
        }
    }
    std::cout << -1 << '\n';
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