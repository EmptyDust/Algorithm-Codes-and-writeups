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
    int n, m;std::cin >> n >> m;
    std::vector<std::string> info(n);
    for (auto& s : info)std::cin >> s, s += s;
    std::vector<pii> idx(n);
    for (int i = 0;i < n;++i) idx[i] = { i,i };
    auto radix_sort = [&](int i) {
        ranges::sort(idx, [&](pii& a, pii& b) {
            if (info[a.first][i] == info[b.first][i])
                return a.second < b.second;
            return info[a.first][i] > info[b.first][i];
            });
        for (int j = 0;j < n;++j) {
            idx[j].second = j;
        }
        };
    std::vector<int> ans;ans.reserve(m);
    for (int i = 2 * m - 1;i >= 0;--i) {
        radix_sort(i);
        if (i < m)ans.push_back(idx[0].first + 1);
    }
    ranges::reverse(ans);
    for (auto x : ans)std::cout << x << " ";
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