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
    std::string s, t;std::cin >> s >> t;
    std::vector<int> cnt(26);
    for (auto ch : t) cnt[ch - 'a']++;
    for (auto ch : s) cnt[ch - 'a']--;
    for (int x : cnt) if (x < 0) {
        std::cout << "Impossible";
        return;
    }
    std::string ans;
    for (auto ch : s) {
        int c = ch - 'a';
        for (int x = 0;x < c;++x) {
            while (cnt[x]) {
                ans += 'a' + x;
                cnt[x]--;
            }
        }
        ans += ch;
    }
    for (int x = 0;x < 26;++x) {
        while (cnt[x]) {
            ans += 'a' + x;
            cnt[x]--;
        }
    }
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