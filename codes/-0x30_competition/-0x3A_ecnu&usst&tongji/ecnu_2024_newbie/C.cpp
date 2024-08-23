#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, m, num, gcd;std::cin >> n >> m;
    std::cin >> gcd;
    for (int i = 1;i < n;++i) {
        std::cin >> num;
        gcd = std::gcd(gcd, num);
    }
    for (int i = 0;i < m;++i) {
        std::cin >> num;
        if (num % gcd == 0) {
            std::cout << "0 0 0";
            return 0;
        }
    }
    std::cout << "1 1 " << gcd;
    return 0;
}