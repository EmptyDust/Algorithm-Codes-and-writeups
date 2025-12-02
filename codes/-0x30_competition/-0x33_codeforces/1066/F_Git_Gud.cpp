#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<int, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n;std::cin >> n;
    int K = 60;
    std::vector<int> cur(n);
    std::iota(cur.begin(), cur.end(), 1);
    std::vector<a2> ans;
    int cnt = 0;
    while (cur.size() > 1) {
        if (cnt >= 2) {
            for (int i = 1;i < cur.size();++i) {
                ans.push_back({ cur[i - 1], cur[i] - cur[i - 1] });
            }
            break;
        }
        std::vector<int> ncur;
        for (int j = 0;j < K - 1;++j) {
            std::vector<a2> tmp;
            for (int i = 0;i < cur.size();i += K) {
                if (i + j + 1 < cur.size()) {
                    if (j == K - 2) {
                        ncur.push_back(cur[i + j + 1]);
                        // std::cout << ncur.back() << ' ';
                    }
                    tmp.push_back({ cur[i + j], cur[i + j + 1] - cur[i + j] });
                    // if (cnt == 1) std::cout << cur[i + j] << '\n';
                }
            }
            ranges::reverse(tmp);
            for (auto& it : tmp) ans.push_back(it);
        }
        cur = ncur;
        if (cur.size() && cur.back() != n) cur.push_back(n);
        // for (auto x : cur) std::cout << x << ' ';std::cout << '\n';
        cnt++;
        // if (cnt == 2)break;
    }
    // std::cout << cnt << '\n';
    i64 sum = 0, pre = inf;
    std::cout << ans.size() << '\n';
    for (auto [x, y] : ans) {
        std::cout << x << ' ' << y << '\n';
        sum += y;
        if (pre < x) sum += 1000;
        pre = x;
    }
    // std::cout << sum << '\n';
    // assert(sum <= 1'000'000);
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}