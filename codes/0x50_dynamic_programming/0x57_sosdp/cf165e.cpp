#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = (1 << 22) - 1, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

int Ts[N + 1];

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    memset(Ts, -1, sizeof Ts);
    int n;std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0;i < n;++i) {
        std::cin >> a[i];
        Ts[a[i]] = a[i];
    }
    for (int s = 0;s < 22;++s)
        for (int mask = 0;mask <= N;++mask)
            if (mask >> s & 1 && Ts[mask ^ (1 << s)] != -1)
                Ts[mask] = Ts[mask ^ (1 << s)];

    for (int i = 0;i < n;++i) {
        int mask = N ^ a[i];
        std::cout << Ts[mask] << ' ';
    }

    return 0;
}