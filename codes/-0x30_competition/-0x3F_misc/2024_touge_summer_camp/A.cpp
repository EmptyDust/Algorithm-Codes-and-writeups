#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int L;std::cin >> L;
    int s, t, m;std::cin >> s >> t >> m;
    std::vector<int> p(m), vis(m);
    std::set<int> st;st.insert(0);
    for (int& x : p) std::cin >> x;
    std::sort(p.begin(), p.end());

    for (int x : p) {
        for (int i = -10;i <= 10;++i)if (x + i >= 0 && x + i <= L)
            st.insert(x + i);
    }

    int n = st.size();
    std::vector<int> nums(n), dp(n, inf), add(n);dp[0] = 0;
    int _i = 0;
    for (int x : st) {
        nums[_i++] = x;
    }
    for (int i = 0, j = 0;i < n;++i) {
        while (j < m && nums[i] == p[j]) {
            add[i] = 1;
            j++;
        }
    }

    auto check = [&](int x, int y) {
        int u = (y - x) / s * t;
        return y <= u;
        };

    for (int i = 0;i < n;++i) {
        for (int j = i + s, cur = nums[i] + s;j <= i + t;++j, cur++) {
            if (cur != nums[j])break;
            dp[j] = std::min(dp[j], dp[i] + add[j]);
        }
        if (!add[i]) {
            for (int j = i + 1;j < n;++j) {
                if (add[j]) {
                    // std::cout << nums[j] << ' ';
                    break;
                }

                if (check(nums[i], nums[j])) {
                    dp[j] = std::min(dp[j], dp[i] + add[j]);
                }
            }
        }
    }
    for (int i = 0;i < n;++i) {
        // std::cout << nums[i] << ' ' << dp[i] << '\n';
    }
    std::cout << dp.back();
    return 0;
}