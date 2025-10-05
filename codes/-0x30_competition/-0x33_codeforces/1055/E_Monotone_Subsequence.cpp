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
    std::vector<int> vis(n * n + 2);

    std::vector<std::vector<int>> r(n * n + 2), l(n * n + 2);

    for (int _ = 0;_ < n;++_) {

        std::vector<int> ask;
        for (int i = 1;i <= n * n + 1;++i) {
            if (!vis[i]) {
                ask.push_back(i);
            }
            // std::cout << vis[i] << ' ';
        }
        if (ask.empty()) break;

        std::cout << "? " << ask.size() << ' ';
        for (auto x : ask)std::cout << x << ' ';
        std::cout << std::endl;

        int k;std::cin >> k;
        std::vector<int> res(k);
        for (auto& x : res) {
            std::cin >> x;
            vis[x] = 2;
            // std::cout << x << ' ';
        }
        for (int i = res[0], pre = 0;i <= n * n + 1;++i) {
            if (vis[i] == 2) {
                vis[i] = 1;
                l[pre].push_back(i);
                pre = i;
            }
            else if (!vis[i]) {
                r[i].push_back(pre);
            }
        }
    }

    std::vector<int> ans;

    std::vector<int> resl(n * n + 2, 1), froml(n * n + 2);
    for (int u = 1;u <= n * n + 1;++u) {
        if (resl[u] == n + 1) {
            int x = u;
            while (x) {
                ans.push_back(x);
                x = froml[x];
            }
            ranges::sort(ans);
            std::cout << "! ";
            for (auto x : ans)std::cout << x << " ";
            std::cout << std::endl;
            return;
        }
        for (auto v : l[u]) {
            if (resl[v] < resl[u] + 1) {
                resl[v] = resl[u] + 1;
                froml[v] = u;
            }
        }
    }

    std::vector<int> resr(n * n + 2, 1), fromr(n * n + 2);
    // for (auto x : r[3])std::cout << x << ' ';std::cout << '\n';
    // for (auto x : r[4])std::cout << x << ' ';std::cout << '\n';
    // for (auto x : r[5])std::cout << x << ' ';std::cout << '\n';

    for (int u = n * n + 1;u >= 1;--u) {
        if (resr[u] == n + 1) {
            int x = u;
            while (x) {
                ans.push_back(x);
                x = fromr[x];
            }
            ranges::sort(ans);
            std::cout << "! ";
            for (auto x : ans)std::cout << x << " ";
            std::cout << std::endl;
            return;
        }
        for (auto v : r[u]) {
            if (resr[v] < resr[u] + 1) {
                resr[v] = resr[u] + 1;
                fromr[v] = u;
            }
        }
    }

    assert(0);
}

signed main() {
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}