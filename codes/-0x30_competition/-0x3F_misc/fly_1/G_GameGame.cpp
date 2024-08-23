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
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    std::vector<int> cnt(32);
    for (int& x : a) {
        for (int i = 0;i <= 30;++i) {
            if (x >> i & 1) {
                cnt[i]++;
            }
        }
    }
    for (int i = 30;i >= 0;--i) {
        if (cnt[i] % 2) {
            // if (cnt[i] == 1) {
            //     std::cout << "WIN";
            //     return;
            // }
            if (cnt[i] / 2 % 2) {
                if ((n - cnt[i]) % 2)
                    std::cout << "WIN";
                else
                    std::cout << "LOSE";
            }
            else {
                // if ((n - cnt[i]) % 2)
                //     std::cout << "LOSE";
                // else
                std::cout << "WIN";
            }
            return;
        }
    }
    std::cout << "DRAW";
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