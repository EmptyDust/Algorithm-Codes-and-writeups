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
    int n, z;std::cin >> n >> z;
    std::vector<int> a(n), suf(n, n);
    std::vector next1(32, std::vector<int>(n + 2, n)), value1(32, std::vector<int>(n + 2));
    std::vector next2(32, std::vector<int>(n + 2, n)), value2(32, std::vector<int>(n + 2));
    next1[0][n] = next2[0][n] = next1[0][n + 1] = next2[0][n + 1] = n + 1;
    for (auto& x : a)std::cin >> x;
    for (int i = n - 2, j = n - 1;i >= 0;--i) {
        while (a[j - 1] - a[i] > z) j--;
        if (a[j] - a[i] > z) next1[0][i] = j;
        else next1[0][i] = n;
        value1[0][i] = 1;
    }
    for (int t = 1;t < 32;++t) {
        for (int i = 0;i <= n + 1;++i) {
            // std::cout << next[t][i - 1] << ' ';
            next1[t][i] = next1[t - 1][next1[t - 1][i]];
            value1[t][i] = value1[t - 1][i] + value1[t - 1][next1[t - 1][i]];
        }
    }
    for (int i = n - 2, s = n;i >= 0;--i) {
        int x = i, y = i + 1;
        if (next1[0][i] == y) s = y;
        suf[i] = s;
        int cnt = 0;
        for (int t = 31;t >= 0;--t) {
            if (next1[t][x] == next1[t][y]) continue;
            x = next1[t][x], y = next1[t][y];
            cnt += 1 << t;
        }
        if (x != y) x = next1[0][x], y = next1[0][y], cnt++;
        // std::cout << s << " " << x << ' ' << y << ' ' << cnt << ' ' << next2[0][i] << ' ' << value2[0][i] << '\n';
        if (x == n + 1) {
            x = next1[0][i], y = i + 1;
            cnt = 0;
            for (int t = 31;t >= 0;--t) {
                if (next1[t][x] == next1[t][y]) continue;
                x = next1[t][x], y = next1[t][y];
                cnt += 1 << t;
            }
            if (x != y) x = next1[0][x], y = next1[0][y], cnt++;
        }
        next2[0][i] = std::min(s, x);
        value2[0][i] = cnt;
        assert(x == y);
        // std::cout << s << " " << x << ' ' << y << ' ' << cnt << ' ' << next2[0][i] << ' ' << value2[0][i] << '\n';
    }
    for (int t = 1;t < 32;++t) {
        for (int i = 0;i <= n + 1;++i) {
            // std::cout << next[t][i - 1] << ' ';
            next2[t][i] = next2[t - 1][next2[t - 1][i]];
            value2[t][i] = value2[t - 1][i] + value2[t - 1][next2[t - 1][i]];
        }
    }
    int q;std::cin >> q;
    while (q--) {
        int L, R;std::cin >> L >> R;L--, R--;
        int ans = 0;
        int l = L, r = R;
        for (int t = 31;t >= 0;--t) {
            if (next1[t][l] > r) continue;
            ans += value1[t][l];
            l = next1[t][l];
        }
        if (l <= r) ans++;
        // std::cout << ans << ' ';
        l = L, r = R;
        for (int t = 31;t >= 0;--t) {
            if (next2[t][l] > r) continue;
            // std::cout << t << ' ' << l << ' ' << value2[t][l] << ' ' << next2[t][l] << '\n';
            ans += value2[t][l];
            l = next2[t][l];
        }
        // std::cout << ans << ' ';
        l++;
        for (int t = 31;t >= 0;--t) {
            if (next1[t][l] > r) continue;
            ans += value1[t][l];
            l = next1[t][l];
        }
        if (l <= r) ans++;
        std::cout << ans << '\n';
    }
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