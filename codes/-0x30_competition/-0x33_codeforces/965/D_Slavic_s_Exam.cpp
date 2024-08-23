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
    std::string s, t;std::cin >> s >> t;
    bool ok = false;
    int n = s.length(), m = t.length();
    for (int i = 0, j = 0;i < n;++i) {
        if (s[i] == '?')
            s[i] = t[j];
        if (s[i] == t[j]) {
            j++;
            if (j == m) {
                ok = true;
                break;
            }
        }
    }
    if (ok) {
        std::cout << "YES\n";
        for (char& ch : s)if (ch == '?')ch = 'a';
        std::cout << s;
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