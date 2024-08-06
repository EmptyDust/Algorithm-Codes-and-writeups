#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = (1 << 21) - 1, MAXN = 2e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

struct T
{
    int a, b;
    T() { a = -inf;b = -inf; }
    T(int x) { a = x;b = -inf; }
    T(int x, int y) { a = x;b = y; }
    T operator+(T t) {
        int x = a;
        if (x > t.a) {
            std::swap(x, t.a);
        }
        t.b = std::max(t.b, b);
        if (x != t.a) {
            t.b = std::max(t.b, x);
        }
        return t;
    }
}Ts[N + 1];

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n;std::cin >> n;
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    for (int i = 0;i < n;++i)
        Ts[a[i]] = Ts[a[i]] + T(i);

    for (int s = 0;s < 21;++s)
        for (int mask = 0;mask <= N;++mask)
            if (!(mask >> s & 1))
                Ts[mask] = Ts[mask ^ (1 << s)] + Ts[mask];

    int ans = 0;
    for (int s = 20;s >= 0;--s) {
        ans |= 1 << s;
        bool ok = false;
        for (int i = 0;i < n;++i) {
            if (Ts[ans & ~a[i]].b > i) {
                ok = true;
                break;
            }
        }
        if (!ok)ans ^= 1 << s;
    }
    std::cout << ans;

    return 0;
}