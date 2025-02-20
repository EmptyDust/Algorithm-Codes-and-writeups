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
    int n;std::cin >> n;
    std::vector<pii> e;
    std::vector<int> cnt(n);
    for (int i = 1;i < n;++i) {
        int u, v;std::cin >> u >> v;v--, u--;
        e.push_back({ u,v });
        cnt[u]++;
        cnt[v]++;
    }
    int max = *std::max_element(cnt.begin(), cnt.end());
    int mc = std::count(cnt.begin(), cnt.end(), max);
    if (mc > 2) {
        std::cout << 1 + (max - 1) * 2;
        return;
    }
    if (mc == 2) {
        int p1 = -1, p2 = -1;
        for (int i = 0;i < n;++i)if (cnt[i] == max) {
            if (~p1)p2 = i;
            else p1 = i;
        }
        for (auto [u, v] : e) {
            if (u == p1 && v == p2 || u == p2 && v == p1) {
                std::cout << (max - 1) * 2;
                return;
            }
        }
        std::cout << 1 + (max - 1) * 2;
        return;
    }
    int p1 = std::max_element(cnt.begin(), cnt.end()) - cnt.begin();
    std::vector<int> tag(n, 0);
    for (auto [u, v] : e) {
        if (u == p1)tag[v] = -1;
        if (v == p1)tag[u] = -1;
    }
    int ans = 0;
    for (int i = 0;i < n;++i)if (i != p1) {
        ans = std::max(ans, 1 + (max - 1) + (cnt[i] + tag[i] - 1));
    }
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