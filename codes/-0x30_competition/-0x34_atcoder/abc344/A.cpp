#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    bool f = 1;
    std::string s, t;
    std::cin >> s;
    for (int i = 0;i < s.length();++i) {
        if (s[i] == '|') {
            f = !f;
            continue;
        }
        if (f)t += s[i];
    }
    std::cout << t;
    return 0;
}