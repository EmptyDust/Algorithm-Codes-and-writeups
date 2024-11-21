#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<i64, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

struct dsu {
    std::vector<int> d;
    dsu(int n) { d.resize(n); iota(d.begin(), d.end(), 0); }
    int get_root(int x) { return d[x] = (x == d[x] ? x : get_root(d[x])); };
    bool merge(int u, int v) {
        if (get_root(u) != get_root(v)) {
            d[get_root(u)] = get_root(v);
            return true;
        }
        else return false;
    }
    int cal() {
        int cnt = 0;
        for (int i = 1;i < d.size();++i)
            if (i == get_root(i))
                cnt++;
        return cnt;
    }
};

void solve() {
    int n, m;std::cin >> n >> m;
    dsu dsu(n + 1);
    std::vector<a3> ops(m);
    for (auto& [a, d, k] : ops)std::cin >> a >> d >> k;
    ranges::sort(ops);
    std::vector info(11, std::vector<std::vector<a3>>(11, std::vector<a3>()));
    for (auto op : ops) {
        auto [a, d, k] = op;
        info[d][a % d].push_back(op);
    }
    for (int d = 1;d <= 10;++d) {
        for (int mod = 0;mod < d;++mod) {
            int cur = mod;
            for (auto [a, d, k] : info[d][mod]) {
                if (cur < a)cur = a;
                for (;cur <= a + d * k;cur += d) {
                    dsu.merge(a, cur);
                }
            }
        }
    }
    std::cout << dsu.cal();
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