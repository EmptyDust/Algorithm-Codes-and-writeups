#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    std::string s;
    std::cin >> s;
    int cnt = 0, res = 0;
    bool g, z, h, u;
    g = z = h = u = false;
    for (int i = 0;i < n;++i) {
        res++;
        if (s[i] == 'g')g = true, cnt++;
        if (s[i] == 'z')z = true, cnt++;
        if (s[i] == 'h')h = true, cnt++;
        if (s[i] == 'u')u = true, cnt++;
        if (g && z && h && u) {
            i += cnt;
            cnt = 0;
            g = z = h = u = false;
        }
    }
    std::cout << res;
    return 0;
}