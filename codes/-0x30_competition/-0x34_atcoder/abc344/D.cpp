#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9;
int nums[MAXN], n;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::string t;std::cin >> t;
    int len = t.length();
    std::vector<i64> f(len + 1, inf);
    f[0] = 0;
    int n;std::cin >> n;
    while (n--) {
        int k;std::cin >> k;
        std::vector<i64> tmp(f);
        while (k--) {
            std::string s;std::cin >> s;
            int lim = len - (int)s.length() + 1;
            for (int i = 0;i < lim;++i) {
                bool ff = true;
                for (int j = 0;j < s.length();++j) {
                    if (t[i + j] != s[j]) {
                        ff = false;
                        break;
                    }
                }
                if (ff) {
                    int x = i + (int)s.length();
                    tmp[x] = std::min(tmp[x], std::min(f[x], f[i] + 1));
                    //std::cout << i << ' ' << x << ' ' << s << std::endl;
                }
            }
        }
        f = tmp;
    }
    std::cout << (f[len] == inf ? -1 : f[len]);
    return 0;
}