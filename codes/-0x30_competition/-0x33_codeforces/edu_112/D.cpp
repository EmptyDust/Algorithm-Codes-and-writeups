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
    int n, m;std::cin >> n >> m;
    std::string s;std::cin >> s;s = "#" + s;
    std::string t = "abc";
    std::vector pref(6, std::vector<int>(n + 1));int c = 0;
    do {
        // std::cout << t << ' ';
        for (int i = 1;i <= n;++i) {
            if (t[i % 3] != s[i]) pref[c][i]++;
            pref[c][i] += pref[c][i - 1];
        }
        // for (int j = 0;j <= n;++j)
        //     std::cout << pref[c][j] << ' ';
        // std::cout << '\n';
        c++;
    } while (std::next_permutation(t.begin(), t.end()));
    while (m--) {
        int l, r;std::cin >> l >> r;
        l--;
        int min = inf;
        for (int i = 0;i < 6;++i)
            min = std::min(min, pref[i][r] - pref[i][l]);
        std::cout << min << '\n';
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