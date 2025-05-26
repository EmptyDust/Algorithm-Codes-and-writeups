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
    int n, m, k;std::cin >> n >> m >> k;
    int len = std::max(k, n / (m + 1));
    std::vector<int> a;
    for (int i = 0;i < m + 1;++i)for (int j = 0;j < len;++j)if (a.size() < n)a.push_back(j);
    while (a.size() < n)a.push_back(0);
    for (auto& x : a)std::cout << x << " ";
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