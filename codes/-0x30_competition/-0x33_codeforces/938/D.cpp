#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    int n, m, k;std::cin >> n >> m >> k;
    std::vector<int> a(n), b(m);
    for (int& num : a)std::cin >> num;
    for (int& num : b)std::cin >> num;
    std::map<int, int> sn, has;
    for (int& num : b)sn[num]++;
    std::map<int, int> nd(sn);
    int p = 0;
    for (int i = 0;i < m;++i) {
        has[a[i]]++;
        if (nd.count(a[i])) {
            nd[a[i]]--;
            if (nd[a[i]] == 0)nd.erase(a[i]);
            p++;
        }
    }
    int ans = (p >= k);
    for (int i = 0;i < n - m;++i) {
        has[a[i]]--;
        if (has[a[i]] < sn[a[i]]) {
            p--;
            nd[a[i]]++;
        }
        int nw = i + m;
        has[a[nw]]++;
        if (nd.count(a[nw])) {
            nd[a[nw]]--;
            if (nd[a[nw]] == 0)nd.erase(a[nw]);
            p++;
        }
        if (p >= k)ans++;
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