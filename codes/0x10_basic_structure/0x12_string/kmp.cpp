#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::string s;std::cin >> s;
    std::string t;std::cin >> t;
    int n = s.length(), m = t.length();
    std::vector<int> nxt(n + 1);
    nxt[0] = -1;
    for (int i = 0, j = -1;i < n;) {
        if (j == -1 || t[i] == t[j]) {
            ++i, ++j;
            nxt[i] = j;
        }
        else j = nxt[j];
    }
    int i = 0, j = 0;
    for (;i < n && j < m;) {
        if (j == -1 || s[i] == t[j]) {
            ++i, ++j;
        }
        else j = nxt[j];
    }
    if (j == m) {
        std::cout << i - j;
    }
    else std::cout << -1;
    return 0;
}