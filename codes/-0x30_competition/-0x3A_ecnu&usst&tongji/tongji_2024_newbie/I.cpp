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
    std::string s;std::cin >> s;
    int n = s.length();
    i64 ans = 0;
    {
        i64 cnt = 0, cur = 0;
        for (int i = 0;i < n;++i) {
            cur += cnt;
            if (s[i] == '1')cnt++;
            else ans += cur;
        }
    }
    {
        i64 cnt = 0, cur = 0;
        for (int i = n - 1;i >= 0;--i) {
            cur += cnt;
            if (s[i] == '1')cnt++;
            else ans += cur;
        }
    }
    std::cout << ans;
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