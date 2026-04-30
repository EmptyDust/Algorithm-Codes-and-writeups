#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], ps[MAXN], n;
using pt = std::pair<i64, i64>;

void solve() {
    std::cin >> n;
    for (int i = 0;i < n;++i)std::cin >> nums[i];
    for (int i = 0;i < n;++i)std::cin >> ps[i], ps[i]--;
    std::set<pt> st, bag;
    for (int i = 0;i < n;++i)st.insert({ nums[i],i });
    i64 ans = 0, len = 0;
    for (int i = 0;i < n;++i) {
        if (i) {
            if (st.count({ nums[ps[i - 1]],ps[i - 1] }))
                st.erase({ nums[ps[i - 1]],ps[i - 1] });
            else if (bag.count({ nums[ps[i - 1]],ps[i - 1] }))
                bag.erase({ nums[ps[i - 1]],ps[i - 1] });
        }
        while (bag.size() <= i && !st.empty()) {
            bag.insert(*--st.end());
            st.erase(--st.end());
        }
        if (bag.size() < i)break;
        if (ans < bag.size() * bag.begin()->first) {
            len = bag.size();
            ans = len * bag.begin()->first;
        }
    }
    std::cout << ans << ' ' << len;
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