#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for (int& x : nums)std::cin >> x;
    std::map<int, int> mp;
    for (int x : nums)mp[x]++;
    for (auto [x, cnt] : mp)if (cnt >= 3) {
        std::cout << "YES";
        return 0;
    }
    std::cout << "NO";
    return 0;
}