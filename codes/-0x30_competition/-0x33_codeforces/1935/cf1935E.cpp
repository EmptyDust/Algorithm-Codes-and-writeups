#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

struct E
{
    int det;
    int dub;
};

void solve() {
    std::cin >> n;
    std::vector<std::vector<E>> Es(30, std::vector<E>(n + 1, { 0,0 }));
    int x, y;
    for (int i = 1;i <= n;++i) {
        std::cin >> x >> y;//y>x
        for (int p = 0;p < 30;++p)
            Es[p][i].det = (y >> p) & 1;
        if (x == y)continue;
        int lg = std::__lg(x ^ y);
        for (int p = 0;p <= lg;++p)
            Es[p][i].dub = Es[p][i].det;
    }
    for (int i = 1;i <= n;++i) {
        for (int p = 0;p < 30;++p) {
            Es[p][i].det += Es[p][i - 1].det;
            Es[p][i].dub += Es[p][i - 1].dub;
        }
    }
    int q;std::cin >> q;
    while (q--) {
        int l, r;std::cin >> l >> r;
        bool f = false;
        int res = 0;
        for (int p = 29;~p;--p) {
            int det = Es[p][r].det - Es[p][l - 1].det;
            int dub = Es[p][r].dub - Es[p][l - 1].dub;
            if (det >= 2 && dub >= 1)f = true;
            if (f || det)res |= 1 << p;
        }
        std::cout << res << ' ';
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