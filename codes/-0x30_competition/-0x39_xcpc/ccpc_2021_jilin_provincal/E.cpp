#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    std::cin >> n;
    for (int i = 0;i < n;++i)std::cin >> nums[i];
    std::set<int> st;
    for (int i = 0;i < n;++i) {
        int x;
        if (nums[i] & 1)x = nums[i] - 1;
        else x = nums[i] + 1;
        if (st.count(x)) {
            std::cout << "Yes";
            return;
        }
        st.insert(nums[i]);
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