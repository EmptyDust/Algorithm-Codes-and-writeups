#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

#define int long long

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

struct dsu {
    std::vector<int> d;
    int cnt;
    dsu(int n) { d.resize(n); iota(d.begin(), d.end(), 0);cnt = n; }
    int get_root(int x) { return d[x] = (x == d[x] ? x : get_root(d[x])); };
    bool merge(int u, int v) {
        if (get_root(u) != get_root(v)) {
            d[get_root(u)] = get_root(v);
            cnt--;
            return true;
        }
        else return false;
    }
    bool ok() {
        return cnt == 1;
    }
};

void solve() {
    int w, h, n;std::cin >> w >> h >> n;
    std::vector<pii> ps(n);
    for (auto& [x, y] : ps)std::cin >> x >> y;
    std::vector<a3> a3s;a3s.reserve(n * n);
    for (int i = 0;i < n;++i)for (int j = 0;j < n;++j)if (i != j) {
        int len = std::abs(ps[i].first - ps[j].first) + std::abs(ps[i].second - ps[j].second);
        a3s.push_back({ len / 2,i,j });
    }
    ranges::sort(a3s);
    dsu d(n);
    for (auto [len, u, v] : a3s) {
        d.merge(u, v);
        // std::cout << u << ' ' << v << ' ' << len << '\n';
        if (d.ok()) {
            std::cout << len;
            return;
        }
    }
    std::cout << 0;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}