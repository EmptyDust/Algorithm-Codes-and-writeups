#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 998244353;
using pii = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    i64 n, k;std::cin >> n >> k;
    if (n < k) {
        std::cout << 0;
        return 0;
    }
    std::vector<i64> f(n), fact(k + 1), mul(k + 1);
    i64 fst = fact[0] = 1, sum = 0;
    for (i64 i = 1;i <= k;++i)
        fact[i] = fst = fst * i % mod;
    mul[0] = -1;
    for (i64 i = 1;i <= k;++i) {
        for (i64 j = 0;j < i;++j) {
            mul[i] -= mul[j] * fact[i - j] % mod;
            mul[i] %= mod;
        }
    }
    f[k - 1] = fst;
    for (int i = 0;i < n;++i) {
        auto& cur = f[i];
        for (int j = i + 1;j < n && j - i <= k;++j) {
            f[j] = (f[j] + f[i] * mul[j - i] % mod) % mod;
        }
    }
    std::cout << f.back();
    return 0;
}


//1 2 [3 4 5 6 7 1 2] 3
//1 2 [3 4 5 6 7 2 1] 3
//1 [2 3 4 5 6 7 1] 3 2
//[1 2 3 4 5 6 7] 2 3 1
//[1 2 3 4 5 6 7] 3 1 2
//[1 2 3 4 5 6 7] 3 2 1

//1 2 3 [4 5 6 7 1 2 3] 4
//1 2 [3 4 5 6 7 1 2] 4 3
//1 2 3 [4 5 6 7 1 3 2] 4
//1 [2 3 4 5 6 7 1] 3 4 2
//1 [2 3 4 5 6 7 1] 4 2 3
//1 [2 3 4 5 6 7 1] 4 3 2

//1 2 3 4 5 6 7 2 1 3 4
//1 2 3 4 5 6 7 2 1 4 3
//1 2 3 4 5 6 7 2 3 1 4
//1 2 3 4 5 6 7 2 3 4 1
//1 2 3 4 5 6 7 2 4 1 3
//1 2 3 4 5 6 7 2 4 3 1

//1 2 3 4 5 6 7 3 1 2 4
//1 2 3 4 5 6 7 3 1 4 2
//1 2 3 4 5 6 7 3 2 1 4
//1 2 3 4 5 6 7 3 2 4 1
//1 2 3 4 5 6 7 3 4 1 2
//1 2 3 4 5 6 7 3 4 2 1

//1 2 3 4 5 6 7 4 1 2 3
//1 2 3 4 5 6 7 4 1 3 2
//1 2 3 4 5 6 7 4 2 1 3
//1 2 3 4 5 6 7 4 2 3 1
//1 2 3 4 5 6 7 4 3 1 2
//1 2 3 4 5 6 7 4 3 2 1


//1 2 1 2 1
//1 2 2 1 2
//1 2 1 1 2