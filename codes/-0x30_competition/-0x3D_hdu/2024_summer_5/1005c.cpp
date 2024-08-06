#include <bits/stdc++.h>

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
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    int gcd = a[0];
    for (int x : a)gcd = std::__gcd(gcd, x);
    for (int x : a)if (x == gcd) {
        std::cout << n - 1;
        return;
    }
    for (int x : a)for (int y : a) {
        if (x % y && gcd % (x % y) == 0) {
            std::cout << n;
            return;
        }
    }
    std::vector<int> b, vis(n);
    for (int i = 0;i < n;++i)if (!vis[i])
        for (int j = 0;j < n;++j)if (!vis[j] && i != j) {
            if (a[j] % a[i] == 0) {
                vis[j] = 1;
            }
        }
    for (int i = 0;i < n;++i)if (!vis[i])b.push_back(a[i]);
    // for (int x : b)std::cout << x << ' ';
    int m = b.size();
    if (m == 2) {
        std::cout << n;
        return;
    }
    int x = *std::min_element(b.begin(), b.end());
    if (std::count(b.begin(), b.end(), x) == 1) {
        int gcd = -1;
        for (int i = 0;i < n;++i)if (x != b[i]) {
            if (gcd == -1)gcd = b[i];
            else gcd = std::__gcd(gcd, b[i]);
        }
        if (gcd >= x) {
            std::cout << n;
            return;
        }
    }
    std::cout << n + 1;
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