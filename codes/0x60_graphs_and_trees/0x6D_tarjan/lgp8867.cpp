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

template<class T>
constexpr T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

constexpr i64 mul(i64 a, i64 b, i64 p) {
    i64 res = a * b - i64(1.L * a * b / p) * p;
    res %= p;
    if (res < 0) {
        res += p;
    }
    return res;
}
template<i64 P>
struct MLong {
    i64 x;
    constexpr MLong() : x{} {}
    constexpr MLong(i64 x) : x{ norm(x % getMod()) } {}

    static i64 Mod;
    constexpr static i64 getMod() {
        if (P > 0) {
            return P;
        }
        else {
            return Mod;
        }
    }
    constexpr static void setMod(i64 Mod_) {
        Mod = Mod_;
    }
    constexpr i64 norm(i64 x) const {
        if (x < 0) {
            x += getMod();
        }
        if (x >= getMod()) {
            x -= getMod();
        }
        return x;
    }
    constexpr i64 val() const {
        return x;
    }
    explicit constexpr operator i64() const {
        return x;
    }
    constexpr MLong operator-() const {
        MLong res;
        res.x = norm(getMod() - x);
        return res;
    }
    constexpr MLong inv() const {
        assert(x != 0);
        return power(*this, getMod() - 2);
    }
    constexpr MLong& operator*=(MLong rhs)& {
        x = mul(x, rhs.x, getMod());
        return *this;
    }
    constexpr MLong& operator+=(MLong rhs)& {
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr MLong& operator-=(MLong rhs)& {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr MLong& operator/=(MLong rhs)& {
        return *this *= rhs.inv();
    }
    friend constexpr MLong operator*(MLong lhs, MLong rhs) {
        MLong res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr MLong operator+(MLong lhs, MLong rhs) {
        MLong res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr MLong operator-(MLong lhs, MLong rhs) {
        MLong res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr MLong operator/(MLong lhs, MLong rhs) {
        MLong res = lhs;
        res /= rhs;
        return res;
    }
    friend constexpr std::istream& operator>>(std::istream& is, MLong& a) {
        i64 v;
        is >> v;
        a = MLong(v);
        return is;
    }
    friend constexpr std::ostream& operator<<(std::ostream& os, const MLong& a) {
        return os << a.val();
    }
    friend constexpr bool operator==(MLong lhs, MLong rhs) {
        return lhs.val() == rhs.val();
    }
    friend constexpr bool operator!=(MLong lhs, MLong rhs) {
        return lhs.val() != rhs.val();
    }
};

template<>
i64 MLong<0LL>::Mod = i64(1E18) + 9;

template<int P>
struct MInt {
    int x;
    constexpr MInt() : x{} {}
    constexpr MInt(i64 x) : x{ norm(x % getMod()) } {}

    static int Mod;
    constexpr static int getMod() {
        if (P > 0) {
            return P;
        }
        else {
            return Mod;
        }
    }
    constexpr static void setMod(int Mod_) {
        Mod = Mod_;
    }
    constexpr int norm(int x) const {
        if (x < 0) {
            x += getMod();
        }
        if (x >= getMod()) {
            x -= getMod();
        }
        return x;
    }
    constexpr int val() const {
        return x;
    }
    explicit constexpr operator int() const {
        return x;
    }
    constexpr MInt operator-() const {
        MInt res;
        res.x = norm(getMod() - x);
        return res;
    }
    constexpr MInt inv() const {
        assert(x != 0);
        return power(*this, getMod() - 2);
    }
    constexpr MInt& operator*=(MInt rhs)& {
        x = 1LL * x * rhs.x % getMod();
        return *this;
    }
    constexpr MInt& operator+=(MInt rhs)& {
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr MInt& operator-=(MInt rhs)& {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr MInt& operator/=(MInt rhs)& {
        return *this *= rhs.inv();
    }
    friend constexpr MInt operator*(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr MInt operator+(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr MInt operator-(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr MInt operator/(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res /= rhs;
        return res;
    }
    friend constexpr std::istream& operator>>(std::istream& is, MInt& a) {
        i64 v;
        is >> v;
        a = MInt(v);
        return is;
    }
    friend constexpr std::ostream& operator<<(std::ostream& os, const MInt& a) {
        return os << a.val();
    }
    friend constexpr bool operator==(MInt lhs, MInt rhs) {
        return lhs.val() == rhs.val();
    }
    friend constexpr bool operator!=(MInt lhs, MInt rhs) {
        return lhs.val() != rhs.val();
    }
};

template<>
int MInt<0>::Mod = 998244353;

template<int V, int P>
constexpr MInt<P> CInv = MInt<P>(V).inv();

constexpr int P = 1000000007;
using Z = MInt<P>;

struct Tarjan {
    int n;
    std::vector<std::vector<int>> adj;
    std::vector<int> stk;
    std::vector<int> dfn, low, isb, bel;
    std::vector<Z> dp;
    int cur, cnt;

    Tarjan() {}
    Tarjan(int n) {
        init(n);
    }

    void init(int n) {
        this->n = n;
        adj.assign(n, {});
        dfn.assign(n, -1);
        low.assign(n, -1);
        dp.assign(n, 0);
        isb.assign(n, 0);
        bel.assign(n, -1);
        stk.clear();
        cur = cnt = 0;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void dfs(int x, int p) {
        // std::cout << x << ' ' << p << '\n';
        dfn[x] = low[x] = cur++;
        stk.push_back(x);

        for (auto y : adj[x]) if (y != p) {
            if (dfn[y] == -1) {
                dfs(y, x);
                low[x] = std::min(low[x], low[y]);
            }
            else if (dfn[y] < dfn[x]) { //返祖边
                low[x] = std::min(low[x], dfn[y]);
            }
        }
        if (p != -1 && low[x] > dfn[p]) {
            while (stk.back() != x) {
                bel[stk.back()] = cnt;
                stk.pop_back();
            }
            bel[x] = cnt;
            // std::cout << stk.back() << '\n';
            stk.pop_back();
            cnt++;
        }
        // std::cout << x << " " << dfn[x] << ' ' << low[x] << '\n';
    }

    Z work() {
        std::vector<Z> p2(1, 1);
        auto pow2 = [&](int p) {
            for (int i = p2.size();i <= p;++i) {
                p2.push_back(p2.back() * 2);
            }
            return p2[p];
            };
        for (int i = 0; i < n; i++) {
            if (dfn[i] == -1) {
                dfs(i, -1);
                while (stk.size()) {
                    bel[stk.back()] = cnt;
                    stk.pop_back();
                }
                cnt++;
            }
        }
        // for (int x : bel)std::cout << x << ' ';std::cout << '\n';
        std::vector<int> cntp(cnt), cnte(cnt), vis(cnt);
        std::vector g(cnt, std::vector<int>());
        int ec = 0;
        for (int i = 0;i < n;++i) {
            int x = bel[i];
            cntp[x]++;
            for (auto j : adj[i])if (j > i) {
                int y = bel[j];
                if (x == y) {
                    cnte[x]++;
                    ec++;
                    // std::cout << i << ' ' << j << ' ' << x << '\n';
                }
                else {
                    g[x].push_back(y);
                    g[y].push_back(x);
                    ec++;
                    // std::cout << x << ' ' << y << '\n';
                }
            }
        }
        // std::cout << ec << '\n';
        std::vector<std::array<Z, 2>> dp(cnt);
        std::vector<Z> mul(cnt);
        for (int i = 0;i < cnt;++i) {
            mul[i] = pow2(cntp[i] + cnte[i]);
            // std::cout << mul[i] << ' ' << cntp[i] << " " << cnte[i] << '\n';
        }
        Z ans = 0;
        auto dfs2 = [&](auto&& self, int u, int p) ->void {
            // std::cout << u << ' ' << p << '\n';
            vis[u] = 1;
            dp[u][1] = mul[u];
            dp[u][0] = pow2(cnte[u]);
            // if (u == 1)std::cout << cnte[u] << ' ';
            for (auto v : g[u])if (!vis[v]) {
                // std::cout << u << ' ' << v << '\n';
                self(self, v, u);
                dp[u][1] *= dp[v][1] + pow2(cnte[v]);
                dp[u][0] *= dp[v][0] + pow2(cnte[v]);
                cnte[u] += cnte[v] + 1;
            }
            ans += (dp[u][1] - dp[u][0]) * pow2(ec - cnte[u] - (p != -1));
            // std::cout << u << ' ' << dp[u][0] << ' ' << dp[u][1] << ' '
            //     << (dp[u][1] - dp[u][0]) * power(2, ec - cnte[u] - (p != -1)) << '\n';
            };
        for (int i = 0;i < cnt;++i)if (!vis[i]) {
            // std::cout << "i: " << i << '\n';
            dfs2(dfs2, i, -1);
        }
        return ans;
    }
};


void solve() {
    int n, m;std::cin >> n >> m;
    Tarjan tj(n);
    for (int i = 0;i < m;++i) {
        int u, v;std::cin >> u >> v;
        u--, v--;
        tj.addEdge(u, v);
        tj.addEdge(v, u);
    }
    auto ans = tj.work();
    std::cout << ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}