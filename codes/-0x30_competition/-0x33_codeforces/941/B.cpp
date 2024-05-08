#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> mp(n);
    for (auto& s : mp)std::cin >> s;
    {
        bool allw1 = true, allb1 = true;
        for (int i = 0;i < m;++i) {
            if (mp[0][i] == 'W')allb1 = false;
            if (mp[0][i] == 'B')allw1 = false;
        }
        bool allw2 = true, allb2 = true;
        for (int i = 0;i < m;++i) {
            if (mp[n - 1][i] == 'W')allb2 = false;
            if (mp[n - 1][i] == 'B')allw2 = false;
        }
        if (allw1 && allb2 || allw2 && allb1) {
            std::cout << "No";
            return;
        }
    }
    {
        bool allw1 = true, allb1 = true;
        for (int i = 0;i < n;++i) {
            if (mp[i][0] == 'W')allb1 = false;
            if (mp[i][0] == 'B')allw1 = false;
        }
        bool allw2 = true, allb2 = true;
        for (int i = 0;i < n;++i) {
            if (mp[i][m - 1] == 'W')allb2 = false;
            if (mp[i][m - 1] == 'B')allw2 = false;
        }
        if (allw1 && allb2 || allw2 && allb1) {
            std::cout << "No";
            return;
        }
    }
    std::cout << "Yes";
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