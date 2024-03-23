#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::string s;std::cin >> s;
    int n = s.length();
    if (s[0] == '<' && s[n - 1] == '>') {
        bool f = true;
        for (int i = 1;i <= n - 2;++i) {
            if (s[i] != '=')f = false;
        }
        if (f) {
            std::cout << "Yes";
            return 0;
        }
    }
    std::cout << "No";
    return 0;
}