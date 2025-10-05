#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using d64 = long double;
using ld = float;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int dx[8] = { -1, 0, 1, 0, -1, -1, 1, 1 }, dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 1e18;
const int mod = 1e9 + 7;

void solve()
{
    // printf("%.10lf", 0.3);
    // std::cout << '\n';
    i64 ppmax, a, b, c, d, e, f;
    std::cin >> ppmax >> a >> b >> c >> d >> e >> f;
    i64 acc_d = 300 * a + 300 * b + 200 * c + 100 * d + 50 * e;
    i64 acc_d_by = 300 * (a + b + c + d + e + f);
    i64 acc = round(acc_d * (d64)10000.0 / acc_d_by);
    i64 pp_d = 320 * a + 300 * b + 200 * c + 100 * d + 50 * e;
    i64 pp_d_by = 320 * (a + b + c + d + e + f);
    int pp;
    d64 ppo = pp_d * (d64)1.0 / pp_d_by;
    // std::cout << pp_d << ' ' << pp_d_by << ' ' << pp_d * (d64)1.0 / pp_d_by << ' ';
    if (ppo < 0.8 + 1e-4) {
        pp = 0;
    }
    else {
        ppo = (d64)1.0 * 5 * ppmax * pp_d / pp_d_by;
        pp = round(ppo) - 4 * ppmax;
    }
    // std::cout << ppo << ' ';
    std::cout << (d64)acc / 100 << "% " << pp << '\n';
    // printf("%.2lf%% %d\n", acc, pp);
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout << std::fixed << std::setprecision(2);
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
        // std::cout << '\n';
    }
}