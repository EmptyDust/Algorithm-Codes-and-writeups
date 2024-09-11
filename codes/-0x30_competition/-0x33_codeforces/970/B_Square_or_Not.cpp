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
    std::string s;std::cin >> s;
    int sq = std::sqrt(n);
    if (sq * sq != n) {
        std::cout << "No";
        return;
    }
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1;i < sq - 1;++i) {
        for (int j = 1;j < sq - 1;++j) {
            if (s[i * sq + j] != '0') {
                std::cout << "No";
                return;
            }
        }
    }
    std::cout << "Yes";
    return;
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