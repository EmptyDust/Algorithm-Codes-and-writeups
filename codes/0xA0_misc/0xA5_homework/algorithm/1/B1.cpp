#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;
using d64 = long double;

using a2 = std::array<int, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

d64 ans = 0;
int n, m, d;

std::map<a2, d64> memory;

std::array<int, 5> cal(int sta) {
    std::array<int, 5> res;
    for (int i = 0;i < 5;++i) {
        res[i] = sta % 6;
        sta /= 6;
    }
    return res;
}

d64 dfs(d64 p, int cnt, int sta_x, int sta_y) {
    if (memory.count({ sta_x, sta_y })) {
        ans += memory[a2{ sta_x, sta_y }];
        return memory[a2{ sta_x, sta_y }];
    }
    if (sta_y == 0) {
        ans += p;
        return memory[a2{ sta_x, sta_y }] = p;
    }
    if (cnt >= d) return memory[a2{ sta_x, sta_y }] = 0;
    std::array<int, 5> x = cal(sta_x), y = cal(sta_y);
    int all = n + m - std::count(x.begin(), x.end(), 0) - std::count(y.begin(), y.end(), 0);
    d64 res = 0;
    int add = 1;
    for (int i = 0;i < 5;++i) {
        add *= 6;
        if (x[i]) {
            sta_x -= add;
            res += dfs(p / all, cnt + 1, sta_x, sta_y);
            sta_x += add;
        }
    }
    add = 1;
    for (int i = 0;i < 5;++i) {
        add *= 6;
        if (y[i]) {
            sta_y -= add;
            res += dfs(p / all, cnt + 1, sta_x, sta_y);
            sta_y += add;
        }
    }
    return memory[a2{ sta_x, sta_y }] = res;
}

void solve() {
    std::cin >> n >> m >> d;
    std::vector<int> x(n), y(m);
    for (auto& a : x)std::cin >> a;
    for (auto& a : y)std::cin >> a;
    int sta_x = 0, sta_y = 0;
    for (int i = 0;i < n;++i) sta_x = sta_x * 6 + x[i];
    for (int i = 0;i < m;++i) sta_y = sta_y * 6 + y[i];
    dfs(1, 0, sta_x, sta_y);
    std::cout << ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cout << std::fixed << std::setprecision(4);
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}