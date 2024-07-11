#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int n;std::cin >> n;

    std::vector<int> a(n + 1), b(n + 1);
    std::vector<std::vector<int>> posa(n + 1), posb(n + 1);

    for (int i = 1;i <= n;++i) {
        int p;std::cin >> p;
        int g = std::__gcd(i, p);
        a[i] = p / g;
        b[i] = i / g;
        posa[a[i]].push_back(i);
        posb[b[i]].push_back(i);
    }

    std::vector<std::vector<int>> div(n + 1);
    for (int i = 1;i <= n;++i) {
        for (int j = i;j <= n;j += i) {
            div[j].push_back(i);
        }
    }

    i64 ans = 0;
    std::vector<int> cnt(n + 1);

    for (int bi = 1;bi <= n;++bi) {
        for (int aj = bi;aj <= n;aj += bi) {
            for (auto j : posa[aj]) {
                cnt[b[j]]++;
            }
        }
        for (auto i : posb[bi]) {
            for (auto j : div[a[i]]) {
                ans += cnt[j];
            }
        }
        for (int aj = bi;aj <= n;aj += bi) {
            for (auto j : posa[aj]) {
                cnt[b[j]]--;
            }
        }
    }

    for (int i = 1;i <= n;++i) {
        if (b[i] == 1) {
            ans--;
        }
    }

    ans /= 2;
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