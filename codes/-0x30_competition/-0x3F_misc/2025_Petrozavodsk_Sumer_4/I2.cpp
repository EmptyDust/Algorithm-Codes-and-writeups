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
    for (int x = n;x >= 1;--x) {
        int pos = std::find(p.begin(), p.end(), x) - p.begin();
        int tar = f[pos];
        if (tar > pos) {
            std::cout << "NO\n";
            return;
        }
        std::vector<int> stk(1, pos);
        for (int i = pos - 1;i >= tar;--i) if (p[i] < x) {
            while (p[stk.back()] < p[i]) stk.pop_back();
            stk.push_back(i);
        }
        // for (auto x : stk)std::cout << x << " ";std::cout << '\n';
        for (int i = 1;i < stk.size();++i) {
            swap(stk[i], stk[i - 1]);
        }
        // for (auto x : p)std::cout << x << ' ';std::cout << '\n';
        // std::cout << p.size() << '\n';
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