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
    i64 n, c1, c2;std::cin >> n >> c1 >> c2;
    i64 ans = 0;
    for (int i = 0;i < n;++i) {
        std::string s;std::cin >> s;
        std::map<char, int> mp;
        for (char ch : s)mp[ch]++;
        int sz = mp.size();
        if (sz == 1) ans += std::min({ c2 + c1, c1 * 3 , c2 * 2 });
        if (sz == 2)ans += std::min({ c2 + c1,c1 * 3,c2 * 2 });
        if (sz == 3)ans += std::min(c2 * 3, c1 * 3);
    }
    std::cout << ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;//std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}