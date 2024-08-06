#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;

int y[MAXN], a[MAXN];
bool check(int l, int r) {
    int ida = 0;
    for (int i = l;i <= r;++i)a[ida++] = y[i];
    std::sort(a, a + ida);
    for (int i = 0;i <= ida - 6;++i) {
        for (int j = i + 1;j < i + 6;++j) {
            for (int k = j + 1;k < i + 6;++k) {
                int b[4];int idb = 0;
                for (int x = i + 1;x < i + 6;++x)
                    if (x != j && x != k)
                        b[idb++] = a[x];
                if (a[i] + a[j] > a[k] && b[0] + b[1] > b[2])
                    return true;
            }
        }
    }
    int cnt = 0;
    for (int i = 0;i < ida - 2;++i) {
        if (a[i] + a[i + 1] > a[i + 2]) {
            i += 2;
            cnt++;
        }
    }
    return cnt > 1;
}

void solve() {
    int n, q;std::cin >> n >> q;
    for (int i = 1;i <= n;++i)std::cin >> y[i];
    std::map<pii, int> p;
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        int res;
        if (p.count({ l,r }))
            res = p[{l, r}];
        else
            res = (r - l + 1 >= 48 || check(l, r));
        p[{l, r}] = res;
        if (res)
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;//std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}