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
    std::vector<int> a(m), b(k);
    for (int& x : a)std::cin >> x;
    for (int& x : b)std::cin >> x;
    if (n == k) {
        std::cout << std::string(m, '1');
        return;
    }
    if (n == k + 1) {
        int q = n;
        for (int i = 0;i < k;++i) {
            if (b[i] != i + 1) {
                q = i + 1;
                break;
            }
        }
        std::string ans;
        for (int i = 0;i < m;++i) {
            ans += a[i] == q ? '1' : '0';
        }
        std::cout << ans;
        return;
    }
    std::cout << std::string(m, '0');
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