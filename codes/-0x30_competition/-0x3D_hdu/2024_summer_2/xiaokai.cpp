#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<i64, i64>;

i64 frac15 = 1;

struct Frac
{
    std::vector<int> cnt;
    Frac() {
        cnt.assign(16, 0);
    }
    Frac(std::vector<int> cnt) {
        this->cnt = cnt;
    }
    Frac operator+(Frac f) {
        std::vector<int> cnt;
        for (int i = 1;i <= 15;++i) {
            cnt[i] = this->cnt[i] + f.cnt[i];
        }
        return Frac(cnt);
    }
    bool operator<(Frac f) {
        auto xa = cal();
        auto ya = f.cal();
        return xa < ya;
    }
    i64 cal() {
        i64 a = 0;
        for (int i = 1;i <= 15;++i) {
            a += cnt[i] * (frac15 / i);
            // std::cout << cnt[i] << ' ';
        }
        return a;
    }
    void print() {
        auto a = cal();
        i64 g = std::__gcd(a, frac15 / 15);
        std::cout << a / g << '/' << frac15 / 15 / g << '\n';
    }
};


void solve() {
    int n;std::cin >> n;
    std::vector<int> adj[n];
    for (int i = 1;i < n;++i) {
        int u, v;std::cin >> u >> v;u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::vector<int> a(n);
    for (int& x : a)
        std::cin >> x;
    std::function<Frac(int, int)> dfs = [&](int x, int p)->Frac {
        Frac cur;
        for (int nxt : adj[x])if (p != nxt) {
            auto res = dfs(nxt, x);
            if (cur < res) {
                cur = res;
            }
        }
        cur.cnt[a[x]]++;
        // std::cout << x << ' ';
        // cur.print();
        return cur;
        };
    dfs(0, -1).print();
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    for (int i = 1;i <= 15;++i) {
        frac15 *= i;
    }
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}