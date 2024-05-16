#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    std::string s;
    int ans = 0;
    for (int i = 0;i < n;++i) {
        std::cin >> s;
        if (s.length() == 5 && s[2] == s[4]) {
            std::map<char, int> mp;
            for (int j = 0;j < 4;++j)mp[s[j]]++;
            bool f = true;
            for (auto [c, cnt] : mp)if (cnt != 1) {
                f = false;
                break;
            }
            if (f)ans++;
        }
    }
    std::cout << ans;
    return 0;
}