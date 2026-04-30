#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;


int cnt[MAXN];

void solve() {
    int n;std::cin >> n;
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    i64 sum = std::accumulate(a.begin(), a.end(), 0ll);
    std::vector<int> b(n);
    int mx = 0;
    for (int i = 0;i < n;++i) {
        cnt[a[i]]++;
        if (cnt[a[i]] >= 2 && mx < a[i]) {
            mx = a[i];
        }
        b[i] = mx;
    }
    sum += std::accumulate(b.begin(), b.end(), 0ll);
    for (int x : a)cnt[x] = 0;

    mx = 0;
    for (int i = 0;i < n;++i) {
        cnt[b[i]]++;
        if (cnt[b[i]] >= 2 && mx < b[i]) {
            mx = b[i];
        }
        sum += 1ll * (n - i) * mx;
    }
    for (int x : b)cnt[x] = 0;

    std::cout << sum;
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