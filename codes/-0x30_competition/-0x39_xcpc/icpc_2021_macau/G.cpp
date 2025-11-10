#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<i64, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const i64 inf = 1e18;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n, k;std::cin >> n >> k;
    std::vector<int> a(n), idx(n);
    for (auto& x : a)std::cin >> x;
    std::iota(idx.begin(), idx.end(), 0);
    ranges::sort(idx, [&](int x, int y) {return a[x] < a[y];});
    if (k == 1) {
        i64 ans = std::min(idx[0], n - idx[0]);
        for (int i = 1;i < n;++i) {
            ans += std::min(std::abs(idx[i] - idx[i - 1]), n - std::abs(idx[i] - idx[i - 1]));
        }
        std::cout << ans;
        return;
    }
    std::set<a2> stp; stp.insert({ 0, 0 });
    for (auto x : idx) {
        int L = ((x - k + 1) % n + n) % n, R = x;
        std::vector<a2> tmp;
        i64 minl = inf, minr = inf;
        auto it = stp.begin();
        if (L < R) {
            while (stp.size() && (*(it = stp.begin()))[0] <= L) {
                minl = std::min(minl, std::min(std::abs((*it)[0] - L), n - std::abs((*it)[0] - L)) + (*it)[1]);
                minr = std::min(minr, std::min(std::abs((*it)[0] - R), n - std::abs((*it)[0] - R)) + (*it)[1]);
                stp.erase(it);
            }
            while ((it = stp.lower_bound({ R, 0 })) != stp.end()) {
                minl = std::min(minl, std::min(std::abs((*it)[0] - L), n - std::abs((*it)[0] - L)) + (*it)[1]);
                minr = std::min(minr, std::min(std::abs((*it)[0] - R), n - std::abs((*it)[0] - R)) + (*it)[1]);
                stp.erase(it);
            }
        }
        else {
            while ((it = stp.lower_bound({ R, 0 })) != stp.end() && (*it)[0] <= L) {
                minl = std::min(minl, std::min(std::abs((*it)[0] - L), n - std::abs((*it)[0] - L)) + (*it)[1]);
                minr = std::min(minr, std::min(std::abs((*it)[0] - R), n - std::abs((*it)[0] - R)) + (*it)[1]);
                stp.erase(it);
            }
        }
        if (minl != inf) stp.insert({ L, minl });
        if (minr != inf) stp.insert({ R, minr });
    }
    i64 ans = inf;
    for (auto& [_, x] : stp) ans = std::min(ans, x);
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