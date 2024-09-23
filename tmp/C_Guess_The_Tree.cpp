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

int query(int x, int y) {
    int r;
    std::cout << "? " << x << ' ' << y << std::endl;
    std::cin >> r;
    return r;
}

void solve() {
    int n;std::cin >> n;
    std::vector<pii> ans;
    for (int i = 2;i <= n;++i) {
        int r = 1, l = i;
        while (1) {
            int x = query(l, r);
            if (x == l) {
                ans.push_back({ l,r });
                break;
            }
            r = x;
        }
    }
    std::cout << "! ";
    for (auto [x, y] : ans)std::cout << x << " " << y << ' ';
    std::cout << std::endl;
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