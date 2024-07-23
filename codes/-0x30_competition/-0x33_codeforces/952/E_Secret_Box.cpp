#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    i64 x, y, z, k;std::cin >> x >> y >> z >> k;
    //(x-a)(y-b)(z-c)  a*b*c = k
    //(xy - ay - bx + ab)(z-c)
    //xyz-ayz-bxz +abz -cxy+acy+bcx-abc
    i64 ans = 0;
    i64 ksq = std::sqrt(k);
    for (int i = 1;i <= std::min(2000ll, ksq);++i) if (k % i == 0) {
        i64 a = k / i;
        i64 k2 = i;
        i64 k2sq = std::sqrt(k2);
        for (int b = 1;b <= std::min(2900ll, k2sq);++b)if (k2 % b == 0) {
            i64 c = k2 / b;
            std::vector<i64> p{ a,b,c };
            do {
                if (x >= p[0] && y >= p[1] && z >= p[2])
                    ans = std::max(ans, (x - p[0] + 1) * (y - p[1] + 1) * (z - p[2] + 1));
            } while (std::next_permutation(p.begin(), p.end()));
        }

        a = i;
        k2 = k / i;
        k2sq = std::sqrt(k2);
        for (int b = 1;b <= std::min(2900ll, k2sq);++b)if (k2 % b == 0) {
            i64 c = k2 / b;
            std::vector<i64> p{ a,b,c };
            do {
                if (x >= p[0] && y >= p[1] && z >= p[2])
                    ans = std::max(ans, (x - p[0] + 1) * (y - p[1] + 1) * (z - p[2] + 1));
            } while (std::next_permutation(p.begin(), p.end()));
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