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
    int n;std::cin >> n;
    std::string s;std::cin >> s;
    std::string t;t.push_back(s[0]);
    for (int i = 1;i < n;++i)if (s[i] != s[i - 1])t.push_back(s[i]);
    int sz = t.size();
    int ans = 0;
    if (t.size() == 1)ans = 0;
    else if (t.size() == 2)ans = 1;
    else if (t.size() == 3)ans = 1;
    else if (t.size() >= 4)ans = sz - 3;
    ans += s.length();
    if (s[0] == '1' && (t.size() >= 4 || t.size() == 1))ans += 1;
    std::cout << ans;
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