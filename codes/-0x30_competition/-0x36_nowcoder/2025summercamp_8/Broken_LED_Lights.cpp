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

std::vector<int> g(1024, inf);

std::string L[10] = {
    "1110111",
    "0010010",
    "1011101",
    "1011011",
    "0111010",
    "1101011",
    "1101111",
    "1010010",
    "1111111",
    "1111011"
};

int vaild[6] = { 0,1,2,3,4,6 };

void solve() {
    int n, m;std::cin >> n >> m;
    std::vector<int> a(n);
    for (int i = 0;i < n;++i) {
        std::string s;std::cin >> s;
        std::string t;
        for (auto x : s) {
            t += L[x - '0'];
        }
        // std::cout << t << '\n';
        a[i] = std::stoi(t, 0, 2);
        // std::cout << a[i] << '\n';
    }
    std::vector<int> vis(1 << 21);
    int ans = inf;
    for (int i = 0;i < (1 << 21);++i) {
        int pop = std::__popcount(i);
        // if (pop > 15) continue;
        bool f = 1;
        for (auto x : a) {
            if (vis[x & i]) f = 0;
            vis[x & i] = 1;
            // if (i == ((1 << 18) - 1)) std::cout << x << " " << (x & i) << ' ' << f << '\n';
        }
        if (f) ans = std::min(ans, pop);
        for (auto x : a) {
            vis[x & i] = 0;
        }
        // assert(std::accumulate(vis.begin(), vis.end(), 0ll) == 0);
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