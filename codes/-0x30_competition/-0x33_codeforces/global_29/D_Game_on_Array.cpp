#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using a2 = std::array<i64, 2>;
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
    std::map<int, int> next, cnt;
    for (auto& x : a)std::cin >> x, cnt[x]++;
    i64 sum = std::accumulate(a.begin(), a.end(), 0ll);
    ranges::sort(a);
    a.erase(std::unique(a.begin(), a.end()), a.end());
    ranges::sort(a, [&](int x, int y) {
        // return x < y;
        // if (cnt[x] == cnt[y]) {
        //     return x < y;
        // }
        return cnt[x] > cnt[y];
        });
    bool f = 0;
    a2 ans = { 0,0 };
    for (auto x : a) if (x % 2) {
        ans[f] += cnt[x];
        sum -= cnt[x];
        f ^= 1;
    }
    ans[0] += sum / 2, ans[1] += sum / 2;
    std::cout << ans[0] << ' ' << ans[1] << '\n';
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