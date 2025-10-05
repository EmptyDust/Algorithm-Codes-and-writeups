#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<int, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

// 2 3 3 3
// 2 2 2 2 3

// 

i64 qpow(i64 x, i64 p) {
    if (p <= 0) return 1;
    i64 ret = 1;
    while (p) {
        if (p & 1)ret = ret * x % mod;
        p >>= 1;
        x = x * x % mod;
    }
    return ret;
}

void solve() {
    std::vector<int> cnt(11);
    for (int i = 1;i <= 9;++i)std::cin >> cnt[i];
    i64 mul = 1;

    if (cnt[1] <= cnt[2]) {
        cnt[3] += cnt[1];
        cnt[2] -= cnt[1];
        cnt[1] = 0;
    }
    else {
        cnt[3] += cnt[2];
        cnt[1] -= cnt[2];
        cnt[2] = 0;
        cnt[3] += cnt[1] / 3;
        cnt[1] %= 3;
    }

    if (cnt[1] == 2) {
        cnt[2] = 1;
        cnt[1] = 0;
    }

    if (cnt[1] == 1) {
        bool f = 1;
        for (int i = 2;i <= 9;++i) {
            if (cnt[i]) {
                cnt[i]--;
                cnt[i + 1]++;
                cnt[1] = 0;
                f = 0;
                break;
            }
        }
        if (f) {
            std::cout << 1;
            return;
        }
    }

    for (int i = 2;i <= 10;++i)mul = mul * qpow(i, cnt[i]) % mod;

    std::cout << mul;
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