#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], pre[MAXN], n, q;
using pt = std::pair<int, int>;

void solve() {
    std::cin >> n >> q;
    for (int i = 1;i <= n;++i)std::cin >> nums[i];
    for (int i = 1;i <= n;++i)pre[i] = pre[i - 1] ^ nums[i];
    std::map<int, std::vector<int>> mp;
    for (int i = 0;i <= n;++i)
        mp[pre[i]].push_back(i);
    int l, r;
    while (q--) {
        std::cin >> l >> r;
        auto _l_r = std::upper_bound(mp[pre[r]].begin(), mp[pre[r]].end(), l - 1);//找第一个大于l-1
        auto _r_l = std::upper_bound(mp[pre[l - 1]].rbegin(), mp[pre[l - 1]].rend(), r, std::greater<int>());//找第一个小于r
        int l_r = -1, r_l = -1;
        if (_l_r != mp[pre[r]].end())l_r = *_l_r;
        if (_r_l != mp[pre[l - 1]].rend())r_l = *_r_l;
        if (pre[r] == pre[l - 1]) {
            if (r - l + 1 >= 2)std::cout << "Yes";
            else std::cout << "No";
            std::cout << '\n';
            continue;
        }
        //std::cout << l_r << ' ' << r_l << '\n';
        if (l_r < r_l && l_r >= l && r_l < r)std::cout << "Yes";
        else std::cout << "No";
        std::cout << '\n';
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}