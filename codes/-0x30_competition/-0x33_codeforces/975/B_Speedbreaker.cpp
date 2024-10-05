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
    std::vector<int> a(n), zbs(n);
    for (int& x : a)std::cin >> x;
    std::iota(zbs.begin(), zbs.end(), 0);
    ranges::sort(zbs, [&](int x, int y) {return a[x] < a[y];});
    int cnt = 0, l = n - 1, r = 0;
    int L = 0, R = n - 1;
    bool ok = false;
    int ans = 0;
    for (int p : zbs) {
        cnt++;
        l = std::min(l, p);
        r = std::max(r, p);
        if (r - l + 1 > a[p]) {
            std::cout << 0;
            return;
        }
        if (!ok && a[p] == r - l + 1) {
            L = l, R = r;
            for (int i = l;i <= r;++i) {
                L = std::max(L, i - a[i] + 1);
                R = std::min(R, i + a[i] - 1);
            }
            ans = R - L + 1;
            ok = true;
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