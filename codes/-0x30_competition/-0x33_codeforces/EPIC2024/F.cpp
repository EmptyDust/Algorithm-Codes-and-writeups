#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;

void solve() {
    int n;std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1;i <= n;++i)std::cin >> a[i];
    int cnt = 0;
    std::deque<a3> pts;
    std::vector<int> check(n + 1);
    for (int i = n - 1;i >= 1;--i) {
        int pos;
        for (int j = 1;j <= n;++j)if (j == a[i])pos = j;
        if (pos == i) {
            int ad = 0;
            for (auto& [cur, need, pos] : pts) {
                if (check[pos])continue;
                cur += ad;
                if (cur == need) {
                    ad++;
                    cnt++;
                    bool f = false;
                    for (int j = pos + 1;j < n;++j) {
                        if (!check[j]) {

                        }
                    }
                }
            }
        }
        else if (pos < i && (i - pos) % 2 == 0) {
            pts.push_front({ 0, (i - pos) / 2 ,i });
        }
    }
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