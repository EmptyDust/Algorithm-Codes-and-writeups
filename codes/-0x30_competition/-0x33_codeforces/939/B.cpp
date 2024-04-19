#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    std::cin >> n;
    std::map<int, int> mp;
    for (int i = 0;i < n;++i)std::cin >> nums[i], mp[nums[i]]++;
    int m = 0, h = 0, z = 0;
    for (int i = 1;i <= n;++i) {
        if (mp.count(i)) {
            if (mp[i] == 2) {
                m++;
            }
            else {
                z++;
            }
        }
        else {
            h++;
        }
    }
    if (m > h) {
        std::cout << m + z;
    }
    else std::cout << m;
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