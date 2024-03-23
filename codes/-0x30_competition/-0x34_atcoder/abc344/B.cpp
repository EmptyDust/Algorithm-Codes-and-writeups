#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::vector<std::string> ss;
    std::string tmp;
    while (std::cin >> tmp) {
        ss.push_back(tmp);
    }
    std::reverse(ss.begin(), ss.end());
    for (auto s : ss)std::cout << s << std::endl;
    return 0;
}