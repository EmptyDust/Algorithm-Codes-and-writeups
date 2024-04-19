#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    std::cin >> n;
    bool f = true;
    for (int i = 0;i < n;++i) {
        bool ff = f;
        for (int j = 0;j < n;++j) {
            if (ff)std::cout << "##";
            else std::cout << "..";
            ff = !ff;
        }
        std::cout << '\n';
        ff = f;
        for (int j = 0;j < n;++j) {
            if (ff)std::cout << "##";
            else std::cout << "..";
            ff = !ff;
        }
        std::cout << '\n';
        f = !f;
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