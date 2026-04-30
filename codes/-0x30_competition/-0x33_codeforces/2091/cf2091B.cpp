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
    i64 n, x;std::cin >> n >> x;
    std::vector<int> a(n);
    for (auto& x : a)std::cin >> x;
    ranges::sort(a, std::greater<int>());
    i64 res = 0, cnt = 0;
    int ans = 0;
    for (int i = 0;i < n;++i) {
        cnt++;
        res = cnt * a[i];
        if (res >= x) {
            ans++;
            cnt = 0;
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