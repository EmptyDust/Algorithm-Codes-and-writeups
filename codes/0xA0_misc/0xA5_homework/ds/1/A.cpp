#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 6;
const int MAXN = 33;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

i64 comb_1702[MAXN][MAXN];
void init(int n) {
    for (int i = 0;i <= n;++i) {
        comb_1702[i][0] = 1;
        for (int j = 1;j <= i;++j) {
            comb_1702[i][j] = comb_1702[i - 1][j - 1] + comb_1702[i - 1][j];
        }
    }
}

void solve() {
    int n;std::cin >> n;
    init(n);
    for (int i = 0;i < n;++i) {
        for (int j = 0;j <= i;++j) {
            std::cout << comb_1702[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
