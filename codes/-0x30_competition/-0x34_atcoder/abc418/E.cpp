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
    std::vector<a2> points(n);
    std::vector<a4> info;
    for (auto& [x, y] : points) std::cin >> x >> y;
    for (int i = 0;i < n;++i) {
        for (int j = i + 1;j < n;++j) {
            int x = points[i][0] - points[j][0];
            int y = points[i][1] - points[j][1];
            if (x < 0) x = -x, y = -y;
            else if (x == 0 && y < 0) y = -y;
            int gcd = std::gcd(x, y);
            info.push_back({ x / gcd, y / gcd, x, y });
        }
    }
    ranges::sort(info);
    std::vector<a4> cur;
    i64 ans = 0, pallsz = 0, eq = 0;
    for (auto it : info) {
        if (cur.size() && it != cur.back()) {
            auto pe = cur.back();
            i64 sz = cur.size();
            cur.clear();
            eq += sz * (sz - 1) / 2;
            pallsz += sz;
            if (it[0] != pe[0] || it[1] != pe[1]) {
                ans += pallsz * (pallsz - 1) / 2;
                pallsz = 0;
            }
        }
        cur.push_back(it);
    }
    i64 sz = cur.size();
    cur.clear();
    eq += sz * (sz - 1) / 2;
    pallsz += sz;
    ans += sz * (sz - 1) / 2;
    pallsz = 0;
    // std::cout << eq << ' ';
    std::cout << ans - eq / 2;
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