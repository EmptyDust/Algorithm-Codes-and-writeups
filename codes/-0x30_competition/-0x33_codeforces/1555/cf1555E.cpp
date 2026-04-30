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
    int n;std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a)std::cin >> x;
    auto check = [&](int l, int r, int p) {
        for (int i = l;i <= r;++i) {
            for (int j = i + 1;j <= r;++j) {
                if (std::min(a[i], a[p]) <= a[j] && a[j] <= std::max(a[i], a[p])) {
                    return false;
                }
            }
        }
        return true;
        };
    int cnt = n;
    for (int i = 0;i < n;++i) {
        for (int j = i + 1;j < n;++j) {
            // std::cout << i << ' ' << j << ' ' << check(i, j - 1, j) << '\n';
            if (check(i, j - 1, j)) cnt++;
            else break;
        }
    }
    std::cout << cnt;
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