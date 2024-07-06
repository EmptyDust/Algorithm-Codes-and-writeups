#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n;std::cin >> n;
    std::vector<std::string> names[n];
    for (int i = 0;i < n;++i) {
        int x;std::cin >> x;
        names[i].resize(x);
        for (auto& str : names[i])std::cin >> str;
    }
    int q;std::cin >> q;
    while (q--) {
        std::string s;std::cin >> s;
        bool f = false;
        for (int i = 0;i < n;++i) {
            if (std::count(names[i].begin(), names[i].end(), s)) {
                if (names[i].size() == 1) {
                    std::cout << "Walk Alone";
                }
                else {
                    for (auto& str : names[i])if (str != s) {
                        std::cout << str << ' ';
                    }
                }
                f = true;
                break;
            }
        }
        if (!f) {
            std::cout << "Startliner";
        }
        std::cout << '\n';
    }
    return 0;
}