#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int n, M;
using pt = std::pair<int, int>;

i64 qpow(i64 x, i64 p, i64 mod) {
    i64 ret = 1;
    while (p) {
        if (p & 1)ret = ret * x % mod;
        p >>= 1;
        x = x * x % mod;
    }
    return ret;
}

#define inv(x) qpow(x,mod-2)

void exGCD(i64 a, i64 b, i64& x, i64& y) {
    if (!b) x = 1, y = 0;
    else exGCD(b, a % b, y, x), y -= a / b * x;
}
/*
i64 merge(i64 a1, i64 m1, i64 a2, i64 m2, i64& newM) {
    if (m1 < m2)std::swap(a1, a2), std::swap(m1, m2);
    //a2>a1
    i64 gcd = std::__gcd(m1, m2);
    i64 minus = a2 - a1;
    if (minus % gcd)return -1;
    //m1p-m2q=a2-a1
    i64 x, y;
    exGCD(m1, m2, x, y);
    //m1y+m2x=gcd
    x *= minus / gcd;
    y *= minus / gcd;
    std::cout << x << ' ' << y << '\n';
    i64 b = m1 * x + a1;
    if (M / m2 < m1 / gcd) {
        if (2e18 / m2 < m1 / gcd)return -1;
        i64 tmp = m1 / gcd * m2;
        newM = -1;
        return (b % tmp + tmp) % tmp;
    }
    newM = m1 / gcd * m2;
    return (b % newM + newM) % newM;//m1/gcd*m2
}
*/
void solve() {
    std::cin >> n >> M;
    std::vector<pt> pts;
    std::map<i64, i64> f;
    std::set<i64> st;
    for (auto [m, y] : pts) {
        std::cin >> m >> y;
        for (int i = 2;i <= std::sqrt(m);++i)if (m % i == 0) {
            i64 cur = 1;
            while (m % i == 0) {
                m /= i;
                cur *= i;
                if (f.count(cur) && f[cur] != y % cur) {
                    std::cout << "de";
                    return;
                }
                f[cur] = y % cur;
                st.erase(cur);
            }
            st.insert(cur);
        }
    }
    std::vector<pt> cal;
    for (auto x : st) {
        cal.push_back({ x,f[x] });// n a
    }
    int s = cal.size();
    for (int i = 0;i < s;++i) {
        i64 mi = 1;
        for (int j = 0;j < s;++j)if (i != j) {
            mi = mi * cal[j].first % cal[i].first;
        }
        i64 mi_r = qpow(mi, cal[i].first - 2, cal[i].first);
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    solve();
    return 0;
}