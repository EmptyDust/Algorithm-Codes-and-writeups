#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using a3 = std::array<int, 3>;

void solve() {
    int a, b, n, m;
    std::cin >> a >> b >> n >> m;
    std::vector<a3> pts1(n);
    std::vector<bool> used(n);
    int _t = 0;
    for (auto& [x, y, id] : pts1)std::cin >> x >> y, id = _t++;
    std::vector<a3> pts2(pts1);
    std::sort(pts1.begin(), pts1.end());
    std::sort(pts2.begin(), pts2.end(), [&](a3 f, a3 g) {
        if (f[1] != g[1])return f[1] < g[1];
        return f < g;
        });
    int l = 0, r = b + 1;
    int u = 0, d = a + 1;
    int curl = 0, curr = n - 1;
    int curu = 0, curd = n - 1;
    int ans1 = 0, ans2 = 0;
    for (int i = 0;i < m;++i) {
        char dir;int cnt;
        std::cin >> dir >> cnt;
        switch (dir)
        {
        case 'L':
            l += cnt;
            break;
        case 'R':
            r -= cnt;
            break;
        case 'U':
            u += cnt;
            break;
        case 'D':
            d -= cnt;
        }
        while (curl <= curr && pts2[curl][1] <= l) {
            int id = pts2[curl][2];
            if (!used[id])
                if (i % 2)ans2++;
                else ans1++;
            used[id] = 1;
            curl++;
        }
        while (curl <= curr && pts2[curr][1] >= r) {
            int id = pts2[curr][2];
            if (!used[id])
                if (i % 2)ans2++;
                else ans1++;
            used[id] = 1;
            curr--;
        }
        while (curu <= curd && pts1[curu][0] <= u) {
            int id = pts1[curu][2];
            if (!used[id])
                if (i % 2)ans2++;
                else ans1++;
            used[id] = 1;
            curu++;
        }
        while (curu <= curd && pts1[curd][0] >= d) {
            int id = pts1[curd][2];
            if (!used[id])
                if (i % 2)ans2++;
                else ans1++;
            used[id] = 1;
            curd--;
        }
    }
    std::cout << ans1 << ' ' << ans2 << '\n';
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