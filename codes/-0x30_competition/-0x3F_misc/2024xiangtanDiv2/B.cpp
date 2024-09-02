#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n, m;std::cin >> n >> m;
    std::vector<int> a(n + 1);
    std::vector<u64> b(n + 1);
    for (int i = 1;i <= n;++i)
        std::cin >> a[i];
    for (int i = 1;i <= n;++i)
        if (a[i] > m) {
            std::cout << "NO";
            return;
        }
    std::vector<bool> ok(n + 1);
    std::set<int> s1, s2;
    for (int i = n;i >= 1;--i) {
        if (s1.count(a[i]))break;
        s1.insert(a[i]);
        ok[i] = 1;
    }
    if (m > n) {
        for (int i = 0;i < n;++i) {
            if (s2.count(a[i]))break;
            s2.insert(a[i]);
            if (ok[i + 1]) {
                std::cout << "YES";
                return;
            }
        }
        std::cout << "NO";
        return;
    }
    std::vector<u64> y(m + 1);
    u64 e = 0;
    for (int i = 1;i <= m;++i) {
        y[i] = rng();
        e ^= y[i];
    }
    // std::cout << e << ' ';
    for (int i = 1;i <= n;++i)
        b[i] = y[a[i]];
    for (int i = 1;i <= n;++i)
        b[i] ^= b[i - 1];
    // std::cout << (b[4] ^ b[1]);
    // std::cout << ok[6] << ' ';
    for (int i = 0;i < n;++i) {
        if (s2.count(a[i]))break;
        s2.insert(a[i]);
        int j = i;
        while (j + m < n) {
            // std::cout << j << '\n';
            if (e != (b[j + m] ^ b[j])) {
                break;
            }
            j += m;
        }
        // std::cout << i << ' ' << j << '\n';
        if (ok[j + 1]) {
            std::cout << "YES";
            return;
        }
    }
    std::cout << "NO";
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}