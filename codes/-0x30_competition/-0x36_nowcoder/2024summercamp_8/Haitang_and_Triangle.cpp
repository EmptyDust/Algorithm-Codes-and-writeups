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
    std::vector<int> a(n);a[0] = 2, a[1] = 3;
    for (int i = 0;i < m;++i) {
        a[i + 2] = i % 2 ? 3 : 2;
    }
    for (int i = 0;i < n;++i) {
        if (!a[i]) {
            if (a[i - 1] == 3)a[i] = 1;
            else if (a[i - 1] == 2)a[i] = 3;
            else a[i] = 2;
        }
    }
    for (int x : a)std::cout << x << " ";
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