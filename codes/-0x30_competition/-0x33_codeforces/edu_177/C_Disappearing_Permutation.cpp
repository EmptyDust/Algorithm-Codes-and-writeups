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
    std::vector<int> a(n), b(n), v(n);
    for (int& x : a)std::cin >> x, x--;
    for (int& x : b)std::cin >> x, x--;
    int cnt = 0;
    for (auto x : b) {
        if (v[x]) {
            std::cout << cnt << ' ';
            continue;
        }
        int y = a[x];
        v[y] = 1;
        cnt++;
        while (y != x) {
            v[y] = 1;
            cnt++;
            y = a[y];
        }
        std::cout << cnt << ' ';
    }
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