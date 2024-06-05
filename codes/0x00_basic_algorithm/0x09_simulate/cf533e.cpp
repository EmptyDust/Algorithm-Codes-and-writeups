#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    std::string _s, _t;
    std::cin >> _s >> _t;
    std::string s, t;
    int l = 0, r = n - 1;
    while (_s[l] == _t[l])l++;
    while (_s[r] == _t[r])r--;
    s = _s.substr(l, r - l + 1);
    t = _t.substr(l, r - l + 1);
    int len = r - l + 1;
    int ans = 0;
    if (s.substr(0, len - 1) == t.substr(1, len - 1))
        ans++;
    if (s.substr(1, len - 1) == t.substr(0, len - 1))
        ans++;
    std::cout << ans;
    return 0;
}