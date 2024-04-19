#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::string s[6];
    for (int i = 0;i < 6;++i)std::cin >> s[i];
    if (s[0][3] != '|')std::cout << 'o';
    else if (s[5][3] != '|')std::cout << 'm';
    else std::cout << 'p';
    return 0;
}