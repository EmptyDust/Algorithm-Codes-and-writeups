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
    std::string ss[2];std::cin >> ss[0] >> ss[1];
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0;i < n;++i) {
        cnt1 += ss[i % 2][i] == '0';
    }
    for (int i = 0;i < n;++i) {
        cnt2 += ss[i % 2 == 0][i] == '0';
    }
    if (cnt1 >= n / 2 + n % 2 && cnt2 >= n / 2) {
        std::cout << "YES";
    }
    else std::cout << "NO";
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