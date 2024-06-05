#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    int n;std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int& x : a)std::cin >> x;
    for (int& x : b)std::cin >> x;
    int m;std::cin >> m;
    std::vector<int> d(m);
    for (int& x : d)std::cin >> x;
    std::map<int, int> mp, mp2;
    for (int i = 0;i < n;++i) {
        if (a[i] != b[i])
            mp[b[i]]++;
        mp2[b[i]]++;
    }
    bool f = true;
    for (int x : d) {
        if (mp.count(x)) {
            mp[x]--;
            if (mp[x] == 0)mp.erase(x);
        }
        if (!mp2.count(x))f = false;
        else f = true;
    }
    std::cout << (f && mp.empty() ? "YES" : "NO");
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