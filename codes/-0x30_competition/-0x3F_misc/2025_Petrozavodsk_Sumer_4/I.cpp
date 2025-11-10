// 4 1 2 3 5
// 5 4 3 2 1

#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<int, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n;std::cin >> n;
    std::vector<int> p(n), q(n), f(n);
    for (auto& x : p)std::cin >> x;
    for (auto& x : q)std::cin >> x;
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < n;++j) {
            if (p[i] == q[j]) {
                f[i] = j;
                break;
            }
        }
    }
    std::vector<a2> ans;
    auto swap = [&](int x, int y) {
        assert(p[x] < p[y]);
        std::swap(p[x], p[y]);
        std::swap(f[x], f[y]);
        ans.push_back({ x + 1, y + 1 });
        };
    std::vector<a2> tmp;
    for (int i = 0;i < n;++i) while (p[i] != q[i]) {//if (i == 0) { //
        // assert(tmp.empty());
        int x = i;
        do {
            tmp.push_back({ p[x], x });
            x = f[x];
        } while (x != i);
        int m = tmp.size();
        ranges::sort(tmp, std::greater<a2>());
        auto [value, u] = tmp[0];
        // std::cout << f[u] << ' ' << u << '\n';
        if (f[u] > u) {
            std::cout << "NO\n";
            return;
        }
        std::vector<int> r(1, f[u]);
        for (int j = 1;j < m;++j) {
            auto [_, v] = tmp[j];
            if (f[u] < v && v <= u && f[v] > v) {
                r.push_back(v);
            }
        }
        // for (auto x : r)std::cout << x << ' ';
        ranges::sort(r, std::greater<int>());
        for (auto x : r) {
            swap(x, u);
            u = x;
        }
        tmp.clear();
        // for (auto x : p)std::cout << x << ' ';
        // if (i == 1)break;
    }
    std::cout << "YES\n";
    std::cout << ans.size() << '\n';
    for (auto [x, y] : ans)std::cout << x << ' ' << y << '\n';
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