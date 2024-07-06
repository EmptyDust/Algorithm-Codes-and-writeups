#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int n;
using pii = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    std::string s;std::cin >> s;
    int x = std::count(s.begin(), s.end(), '0'), y = n - x;
    if (!x || !y) {
        std::cout << 0;
    }
    else if (x != y) {
        std::cout << 1;
    }
    else if (n == 2) {
        std::cout << -1;
    }
    else {
        std::cout << 2;
    }
    //011100
    return 0;
}