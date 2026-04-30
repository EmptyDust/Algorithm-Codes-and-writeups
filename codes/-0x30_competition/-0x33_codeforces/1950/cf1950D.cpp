#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e5 + 10;
using pt = std::pair<int, int>;
std::vector<int> nums;

bool solve() {
    int n;
    std::cin >> n;
    std::vector<int> f;
    f.push_back(n);
    if (f.back() == 1)return true;
    for (int num : nums) {
        for (int i = 0;i < f.size();++i) {
            if (f[i] % num == 0) {
                f.push_back(f[i] / num);
                if (f.back() == 1)return true;
            }
        }
    }
    return false;
}

bool check(int x) {
    while (x) {
        int p = x % 10;
        x /= 10;
        if (p > 1)return false;
    }
    return true;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    for (int i = 2;i < MAXN;++i)if (check(i)) {
        nums.push_back(i);
    }
    while (t--) {
        std::cout << (solve() ? "Yes" : "No");
        std::cout << '\n';
    }
    return 0;
}