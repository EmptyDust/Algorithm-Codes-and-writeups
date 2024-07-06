#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int n, k;std::cin >> n >> k;
    std::vector<i64> a(n);
    for (auto& x : a)std::cin >> x;
    std::sort(a.begin(), a.end(), [&](auto a, auto b) {
        if (a % k != b % k)return a % k < b % k;
        return a < b;
        });
    bool f = n % 2;
    i64 ans = 0;
    for (int i = 0;i < n - 1;i += 2) {
        if (a[i] % k != a[i + 1] % k) {
            if (f)f = false, i--;
            else {
                std::cout << -1;
                return;
            }
        }
        else ans += (a[i + 1] - a[i]) / k;
    }
    if (n % 2) {
        std::map<int, int> mp;
        for (int x : a)mp[x % k]++;
        int y;
        for (auto [x, cnt] : mp)if (cnt % 2) {
            y = x;
        }
        std::vector<int> bl, oth;
        for (int i = 0;i < n;++i) {
            if (a[i] % k == y)bl.push_back(a[i]);
            else {
                oth.push_back(a[i]);
            }
        }
        i64 res = 0;
        for (int i = 0;i < oth.size();i += 2) {
            res += (oth[i + 1] - oth[i]) / k;
        }
        int m = bl.size();
        std::vector<int> suf(m);
        i64 cur = 0;
        for (int i = m - 2;i > 0;i -= 2) {
            cur += (bl[i + 1] - bl[i]) / k;
            suf[i] = cur;
        }
        cur = 0;
        for (int i = 0;i < m - 1;i += 2) {
            ans = std::min(ans, res + cur + suf[i + 1]);
            cur += (bl[i + 1] - bl[i]) / k;
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