#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;
#define lowbit(x) x&-x

void solve() {
    std::cin >> n;
    for (int i = 1;i <= n;++i)std::cin >> nums[i];
    std::map<int, int> mp;
    for (int i = 1;i <= n;++i) {
        mp[nums[i] + i]++;
    }
    std::vector<pt> tmp;
    for (auto a : mp)
        tmp.push_back(a);
    std::reverse(tmp.begin(), tmp.end());
    int t = 0, pre = -1;
    for (int i = 0;i < tmp.size();++i) {
        if (t) {
            for (int j = pre - 1;t && j > tmp[i].first;--j) {
                t--;
                std::cout << j << ' ';
            }
        }
        t += tmp[i].second - 1;
        std::cout << tmp[i].first << ' ';
        pre = tmp[i].first;
    }
    if (t) {
        for (int j = pre - 1;t;--j) {
            t--;
            std::cout << j << ' ';
        }
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