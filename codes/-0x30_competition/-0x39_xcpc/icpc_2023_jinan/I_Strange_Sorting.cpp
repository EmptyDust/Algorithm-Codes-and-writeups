#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n;std::cin >> n;
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    std::map<int, int> mp;
    for (int i = 0;i < n;++i)mp[a[i]] = i + 1;
    std::vector<pii> ans;
    for (int i = 0;i < n;++i)if (a[i] != i + 1){
        int l = i;
        int r = i;
        for (int k = a[i] - 1;k >= i + 1;--k)
            r = std::max(r, mp[k]);
        ans.push_back({ l + 1,r });
        ranges::sort(a.begin() + l, a.begin() + r);
        for (int j = l;j < r;++j)mp[a[j]] = j + 1;
    }
    std::cout << ans.size() << '\n';
    for (auto [l, r] : ans)std::cout << l << ' ' << r << '\n';
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