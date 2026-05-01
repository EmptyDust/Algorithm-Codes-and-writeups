#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

std::vector<int> primes;
int next_p[MAXN];
void init() {
    for (int i = 2;i <= N;++i)if (!next_p[i]) {
        primes.push_back(i);
        next_p[i] = i;
        for (i64 j = 1ll * i * i;j <= N;j += i) {
            next_p[j] = i;
        }
    }
}

std::vector<int> factors(int x) {
    std::vector<int> res{ 1 };
    while (x > 1) {
        int k = res.size();
        int p = next_p[x];
        int cur = 1;
        while (x % p == 0) {
            cur *= p;
            for (int i = 0;i < k;++i) {
                res.push_back(res[i] * cur);
            }
            x /= p;
        }
    }
    return res;
}

int l[MAXN];
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    init();
    memset(l, -1, sizeof l);
    int n;std::cin >> n;
    for (int i = 0;i < n;++i) {
        int x, y;std::cin >> x >> y;
        int ans = 0;
        for (int f : factors(x)) {
            if (i - l[f] > y)ans++;
            // std::cout << f << ' ' << i - l[f] << '\n';
            l[f] = i;
        }
        std::cout << ans << '\n';
    }
    return 0;
}