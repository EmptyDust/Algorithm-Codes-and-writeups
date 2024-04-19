#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    std::map<std::string, int> mp;
    std::cin >> n;
    std::vector<pt> songs(n);
    int ID = 0;
    std::string s, t;
    for (int i = 0;i < n;++i) {
        std::cin >> s >> t;
        if (!mp.count(s))
            mp[s] = ID++;
        if (!mp.count(t))
            mp[t] = ID++;
        songs[i].first = mp[s];
        songs[i].second = mp[t];
    }
    std::vector<std::vector<int>> map(n);
    for (int i = 0;i < n;++i)for (int j = 0;j < n;++j) {
        if (i == j)continue;
        if (songs[i].first == songs[j].first || songs[i].second == songs[j].second) {
            map[i].push_back(j);
            map[j].push_back(i);
        }
    }
    std::vector<std::vector<int>> st(n, std::vector<int>(1 << n, 0));
    for (int i = 0;i < n;++i)st[i][1 << i] = 1;
    for (int s = 2;s <= n;++s) {
        for (int x = 0;x < n;++x) {
            for (int i = 0;i < (1 << n);++i)if (st[x][i] && std::__popcount(i) == s - 1) {
                for (int nxt : map[x])if ((i & 1 << nxt) == 0) {
                    st[nxt][i | (1 << nxt)] = 1;
                }
            }
        }
    }
    int ans = 0;
    for (int x = 0;x < n;++x) {
        for (int i = 0;i < (1 << n);++i)if (st[x][i]) {
            ans = std::max(ans, std::__popcount(i));
        }
    }
    std::cout << n - ans;
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