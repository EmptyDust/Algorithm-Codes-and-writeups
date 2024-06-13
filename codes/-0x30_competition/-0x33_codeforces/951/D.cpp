#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int n, k;
using pt = std::pair<int, int>;
std::string s;
bool test(int pos) {
    if (pos > n || pos < 1)return false;
    std::string x = s.substr(0, pos);
    std::reverse(x.begin(), x.end());
    x = s.substr(pos, n - pos) + x;
    bool f = x[0] - '0';f = !f;
    for (int i = 0;i < n;++i) {
        if (i % k == 0)f = !f;
        bool g = x[i] - '0';
        if (g != f) {
            return false;
        }
    }
    return true;
}

void solve() {
    std::cin >> n >> k;
    std::cin >> s;
    bool f = s[0] - '0';f = !f;
    for (int i = 0;i < n;++i) {
        if (i % k == 0)f = !f;
        bool g = s[i] - '0';
        if (g != f) {
            if (test(i)) {
                std::cout << i;
                return;
            }
            int cnt = 0;
            for (int j = i;j < n;++j) {
                if (s[j] == s[i])cnt++;
                else break;
            }
            if (test(i - k + cnt)) {
                std::cout << i - k + cnt;
                return;
            }
            std::cout << -1;
            return;
        }
    }
    std::cout << n;
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