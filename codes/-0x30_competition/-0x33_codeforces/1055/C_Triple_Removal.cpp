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
    int n, q;std::cin >> n >> q;
    std::vector<int> a(n + 1), cnt01(n + 1), cnt10(n + 1), cnt0(n + 1), cnt1(n + 1);
    for (int i = 1;i <= n;++i)std::cin >> a[i];
    if (a[1]) cnt1[1]++;
    else cnt0[1]++;
    for (int i = 2;i <= n;++i) {
        if (a[i] == 1 && a[i - 1] == 0) cnt01[i]++;
        if (a[i] == 0 && a[i - 1] == 1) cnt10[i]++;
        if (a[i] == 1) cnt1[i]++;
        if (a[i] == 0) cnt0[i]++;
        cnt01[i] += cnt01[i - 1];
        cnt10[i] += cnt10[i - 1];
        cnt1[i] += cnt1[i - 1];
        cnt0[i] += cnt0[i - 1];
    }
    while (q--) {
        int l, r;std::cin >> l >> r;
        int len = r - l + 1;
        if (len % 3 || (cnt1[r] - cnt1[l - 1]) % 3 || (cnt0[r] - cnt0[l - 1]) % 3) {
            std::cout << -1 << '\n';
            continue;
        }
        int ans = len / 3;
        int a = cnt01[r] - cnt01[l];
        int b = cnt10[r] - cnt10[l];
        if (len % 2) {
            if (a == len / 2 && b == len / 2)ans++;
        }
        else {
            // std::cout << a << ' ' << b << '\n';
            if (a == len / 2 || b == len / 2)ans++;
        }
        std::cout << ans << '\n';
    }
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