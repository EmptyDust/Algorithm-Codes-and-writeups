#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    int n, k;
    std::cin >> n >> k;
    for (int i = 0;i < 2 * n;++i)std::cin >> nums[i];
    std::vector<int> g, ao, bo;
    std::map<int, int> mp;
    for (int i = 0;i < n;++i)mp[nums[i]]++;
    for (int i = 1;i <= n;++i) {
        int& cur = mp[i];
        if (cur == 2) {
            ao.push_back(i);
        }
        else if (cur == 1) {
            g.push_back(i);
        }
        else {
            bo.push_back(i);
        }
    }
    std::vector<int> aans, bans;
    for (int i = 0;i < ao.size() && i < bo.size() && i < k;++i) {
        aans.push_back(ao[i]);
        aans.push_back(ao[i]);
        bans.push_back(bo[i]);
        bans.push_back(bo[i]);
    }
    int t = aans.size();
    for (int i = t;i < 2 * k;++i) {
        aans.push_back(g[i - t]);
        bans.push_back(g[i - t]);
    }
    for (int num : aans)std::cout << num << ' ';
    std::cout << '\n';
    for (int num : bans)std::cout << num << ' ';
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