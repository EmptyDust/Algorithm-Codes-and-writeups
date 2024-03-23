#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    std::cin >> n;
    for (int i = 0;i < n;++i)std::cin >> nums[i];
    std::map<int, int> mp;
    for (int i = 0;i < n;++i)mp[nums[i]]++;
    bool f = true;
    for (int i = 0;i < n;++i) {
        if (mp[i] < 2) {
            if (!f || !mp[i]) {
                std::cout << i << ' ';
                return;
            }
            else f = false;
        }
    }
    std::cout << n;
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