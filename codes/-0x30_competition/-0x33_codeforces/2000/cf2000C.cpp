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
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    int m;std::cin >> m;
    for (int i = 0;i < m;++i) {
        std::string s;std::cin >> s;
        if (s.length() != n) {
            std::cout << "NO" << '\n';
            continue;
        }
        bool ok = true;
        std::map<char, int> mp1;
        std::map<int, char> mp2;
        for (int j = 0;j < n;++j) {
            if (!mp1.count(s[j]) && !mp2.count(a[j])) {
                mp1[s[j]] = a[j];
                mp2[a[j]] = s[j];
            }
            else if (mp1.count(s[j]) && mp2.count(a[j])) {
                if (mp1[s[j]] != a[j] || mp2[a[j]] != s[j]) {
                    ok = false;
                    break;
                }
            }
            else {
                ok = false;
                break;
            }
        }
        std::cout << (ok ? "YES" : "NO") << '\n';
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}