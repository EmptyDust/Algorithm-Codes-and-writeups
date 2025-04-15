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
    i64 n, k, x;std::cin >> n >> k >> x;
    std::vector<i64> a(n);
    for (auto& x : a)std::cin >> x;
    i64 ans = 0, sum = std::accumulate(a.begin(), a.end(), 0ll);
    while (k && x > sum) {
        k--;
        x -= sum;
    }
    if (k) for (int i = n - 1;i >= 0;--i) {
        x -= a[i];
        if (x <= 0) {
            ans = i + 1 + n * (k - 1);
            break;
        }
    }
    std::cout << ans;
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