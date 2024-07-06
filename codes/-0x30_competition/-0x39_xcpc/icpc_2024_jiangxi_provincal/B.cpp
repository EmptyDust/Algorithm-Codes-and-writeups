#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    i64 n, p;std::cin >> n >> p;
    std::vector<i64> v(n);
    for (auto& x : v)std::cin >> x;
    i64 k, t0;std::cin >> k >> t0;
    if (t0 >= std::min(n - p + 1, p) + n - 1) {
        i64 res = std::accumulate(v.begin(), v.end(), (i64)0) + n * t0 * k;
        res -= (n - 1) * k * n / 2;
        std::cout << res;
        return;
    }

    i64 res = 0;
    auto work = [&](std::vector<i64> v, int p) {
        std::vector<i64> pre(n);i64 sum = 0;
        for (int i = 0;i < n;++i)pre[i] = sum += v[i];
        i64 cur = 0;
        for (int r = p;r < n;++r) {
            i64 len = r - p + 1, lst = t0 - len, l = r - lst;
            if (len > t0)break;
            cur += v[r] + len * k;
            res = std::max(res, cur);
            i64 T = t0;
            i64 tmp = cur;
            if (l < 0) {
                if (l < -1)continue;
                tmp += (r + 1) * k;
                T--;
                l = 0;
            }
            if (l >= p) {
                tmp = (1 + lst) * k * lst / 2 + lst * lst * k - (lst - 1) * k * lst / 2;
                res = std::max(res, tmp);
            }
            else {
                len = r - p;
                tmp += (1 + len) * k * len / 2 + len * len * k - (len - 1) * k * len / 2;
                tmp += pre[p - 1] - (l ? pre[l - 1] : 0);
                len = p - l;
                tmp += len * (T - len) * k + len * len * k - (len - 1) * k * len / 2;
                //std::cout << p << ' ' << l << ' ' << r << ' ' << len * (t0 - len) * k << '\n';
                res = std::max(res, tmp);
            }
        }
        };
    /*
    100 100 100 1 100
    102 102 102 0 102  3
    104 104 104 2 0    107
    106 106 106 4 0    109
    108 108 108 0      115
    110 110 0          225
    112 0              337
    0                  451
    */
    work(v, p - 1);
    std::reverse(v.begin(), v.end());
    work(v, n - p);

    std::cout << res;
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