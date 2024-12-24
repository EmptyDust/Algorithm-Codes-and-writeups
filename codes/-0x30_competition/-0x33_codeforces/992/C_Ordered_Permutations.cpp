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
    i64 n, k;std::cin >> n >> k;
    if (n < 45 && (1ll << n - 1) < k) {
        std::cout << -1;
        return;
    }
    k--;
    std::deque<int> ans;
    ans.push_back(n);
    for (int i = n - 1;i >= 1;--i) {
        if (k & 1) ans.push_back(i);
        else ans.push_front(i);
        k /= 2;
    }
    while (ans.size()) {
        std::cout << ans.front() << ' ';
        ans.pop_front();
    }
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