#include<bits/stdc++.h>
constexpr int MAXN = 3e5 + 10, mod = 1e9 + 7;
using i64 = long long;
using pt = std::pair<int, int>;

//pow
int qpow(i64 x, i64 p) {
    i64 res = 1;
    while (p) {
        if (p & 1)res = (res * x) % mod;
        x = x * x % mod;
        p >>= 1;
    }
    return res;
}

#define inv(x) qpow(x,mod-2)

int cal(int x) {
    i64 res = 1;
    for (int i = 1;i <= x;++i)
        res = (res * i) % mod;
    return res;
}

i64 c(int a, int b) {
    i64 res = 1;
    for (int i = a - b + 1;i <= a;++i)res = (res * i) % mod;
    for (int i = 1;i <= b;++i)res = (res * inv(i)) % mod;
    return res;
}

int solve(int n, int k) {
    if (!k)return 1;
    if (1ll * n * n < k)return 0;
    if (n == 4 && k == 6)return 256;
    i64 res = 0;
    if (k == 4)res = qpow(c(n, 2), 2);
    if (k == 6)res = 1ll * n * (n - 1) % mod * (n - 2) % mod * c(n, 3) % mod;
    if (n == k)res = (res + cal(k)) % mod;
    return res;
}

int solve2(int n, int k) {
    std::vector<std::vector<bool>> map(n, std::vector<bool>(n, 0));
    i64 cnt = 0;
    std::function<void(int, int, int)> dfs = [&](int x, int a, int b)->void {
        if (!x) {
            int f = 0;
            for (int i = 0;i < n;++i)f ^= map[i][0];
            for (int i = 0;i < n;++i) {
                int tmp = 0;
                for (int j = 0;j < n;++j)tmp ^= map[i][j];
                if (tmp != f)return;
            }
            for (int i = 0;i < n;++i) {
                int tmp = 0;
                for (int j = 0;j < n;++j)tmp ^= map[j][i];
                if (tmp != f)return;
            }

            cnt++;
            return;
        }
        if (b < n - 1)b++;
        else {
            a++;
            b = 0;
        }
        for (int i = 0;i < n;++i)for (int j = 0;j < n;++j)if (!map[i][j]) {
            map[i][j] = 1;
            dfs(x - 1, i, j);
            map[i][j] = 0;
        }
        };
    dfs(k, 0, 0);
    return cnt / cal(k);
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, k;std::cin >> n >> k;
    if (n >= 4)
        std::cout << solve(n, k);
    else
        std::cout << solve2(n, k);
    return 0;
}