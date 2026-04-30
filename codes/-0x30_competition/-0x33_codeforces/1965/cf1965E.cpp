#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    int n;std::cin >> n;
    std::string s;std::cin >> s;
    int l = 0, r = 0, i = 0;
    for (char ch : s) {
        if (ch - '0' == (i % 2 + 2) % 2) {
            i++;
            r = std::max(r, i);
        }
        else {
            i--;
            l = std::min(l, i);
        }
    }
    std::cout << r - l;
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