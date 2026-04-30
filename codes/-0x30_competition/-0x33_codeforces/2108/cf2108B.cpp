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
    int n, x;std::cin >> n >> x;
    if (n == 1 && x == 0) {
        std::cout << -1;
        return;
    }
    std::vector<int> ans;
    for (int i = 30;i >= 0;--i)if (x >> i & 1) {
        ans.push_back(1 << i);
    }
    i64 sum = std::accumulate(ans.begin(), ans.end(), 0ll);
    // std::cout << ans.size() << '\n';
    bool f = 0;
    if (ans.size() < n) {
        sum += n - ans.size();
        f = (n - ans.size()) & 1;
    }
    if (f) {
        if (ans.empty() || ans.front() == 1) {
            sum++;
            sum += 2;
        }
        else sum++;
    }
    // for (auto x : ans)std::cout << x << ' ';
    std::cout << sum;
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