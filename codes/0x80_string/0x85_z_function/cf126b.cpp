#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;

std::vector<int> z_function(std::string s) {
    int n = (int)s.length();
    std::vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r && z[i - l] < r - i + 1) {
            z[i] = z[i - l];
        }
        else {
            z[i] = std::max(0, r - i + 1);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        }
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::string s;std::cin >> s;
    auto zf = z_function(s);
    int n = zf.size(), len = -1, pos = -1;
    auto f = zf;
    for (int i = 2;i < n;++i)f[i] = std::max(f[i], f[i - 1]);
    for (int i = n - 1;i >= 2;--i)if (i + zf[i] == n && zf[i] <= f[i - 1]) {
        len = zf[i];
        pos = i;
    }
    if (pos == -1) {
        std::cout << "Just a legend";
        return 0;
    }
    std::cout << s.substr(pos, len);
    return 0;
}