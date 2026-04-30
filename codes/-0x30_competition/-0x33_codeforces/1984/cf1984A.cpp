#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    std::cin >> n;
    for (int i = 0;i < n;++i)std::cin >> nums[i];
    if (nums[0] == nums[n - 1]) {
        std::cout << "NO";
        return;
    }
    std::cout << "YES\n";
    std::cout << "R";
    if (nums[0] == nums[1]) {
        int i = 1;
        for (;i < n - 1 && nums[i] != nums[n - 1];++i)std::cout << "B";
        for (;i < n - 1;++i)std::cout << "R";
    }
    else {
        for (int i = 1;i < n - 1;++i)std::cout << "B";
    }
    std::cout << "R";
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