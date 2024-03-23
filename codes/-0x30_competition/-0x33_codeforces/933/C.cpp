#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    int n;std::cin >> n;
    std::string s;std::cin >> s;
    int cnt = 0;
    for (int i = 0;i < n - 2;++i) {
        if (i < n - 4 && s.substr(i, 5) == "mapie") {
            cnt++;
            i += 4;
        }
        if (s.substr(i, 3) == "map" || s.substr(i, 3) == "pie") {
            cnt++;
            i += 2;
        }
    }

    std::cout << cnt;
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