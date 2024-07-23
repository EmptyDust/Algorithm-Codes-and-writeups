#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9 + 10, mod = 1e9 + 7;
using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;

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
        int ret = 0;
        for (int i = 0;i < d.size();++i) {
            if (get_root(i) == i)ret++;
        }
        return ret;
    }
};

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    //ai - i <= aj - j
    //bj - j <= bi - i
    int n;std::cin >> n;
    std::vector<pii> ps(n);
    for (auto& [a, b] : ps)std::cin >> a >> b;
    for (int i = 0;i < n;++i)ps[i].first -= i, ps[i].second -= i;
    std::sort(ps.begin(), ps.end(), [&](auto a, auto b) {
        if (a.first != b.first)return a.first < b.first;
        return a.second > b.second;
        });
    int curl = -inf, curr = -inf;
    std::deque<a3> q;
    dsu d(n);
    for (int i = 0;i < n;++i) {
        auto [l, r] = ps[i];
        if (r > curr && l > curl) {
            q.push_back({ l,r,i });
        }
        else {
            auto tmp = q.back();
            // std::cout << r << ' ' << q.back()[1] << '\n';
            while (q.size() && r <= q.back()[1]) {
                d.merge(i, q.back()[2]);
                q.pop_back();
            }
            q.push_back(tmp);
        }
        curl = l;
        curr = std::max(curr, r);
        // std::cout << l << ' ' << r << '\n';
    }
    std::cout << d.cal();
    return 0;
}