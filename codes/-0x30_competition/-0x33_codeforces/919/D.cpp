#include <bits/stdc++.h>
using i64 = long long;
constexpr i64 inf = 1e18;
int n, q;
using pt = std::pair<int, int>;

void solve() {
    std::cin >> n >> q;
    std::vector<int> mul{ 1 };
    std::vector<i64> len{ 0 };
    std::vector<std::vector<int>> nums(1);
    for (int i = 0;i < n;++i) {
        int b, x;std::cin >> b >> x;
        if (b == 1) {
            nums.back().push_back(x);
        }
        else {
            if (len.back() < inf) {
                len.push_back(len.back() <= inf / mul.back() ? len.back() * mul.back() + nums.back().size() : inf);
                mul.push_back(x + 1);
                nums.push_back({});
            }
        }
    }

    while (q--) {
        i64 k;
        std::cin >> k;
        k--;

        for (int i = nums.size() - 1;~i;--i) {
            if (k / mul[i] >= len[i]) {
                std::cout << nums[i][k - mul[i] * len[i]] << " \n"[q == 0];
                break;
            }
            else
                k %= len[i];
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}