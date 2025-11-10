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

void print(int x, int n) {
    std::string out;
    for (int i = 0;i < n;++i) {
        out += (x & 1) ? '1' : '0';
        x >>= 1;
    }
    ranges::reverse(out);
    std::cout << out << '\n';
}

std::vector<int> vis(1 << 20);
std::vector<int> restore;

void solve() {
    int n, k, m;std::cin >> n >> k >> m;
    // std::cout << n << ' ' << k << ' ' << m << '\n';
    if (m == 0) {
        std::cout << 0 << '\n';
        return;
    }
    if (k == 0) {
        std::cout << 0 << '\n';
        std::cout << std::string(n, '0') << '\n';
        return;
    }
    std::cout << (k * m - 1) / n + 1 << '\n';
    std::vector<int> p;
    auto next = [&](int x) {
        if (x & 1) {
            x = (x >> 1) | (1 << n - 1);
        }
        else {
            x = x >> 1;
        }
        return x;
        };
    int mask = (1 << k) - 1;
    for (int i = 0;i < n;++i) {
        // print(mask, n);
        vis[mask] = 1;
        restore.push_back(mask);
        p.push_back(mask);
        mask = next(mask);
    }
    int cur = 0;
    for (unsigned int i = 0;i < (1 << n) && cur + p.size() < m;++i)if (!vis[i] && std::popcount(i) == k) {
        std::vector<int> tmp;
        int mask = i;
        int cnt = 0;
        for (int j = 0;j < n;++j) {
            vis[mask] = 1;
            restore.push_back(mask);
            // print(mask, n);
            tmp.push_back(mask);
            cnt++;
            mask = next(mask);
            if (mask == i)break;
        }
        if (cur + cnt <= m) {
            for (auto x : tmp) print(x, n);
            cur += cnt;
            // std::cout << cur << ' ';
        }
    }
    if (cur == m) return;
    for (int i = 0;i < std::gcd(n, k);++i) {
        for (int j = i, t = 0;t < n / std::gcd(n, k);j = (j + k) % n, t++) {
            // std::cout << j << ' ';
            print(p[j], n);
            cur++;
            if (cur == m) return;
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
        for (auto x : restore)vis[x] = 0;
        restore.clear();
    }
    return 0;
}








/*

1 0 0
1 0 1
1 1 0
1 1 1
2 0 0
2 0 1
2 1 0
2 1 1
2 1 2
2 2 0
2 2 1
3 0 0
3 0 1
3 1 0
3 1 1
3 1 2
3 1 3
3 2 0
3 2 1
3 2 2
3 2 3
3 3 0
3 3 1
4 0 0
4 0 1
4 1 0
4 1 1
4 1 2
4 1 3
4 1 4
4 2 0
4 2 1
4 2 2
4 2 3
4 2 4
4 2 5
4 2 6
4 3 0
4 3 1
4 3 2
4 3 3
4 3 4
4 4 0
4 4 1
5 0 0
5 0 1
5 1 0
5 1 1
5 1 2

*/