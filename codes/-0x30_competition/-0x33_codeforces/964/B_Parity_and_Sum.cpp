#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
#define int long long

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
    std::ranges::sort(a);
    {
        bool ok = true;
        for (int x : a)if (x % 2 == 0)ok = false;
        if (ok) {
            std::cout << 0;
            return;
        }
    }
    int max_odd = -1;
    for (int i = 0;i < n;++i)if (a[i] % 2)max_odd = a[i];
    if (max_odd == -1) {
        std::cout << 0;
        return;
    }
    bool f = false;
    int ans = 0;
    for (int i = 0;i < n;++i) {
        if (a[i] % 2)max_odd = std::max(max_odd, a[i]);
        else {
            if (a[i] < max_odd || f) {
                ans++;
                max_odd = std::max(max_odd, a[i] + max_odd);
            }
            else {
                ans += 2;
                f = true;
            }
        }
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