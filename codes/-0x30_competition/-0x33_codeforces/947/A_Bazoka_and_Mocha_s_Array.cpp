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
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    for (int t = 0;t < n;++t) {
        // for (int x : a)std::cout << x << ' ';std::cout << '\n';
        bool ok = true;
        for (int i = 1;i < n;++i) {
            if (a[i] < a[i - 1])ok = false;
        }
        if (ok) {
            std::cout << "YES";
            return;
        }
        int tmp = a[0];
        for (int i = 1;i < n;++i) {
            a[i - 1] = a[i];
        }
        a.back() = tmp;
    }
    std::cout << "NO";
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