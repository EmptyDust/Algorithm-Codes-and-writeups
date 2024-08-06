#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int n, l, d;std::cin >> n >> l >> d;
    int a;std::cin >> a;
    std::vector<int> nums(n - 1);
    for (int& x : nums)std::cin >> x;
    if (a >= l) {
        std::vector<int> nn;
        for (int& x : nums)if (x < l)nn.push_back(x);
        if (nn.size() < 3) {
            std::cout << "No";
            return;
        }
        std::sort(nn.begin(), nn.end());
        if (a - nn[0] > d) {
            std::cout << "Yes";
            return;
        }
    }
    else {
        std::vector<int> s{ a };
        std::sort(nums.begin(), nums.end());
        s.push_back(nums[0]);
        s.push_back(nums[1]);
        s.push_back(nums.back());
        std::sort(s.begin(), s.end());
        if (!(s.back() - s.front() <= d || s[3] >= l && s[2] >= l)) {
            std::cout << "Yes";
            return;
        }
    }
    std::cout << "No";
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