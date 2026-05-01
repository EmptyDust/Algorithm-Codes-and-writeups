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

using i128 = __int128;

std::istream& operator>>(std::istream& is, i128& n) {
    std::string s;is >> s;
    n = 0;
    for (char i : s) n = n * 10 + i - '0';
    return is;
}
std::ostream& operator<<(std::ostream& os, i128 n) {
    if (n == 0) {
        return os << 0;
    }
    std::string s;
    while (n) {
        s += '0' + n % 10;
        n /= 10;
    }
    std::reverse(s.begin(), s.end());
    return os << s;
}

template<typename T>
struct TWOCRT {//中国剩余定理&扩展中国剩余定理
    std::vector<T> m, r;
    TWOCRT() {};
    TWOCRT(T n) {
        m.resize(n + 1);
        r.resize(n + 1);
    };
    TWOCRT(std::vector<T> _m, std::vector<T> _r) {
        m = _m;
        r = _r;
    }
    T exgcd(T a, T b, __int128& x, __int128& y) {
        if (b == 0) {
            x = 1, y = 0;
            return a;
        }
        T gcd = exgcd(b, a % b, y, x);
        y -= (a / b) * x;
        return gcd;
    }
    T CRT() {
        T M = 1, ans = 0;
        int n = m.size() - 1;
        for (int i = 1; i <= n; i++)M *= m[i];
        for (int i = 1; i <= n; i++) {
            T c = M / m[i], x, y;
            exgcd(c, m[i], x, y);
            ans = (ans + r[i] * c * x % M) % M;
        }
        return (ans % M + M) % M;
    }

    T EXCRT() { //有x=r1(mod m1),x=r2(mod m2)
        i128 m1, m2, r1, r2, p, q;                //转化为x=m1*p+r1=m2*q+r2  (1)
        m1 = m[1], r1 = r[1];                   //m1*p-m2*q=r2-r1
        int n = m.size() - 1;
        for (int i = 2; i <= n; i++) {
            m2 = m[i], r2 = r[i];
            i128 d = exgcd(m1, m2, p, q);
            if ((r2 - r1) % d) { return -1; }      //由裴蜀定理-->> 当gcd(m1,m2)|(r2-r1)时 有解
            p = p * (r2 - r1) / d;//特解            //由扩欧算法得 特解p=p*(r2-r1)/gcd,q=q*(r2-r1)/gcd
            p = (p % (m2 / d) + m2 / d) % (m2 / d);//p可能是负数，为了方便要使p变成正数,通解--》P=p+m2/gcd*k,Q=q-m1/gcd*k
            r1 = m1 * p + r1;                     //x=m1*P+r1=(m1*m2)/gcd*k+m1*p1+r1,与（1）比对
            m1 = m1 * m2 / d;                      //得r=m1*p+r1,m=lcm(m1,m2)
        }
        return (r1 % m1 + m1) % m1;
    }
};

void solve() {
    i128 n, m, k;std::cin >> n >> m >> k;
    std::vector<i128> a(k), module(1, 0), rest(1, 0);
    for (auto& x : a)std::cin >> x;
    i128 N = 1;
    for (int i = 0;i < k;++i) {
        i128 gcd = std::__gcd(a[i], N);
        //lcm = a * b / gcd
        if (n >= N / gcd * a[i]) {
            N = N / gcd * a[i];
        }
        else {
            std::cout << "NO";
            return;
        }
        module.push_back(a[i]);
        rest.push_back(((a[i] - i) % a[i] + a[i]) % a[i]);
        // std::cout << module.back() << ' ' << rest.back() << '\n';
    }
    TWOCRT<i128> excrt(module, rest);
    i128 res = excrt.EXCRT();
    // std::cout << res << ' ' << N << '\n';
    if (res == 0)res = N;
    if (res == -1) {
        std::cout << "NO";
        return;
    }
    res = res + k - 1;
    if (res > m) {
        std::cout << "NO";
        return;
    }
    res = res - k + 1;
    for (i128 i = res;i < res + k;++i) {
        if (std::__gcd(i, N) != a[i - res]) {
            // std::cout << i << ' ' << std::__gcd(i, N) << ' ' << a[i - res] << '\n';
            std::cout << "NO";
            return;
        }
    }
    std::cout << "YES";
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