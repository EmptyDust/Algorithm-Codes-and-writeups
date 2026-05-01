#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int num, n;
using pt = std::pair<int, int>;

void solve() {
    std::cin >> n;
    std::vector<int> cnt(n + 1);
    for (int i = 1;i <= n;++i) {
        std::cin >> num;
        cnt[num]++;
    }
    std::vector<int> ans(n + 10), cnts;
    for (int x : cnt)if (x)cnts.push_back(x);
    int sz = cnts.size();
    for (int x : cnts) {
        int sq = sqrt(x);
        ans[1]++;
        ans[x / sq + 1]--;
    }
    for (int i = 1;i <= n;++i)ans[i] += ans[i - 1];
    for (int x : cnts) {
        int sq = sqrt(x), lim = x / sq;
        for (int i = 1;i <= sq + 1;++i) {
            if (x / i + 1 > lim)ans[x / i + 1]++;
            if (x % i == 0 && x / i > lim)ans[x / i]++;
        }
    }
    //for (int i = 1;i <= n;++i)std::cout << ans[i] << ' ';
    int s;
    for (int i = n;i >= 1;--i)if (ans[i] == sz) {
        s = i;
        break;
    }
    //std::cout << s << '\n';
    int m = 0;
    for (int x : cnts)
        m += x / s + (x % s > 0);
    std::cout << m;
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