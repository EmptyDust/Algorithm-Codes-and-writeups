#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int n;
using pii = std::pair<int, int>;

void solve() {
    i64 n, c;std::cin >> n >> c;
    std::vector<int> nums(n), zbs(n), ans(n);
    for (int i = 0;i < n;++i)std::cin >> nums[i];
    std::iota(zbs.begin(), zbs.end(), 0);
    std::sort(zbs.begin(), zbs.end(), [&](int a, int b) {
        if (nums[a] == nums[b])return a < b;
        return nums[a] > nums[b];
        });

    std::set<pii> st;
    i64 sum = 0;
    for (int i = 0;i < n;++i) {
        st.insert({ nums[i],i });
        sum += nums[i];
    }

    {
        int cur = zbs[0];
        if (cur == 0 || nums[cur] > c + nums[0]) {
            ans[cur] = 0;
        }
        else ans[cur] = cur;
    }

    for (int i = 0;i < n;++i) {
        if (st.count({ nums[i],i }))
            st.erase({ nums[i],i }), sum -= nums[i];
        while (st.size() && c + nums[i] + sum - (*st.begin()).first >= nums[zbs[0]]) {
            sum -= (*st.begin()).first;
            st.erase(st.begin());
        }
        if (i != zbs[0])ans[i] = i + st.size();
        else st.clear(), sum = 0;
        c += nums[i];
    }
    for (int x : ans)std::cout << x << ' ';
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