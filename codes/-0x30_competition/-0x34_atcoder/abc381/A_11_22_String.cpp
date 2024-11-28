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
    if (n % 2 == 0) {
        std::cout << "No";
        return;
    }
    std::string s;std::cin >> s;
    bool ok = true;
    for (int i = 0;i < n / 2;++i)
        if (s[i] != '1')
            ok = false;
    if (s[n / 2] != '/') ok = false;
    for (int i = n / 2 + 1;i < n;++i)
        if (s[i] != '2')
            ok = false;
    std::cout << (ok ? "Yes" : "No");
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