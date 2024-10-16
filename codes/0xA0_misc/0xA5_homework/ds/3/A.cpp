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


int bruteforce(std::string& s, std::string& t) {
    int n = s.length(), m = t.length();
    for (int i = 0;i < n - m + 1;++i) {
        bool ok = true;
        for (int j = 0;j < m;++j) {
            if (s[i + j] != t[j]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            return i;
        }
    }
    return -1;
}

void solve() {
    std::string s, t;std::cin >> s >> t;
    std::cout << bruteforce(s, t) << '\n';
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