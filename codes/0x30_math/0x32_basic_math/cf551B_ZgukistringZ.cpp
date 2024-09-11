#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<i64, i64>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    std::string s, a, b;std::cin >> s >> a >> b;
    int n = s.length();
    std::vector<i64> mp(26), mp1(26), mp2(26);
    for (auto ch : s)mp[ch - 'a']++;
    for (auto ch : a)mp1[ch - 'a']++;
    for (auto ch : b)mp2[ch - 'a']++;

    pii ans = { 0,0 };
    int cur = 0;
    for (int x = 0;x < n;++x) {
        bool ok = true;
        i64 y = inf;
        for (int j = 0;j < 26;++j) {
            if (mp1[j] * x > mp[j]) {
                ok = false;
                break;
            }
            if (mp2[j])
                y = std::min(y, (mp[j] - x * mp1[j]) / mp2[j]);
        }
        if (ok) {
            if (x + y > cur) {
                cur = x + y;
                ans = { x,y };
            }
        }
    }
    auto [x, y] = ans;
    for (int i = 0;i < x;++i) {
        std::cout << a;
    }
    for (int i = 0;i < y;++i) {
        std::cout << b;
    }
    for (int i = 0;i < 26;++i) {
        mp[i] = mp[i] - mp1[i] * x - mp2[i] * y;
    }
    for (int c = 0;c < 26;++c) {
        char ch = c + 'a';
        while (mp[c]--) {
            std::cout << ch;
        }
    }
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