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
    int n, M, D;std::cin >> n >> M >> D;
    std::vector<int> a(M * D + 2);
    for (int i = 0;i < n;++i) {
        int m0, d0, m1, d1;
        std::cin >> m0 >> d0 >> m1 >> d1;
        a[(m0 - 1) * D + d0]++;
        a[(m1 - 1) * D + d1 + 1]--;
    }
    for (int i = 1;i <= M * D;++i) {
        a[i] += a[i - 1];
        if (a[i] == 0) {
            std::cout << (i - 1) / D + 1 << ' ' << (i - 1) % D + 1;
            return;
        }
    }
    std::cout << "Online";
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