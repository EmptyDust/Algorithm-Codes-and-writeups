#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    std::cin >> n;
    std::string s;std::cin >> s;
    int cnt = 0;
    for (auto ch : s) {
        if (ch == '1')cnt++;
    }
    if (cnt % 2) {
        std::cout << "No";
        return;
    }
    if (cnt == 2) {
        if (s.find("11") != -1) {
            std::cout << "No";
            return;
        }
    }
    std::cout << "Yes";
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