#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<i64, i64>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    i64 n, m, k, q;std::cin >> n >> m >> k >> q;
    std::vector<pii> a(n + 1);a[0] = { 0,0 };
    std::vector<i64> len(n + 1);
    for (int i = 1;i <= k;++i) {
        char c;std::cin >> c;
        i64 l;std::cin >> l;
        len[i] = len[i - 1] + l;
        switch (l)
        {
        case 'U':
            a[i] = { a[i - 1].first,a[i - 1].second + l };
            break;
        case 'R':
            a[i] = { a[i - 1].first + l,a[i - 1].second };
            break;
        case 'D':
            a[i] = { a[i - 1].first,a[i - 1].second - l };
            break;
        case 'L':
            a[i] = { a[i - 1].first - l,a[i - 1].second };
            break;
        default:
            break;
        }
    }
    while (q--) {
        i64 x, y, l, r;std::cin >> x >> y >> l >> r;
        pii ch = { a[r].first - a[l - 1].first, a[r].second - a[l - 1].second };
        pii ans = { x + ch.first ,y + ch.second };
        i64 ll = len[r] - len[l - 1];
        std::cout << ans.first << ' ' << ans.second << " " << ll << '\n';
    }
    return 0;
}