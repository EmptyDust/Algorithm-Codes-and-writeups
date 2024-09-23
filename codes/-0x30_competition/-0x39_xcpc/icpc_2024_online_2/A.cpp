#include<bits/stdc++.h>

using i64 = long long;
using pii = std::pair<int, int>;
const int inf = 1e9;

struct isi
{
    int w;
    std::string s;
    int id;
};


void solve() {
    int n, k;std::cin >> n >> k;
    int minc = inf;
    for (int i = 0;i < k;++i) {
        int x;std::cin >> x;
        minc = std::min(minc, x);
    }
    std::map<std::string, int> mp;
    int cnt = 0;
    std::vector<isi> info(n);
    int idx = 0;
    for (auto& [w, s, id] : info) std::cin >> w >> s, id = idx++;
    std::sort(info.begin(), info.end(), [&](isi a, isi b) {
        return a.w > b.w;
        });
    std::vector<int> ans(n);
    for (auto [w, s, id] : info) {
        mp[s]++;
        if (mp[s] <= minc)cnt++;
        ans[id] = cnt;
    }
    for (int x : ans)std::cout << x << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;//std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}