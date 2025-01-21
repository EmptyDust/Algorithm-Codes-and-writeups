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
    int n, k;std::cin >> n >> k;
    std::vector<int> a(n);
    std::map<int, int> cnt;
    for (int& x : a)std::cin >> x;
    for (int& x : a)cnt[x]++;
    std::vector<int> c;
    for (auto [_, ct] : cnt)c.push_back(ct);
    ranges::sort(c);
    int ans = c.size();
    for (int i = 0;i < (int)c.size() - 1;++i) {
        if (c[i] <= k) {
            k -= c[i];
            ans--;
        }
    }
    std::cout << ans;
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