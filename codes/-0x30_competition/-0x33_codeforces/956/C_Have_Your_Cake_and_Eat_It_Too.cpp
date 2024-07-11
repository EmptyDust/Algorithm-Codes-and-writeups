#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int n;std::cin >> n;
    std::vector<int> a(n), b(n), c(n);
    for (int& x : a)std::cin >> x;
    for (int& x : b)std::cin >> x;
    for (int& x : c)std::cin >> x;
    i64 sum = std::accumulate(a.begin(), a.end(), 0ll);
    i64 lim = sum / 3 + (sum % 3 != 0);
    std::vector<pii> ans(3);
    auto work = [&](std::vector<int>& a, std::vector<int>& b, std::vector<int>& c) {
        int i = 0;
        auto& [la, ra] = ans[0];
        auto& [lb, rb] = ans[1];
        auto& [lc, rc] = ans[2];
        i64 cur = 0;la = 0;
        for (;i < n;++i) {
            cur += a[i];
            if (cur >= lim)break;
        }
        // std::cout << cur << ' ';
        cur = 0;ra = i;lb = ++i;
        for (;i < n;++i) {
            cur += b[i];
            if (cur >= lim)break;
        }
        cur = 0;rb = i;lc = ++i;
        for (;i < n;++i) {
            cur += c[i];
            if (cur >= lim)break;
        }
        rc = n - 1;
        // std::cout << la + 1 << ' ' << ra + 1 << ' ' << lb + 1 << ' ' << rb + 1
        //     << ' ' << lc + 1 << ' ' << rc + 1 << '\n';
        if (cur >= lim) {
            return true;
        }
        return false;
        };
    std::vector<std::pair<int, std::vector<int>>> vt{ {0,a},{1,b},{2,c} };
    do {
        if (work(vt[0].second, vt[1].second, vt[2].second)) {
            for (int i = 0;i < 3;++i)if (vt[i].first == 0) {
                std::cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << ' ';
            }
            for (int i = 0;i < 3;++i)if (vt[i].first == 1) {
                std::cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << ' ';
            }
            for (int i = 0;i < 3;++i)if (vt[i].first == 2) {
                std::cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << ' ';
            }
            return;
        }
    } while (std::next_permutation(vt.begin(), vt.end()));
    std::cout << -1;
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