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
    std::vector<a3> info;
    info.push_back({ 0, 0, n });
    for (int i = 0;i < n;++i) {
        int x;std::cin >> x;
        info.push_back({ x, 0, 0 });
        info.push_back({ x + 1, 1, 0 });
    }
    for (int i = 0;i < n;++i) {
        int x;std::cin >> x;
        info.push_back({ x, 0, 0 });
        info.push_back({ x + 1, -1, -1 });
    }
    ranges::sort(info);
    i64 ans = 0;
    i64 neg_cnt = 0, buy_cnt = 0;
    std::vector<a3> cur;cur.push_back(info[0]);
    auto work = [&](i64 price) {
        for (auto& [price, neg, buy] : cur) {
            // std::cout << price << '\n';
            neg_cnt += neg;
            buy_cnt += buy;
        }
        // std::cout << neg_cnt << ' ' << price << ' ' << buy_cnt << '\n';
        if (neg_cnt <= k) {
            ans = std::max(ans, price * buy_cnt);
        }
        cur.clear();
        };
    for (int i = 1;i < info.size();++i) {
        if (info[i][0] == info[i - 1][0]) {
            cur.push_back(info[i]);
        }
        else {
            work(info[i - 1][0]);
            cur.push_back(info[i]);
        }
    }
    work(info.back()[0]);
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