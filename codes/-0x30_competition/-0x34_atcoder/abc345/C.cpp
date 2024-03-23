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
    std::map<char, i64> mp;
    for (int i = 0;i < n;++i)mp[s[i]]++;
    i64 ans = 0;
    bool f = false;
    for (auto [c, cnt] : mp) {
        ans += cnt * (n - cnt);
        if (cnt >= 2)f = true;
    }
    std::cout << ans / 2 + f;
    return 0;
}