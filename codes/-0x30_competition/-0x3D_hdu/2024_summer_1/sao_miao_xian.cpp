#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 998244353;
using pii = std::pair<int, int>;
using a4 = std::array<int, 4>;

template<typename T>
struct Fenwick {
    int n;
    std::vector<T> a;

    Fenwick(int n_ = 0) {
        init(n_);
    }

    void init(int n_) {
        n = n_;
        a.assign(n + 5, T{});
    }

    void add(int x, const T& v) {
        for (int i = x; i <= n; i += i & -i) {
            a[i] = a[i] + v;
        }
    }

    T sum(int x) {
        T ans{};
        for (int i = x; i > 0; i -= i & -i) {
            ans = ans + a[i];
        }
        return ans;
    }

    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }

    int select(const T& k) {
        int x = 0;
        T cur{};
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && cur + a[x + i] <= k) {
                x += i;
                cur = cur + a[x];
            }
        }
        return x;
    }
};

i64 qpow(i64 x, i64 p) {
    i64 ret = 1;
    while (p) {
        if (p & 1)ret = ret * x % mod;
        p >>= 1;
        x = x * x % mod;
    }
    return ret;
}

#define inv(x) qpow(x,mod-2)

struct Mi64 {
    i64 value = 0;
    Mi64() {}
    Mi64(i64 value) { this->value = value; }
    Mi64 operator * (const i64 w) {
        return value * w % mod;
    }
    Mi64 operator * (const Mi64 w) {
        return value * w.value % mod;
    }
    Mi64 operator + (const Mi64 w) {
        return (value + w.value) % mod;
    }
    Mi64 operator - (const Mi64 w) {
        return((value - w.value) % mod + mod) % mod;
    }
    bool operator == (const Mi64 w) {
        return value == w.value;
    }
}comb[2011][2011];

void init() {
    int M = 2010;
    for (int i = 0;i <= M;++i) {
        comb[i][0] = 1;
        for (int j = 1;j <= i;++j) {
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    init();
    int n;std::cin >> n;
    std::vector<a4> ps;
    std::set<int> ys;
    for (int i = 0;i < n;++i) {
        int x1, x2, y1, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2)std::swap(x1, x2);
        if (y1 > y2)std::swap(y1, y2);
        ys.insert(y1);
        ys.insert(y2);
        ps.push_back({ x1,y1,y2,1 });
        ps.push_back({ x2,y1,y2,-1 });
    }
    std::unordered_map<int, int> mp, inv_mp;
    int idx = 1;
    for (int x : ys) {
        inv_mp[idx] = x;
        mp[x] = idx++;
    }

    std::vector<Mi64> fg(n + 1, 0);
    std::sort(ps.begin(), ps.end());
    for (auto& [cur, d, u, op] : ps) {
        d = mp[d];
        u = mp[u];
    }
    Fenwick<int> fw(ys.size() + 10);
    for (int i = 0;i < 2 * n - 1;++i) {
        auto [cur, d, u, op] = ps[i];
        int len = ps[i + 1][0] - cur;
        fw.add(d, op);
        fw.add(u, -op);
        // std::cout << inv_mp[d] << " " << op << '\n';
        // std::cout << inv_mp[u] << " " << -op << '\n';
        // std::cout << '\n';
        for (int j = 1;j < idx - 1;++j) {
            int ylen = inv_mp[j + 1] - inv_mp[j];
            int cnt = fw.sum(j);
            fg[cnt] = fg[cnt] + 1ll * ylen * len;
            // std::cout << cur << ' ' << ps[i + 1][0] << ' ' << inv_mp[j] << ' ' << inv_mp[j + 1]
            //     << ' ' << cnt << '\n';
        }
    }

    // std::cout << '\n';
    // for (int j = 1;j <= n;++j)std::cout << fg[j] << ' ';
    // std::cout << '\n';

    for (int i = 1;i <= n;++i) {
        Mi64 ans = 0;
        Mi64 inv_sum = inv(comb[n][i].value);
        for (int j = 1;j <= n;++j) {
            ans = ans + (inv_sum * comb[n - j][i] * -1 + 1) * fg[j];
        }
        ans = ans - 0;
        std::cout << ans.value << '\n';
    }
    return 0;
}