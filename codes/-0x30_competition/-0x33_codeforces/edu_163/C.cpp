#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

bool solve() {
    std::cin >> n;
    std::string s, t;
    std::cin >> s >> t;
    std::vector<std::vector<int>> map(n, std::vector<int>(2));
    for (int i = 0;i < n;++i) {
        map[i][0] = s[i] == '>';
        map[i][1] = t[i] == '>';
    }
    for (int i = 0;i < n;++i) {
        if (i % 2) {
            if (!map[i][0] && i < n - 1 && !map[i + 1][1]) {
                return false;
            }
        }
        else {
            if (!map[i][1] && i < n - 1 && !map[i + 1][0]) {
                return false;
            }
        }
    }
    return true;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        std::cout << (solve() ? "Yes" : "No");
        std::cout << '\n';
    }
    return 0;
}