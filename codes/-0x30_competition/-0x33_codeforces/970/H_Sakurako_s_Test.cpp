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
    int n, q;std::cin >> n >> q;
    std::vector<int> c(n + 2), ans(q);
    for (int i = 0;i < n;++i) {
        int x;std::cin >> x;
        c[x + 1]++;
    }
    for (int i = 1;i <= n + 1;++i)c[i] += c[i - 1];
    std::vector<pii> qy(q);
    for (int i = 0;i < q;++i) {
        auto& [x, p] = qy[i];
        std::cin >> x;p = i;
    }
    ranges::sort(qy);
    std::vector<pii> cur;
    cur.push_back(qy[0]);
    auto work = [&]() {
        int d = cur.back().first;
        auto l = 1, r = d + 1;
        auto check = [&](auto x)->bool {
            int sum = 0;
            for (int i = 0;i <= n + 1;i += d) {
                sum += c[std::min(n + 1, i + x)] - c[i];
            }
            // std::cout << sum << ' ';
            return sum > n / 2;
            };
        while (l < r) {
            auto mid = l + r >> 1;
            if (check(mid))r = mid;
            else l = mid + 1;
        }
        // std::cout << check(3);
        for (auto x : cur)ans[x.second] = l - 1;
        };
    for (int i = 1;i < q;++i) {
        if (cur.back().first == qy[i].first)cur.push_back(qy[i]);
        else {
            work();
            cur.clear();
            cur.push_back(qy[i]);
        }
    }
    work();
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