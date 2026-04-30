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
    i64 n, l, r;std::cin >> n >> l >> r;
    std::vector<i64> a(n + 1), p(n + 1), ps(n + 1);
    for (int i = 1;i <= n;++i) {
        std::cin >> a[i];
        p[i] = p[i - 1] ^ a[i];
        ps[i] = ps[i - 1] + a[i];
    }
    i64 N = 1 << (std::__lg(n));
    for (int i = n + 1;i <= N;++i) {
        a[i] = p[i / 2];
        p[i] = p[i - 1] ^ a[i];
        ps[i] = ps[i - 1] + a[i];
    }
    n = N;

    //p | s
    //0 | 1 -> 1 1 -> 0 0 1 1 -> 1 1 1 1 0 0 1 1 -> 0 0 1 1 0 0 1 1 1 1 1 1 0 0 1 1
    // -> 1 1 1 1 0 0 1 1 1 1 1 1 0 0 1 1 0 0 1 1 0 0 1 1 1 1 1 1 0 0 1 1
    //1 | 1 -> 0 0 -> 0 0 0 0 -> 
    //0 | 0 -> 0 0 -> 0 0 0 0 -> 
    //1 | 0 -> 1 1 -> 0 0 1 1 -> 1 1 1 1 0 0 1 1


    //0 | 0 0 -> 
    //1 | 0 0 -> 1 1 1 1 info[1][i] = 2 * info[3][i - 1]
    //0 | 1 1 -> 1 1 0 0 -> 1 1 0 0 0 0 0 0
    //1 | 1 1 -> 0 0 1 1 info[3][i] = info[1][i - 1] + info[3][i - 1]

    std::vector info(4, std::vector<i64>(64));
    // info[2][0] = info[3][0] = 1;
    info[3][1] = 2;

    for (int i = 1;i <= 63;++i) {
        info[1][i] = 2 * info[3][i - 1];
        info[2][i] = 2;
        info[3][i] = info[1][i - 1] + info[3][i - 1];
    }

    int P = p[n];
    i64 ans = 0, cur = 0;;
    for (int i = n / 2 + 1;i <= n;++i) {
        for (int t = 60;t >= 0;--t) {
            i64 s = 1ll << t;
            if (i >> (60 - t))continue;
            i64 L = i * s, R = i * s * 2 - 1;
            int st = P + a[i];
            if (l <= L && R <= r) {
                std::cout << i << ' ' << t << ' ' << L << " " << R << "\n";
                if (t) ans += info[st][t];
                else ans += a[i];
                cur += s;
            }
            else if (l <= L) {
                
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