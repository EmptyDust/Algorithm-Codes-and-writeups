#include <bits/stdc++.h>
using i64 = unsigned long long;
constexpr int MAXN = 64 + 10;
i64 n, m;
using pt = std::pair<int, int>;
std::vector<i64> ans;

int lg(i64 x) {
    return x ? std::__lg(x) : -1;
}

void solve() {
    std::cin >> n >> m;
    if (m >= n) {
        std::cout << -1;
        return;
    }
    ans.clear();
    ans.push_back(n);
    if ((m ^ n) <= n) {
        ans.push_back(m);
        std::cout << ans.size() - 1 << '\n';
        for (auto num : ans)std::cout << num << ' ';
        return;
    }
    i64 x = n;
    x ^= (i64)1 << lg(x);
    int lgx = lg(x), lgm = lg(m);
    if (lgx >= lgm && x ^ m) {
        n ^= x ^ m;
        ans.push_back(n);
    }
    else if (lgx < lgm) {
        std::cout << -1;
        return;
    }
    x = n ^ m;
    ans.push_back(m);
    std::cout << ans.size() - 1 << '\n';
    for (auto num : ans)std::cout << num << ' ';
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