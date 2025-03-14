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
    std::vector<pii> info(n);
    for (auto& [x, y] : info)std::cin >> x >> y;
    ranges::sort(info);
    int p = 0, ans = 0, i = 0;
    std::multiset<int> set;
    while (i < info.size()) {
        p = info[i].first;
        while (i < info.size() && info[i].first <= p) {
            set.insert(info[i].second);i++;
            // std::cout << info[i].second << " ";
        }
        while (set.size()) {
            int x = *set.begin();
            set.erase(set.begin());
            if (x < p)continue;
            p++;
            ans++;
            while (i < info.size() && info[i].first <= p) {
                // std::cout << info[i].second << " ";
                set.insert(info[i].second);i++;
            }
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