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
    std::string s;std::cin >> s;s = '*' + s;
    std::vector<pii> pre(n + 1);
    std::vector<int> p;
    for (int i = 1;i <= n;++i) {
        if (s[i] == '/') {
            p.push_back(i);
        }
        else if (s[i] == '1')pre[i].second++;
        else pre[i].first++;
        pre[i].first += pre[i - 1].first;
        pre[i].second += pre[i - 1].second;
    }
    auto cal = [&](int l, int x, int r) {
        if (x < 0 || x >= p.size())return 0;
        x = p[x];
        return std::min(pre[x].second - pre[l - 1].second, pre[r].first - pre[x].first);
        };
    for (int i = 0;i < q;++i) {
        int l, r;std::cin >> l >> r;
        int cnt0 = pre[r].first - pre[l - 1].first;
        int cnt1 = pre[r].second - pre[l - 1].second;
        auto itl = std::lower_bound(p.begin(), p.end(), l);
        auto itr = std::upper_bound(p.begin(), p.end(), r);
        if (itl == itr) {
            std::cout << 0 << '\n';
            continue;
        }
        int p1 = ranges::partition_point(itl, itr, [&](int x) {
            int c1 = pre[x].second - pre[l - 1].second;
            int c0 = pre[r].first - pre[x].first;
            return c1 < c0;
            }) - p.begin();
        int res = std::max(cal(l, p1, r), cal(l, p1 - 1, r));
        std::cout << res * 2 + 1 << '\n';
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}