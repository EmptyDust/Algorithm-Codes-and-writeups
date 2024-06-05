#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    i64 n, m;
    std::cin >> n >> m;
    std::vector<i64> a(n + m + 1), b(a), ans(a);
    for (auto& x : a)std::cin >> x;
    for (auto& x : b)std::cin >> x;
    i64 cnt1 = 0, cnt2 = 0;
    bool f;
    if (cnt1 == n) {
        f = true;
    }
    else if (cnt2 == m) {
        f = false;
    }
    else for (int i = 0;i <= n + m;++i) {
        if (a[i] > b[i])cnt1++;
        else cnt2++;
        if (cnt1 == n) {
            f = true;
            break;
        }
        if (cnt2 == m) {
            f = false;
            break;
        }
    }
    if (!f)std::swap(a, b), std::swap(n, m);
    i64 sum = 0;
    cnt1 = 0;
    i64 pos = inf;
    for (int i = 0;i < n + m;++i) {
        if (cnt1 == n && a[i] > b[i])pos = i, cnt1++;
        if (cnt1 < n && a[i] > b[i])sum += a[i], cnt1++;
        else sum += b[i];
    }
    ans[n + m] = sum;
    for (int i = 0;i < n + m;++i) {
        if (a[i] < b[i] || i >= pos && pos != inf) {
            ans[i] = ans[n + m] - b[i] + b[n + m];
        }
        else if (pos == inf) {
            ans[i] = ans[n + m] - a[i] + a[n + m];
        }
        else {
            ans[i] = ans[n + m] - a[i] + a[pos] - b[pos] + b[n + m];
        }
    }
    for (auto x : ans)std::cout << x << ' ';
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