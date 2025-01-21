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
    int n;std::cin >> n;
    std::vector map(n, std::vector<int>(n));
    for (int i = 0;i < n;++i) {
        std::string s;std::cin >> s;
        for (int j = 0;j < n;++j) {
            map[i][j] = s[j] == '1';
        }
    }
    std::vector<int> a(n);
    std::iota(a.begin(), a.end(), 0);
    ranges::sort(a, [&](int x, int y) {
        if (x < y)return map[x][y] == 1;
        else return map[x][y] == 0;
        });
    for (int x : a)std::cout << x + 1 << ' ';
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