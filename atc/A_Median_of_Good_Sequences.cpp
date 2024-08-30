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
    int n, k;std::cin >> n >> k;
    int mid = (n + 1) / 2;
    if (n % 2 == 0) {
        std::cout << mid << ' ';
        for (int i = n;i >= 1;--i) {
            for (int j = 0;j < k - (i == mid);++j) {
                std::cout << i << ' ';
            }
        }
    }
    else {
        for (int i = 0;i < k;++i)std::cout << mid << ' ';
        mid--;
        if (!mid)return;
        std::cout << mid << ' ';
        for (int i = n;i >= 1;--i) {
            if (i != mid + 1)
                for (int j = 0;j < k - (i == mid);++j) {
                    std::cout << i << ' ';
                }
        }
    }
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