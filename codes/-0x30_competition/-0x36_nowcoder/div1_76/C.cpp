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
const int mod = 1e9 + 7;
// const int mod = 998244353;

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

std::vector<int> fact(1, 1);
std::vector<int> inv_fact(1, 1);
i64 comb(int n, int k) {
    if (k<0 || k>n)return 0;
    while ((int)fact.size() < n + 1) {
        fact.push_back(1ll * fact.back() * (int)fact.size() % mod);
        inv_fact.push_back(inv(fact.back()));
    }
    return 1ll * fact[n] * inv_fact[k] % mod * inv_fact[n - k] % mod;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> g[2 * n + 1];
    std::string s;std::cin >> s;
    std::vector<int> bian(n << 2, -1);
    std::stack<pii> st;
    for (int i = 0;i < (n << 2);++i) {
        st.push({ s[i] == '1',i });
        if (st.size() >= 4) {
            auto d = st.top();st.pop();
            auto c = st.top();st.pop();
            auto b = st.top();st.pop();
            auto a = st.top();st.pop();
            if (!a.first && !b.first && c.first && d.first) {
                bian[a.second] = 0;
                bian[d.second] = 1;
            }
            else {
                st.push(a);
                st.push(b);
                st.push(c);
                st.push(d);
            }
        }
    }
    if (st.size()) {
        std::cout << 0;
        return;
    }
    std::vector<int> a;
    for (int x : bian)
        if (x != -1)
            a.push_back(x);
    // for (int x : a)std::cout << x << ' ';
    int idx = 1;
    std::stack<int> Fa;
    Fa.push(0);
    for (int i = 0;i < 2 * n;++i) {
        if (!a[i]) {
            // std::cout << Fa.size() << ' ';
            g[Fa.top()].push_back(i + 1);
            Fa.push(i + 1);
        }
        else {
            Fa.pop();
        }
    }
    i64 ans = 1;
    std::function<int(int)> dfs = [&](int u) {
        int sz = 0;
        std::vector<int> s;
        for (int v : g[u]) {
            int vsz = dfs(v);
            sz += vsz;
            s.push_back(vsz);
        }
        int _sz = sz;
        for (int x : s) {
            ans = ans * comb(_sz, x) % mod;
            _sz -= x;
        }
        return sz + 1;
        };
    dfs(0);
    // std::cout << g[3].size() << ' ';
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