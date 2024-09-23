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
    int n, m;std::cin >> n >> m;
    std::vector<int> appear(m + 1), mex(m + 1), dp(m + 1);
    int maxele = m;
    for (int i = 0;i < n;++i) {
        int x;std::cin >> x;
        appear[x] = 1;
    }
    for (int i = 1;i <= m;++i)dp[i] = i;
    for (int L = m;L >= 1;--L) {
        
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