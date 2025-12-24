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

#define int long long

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const int mod = 1e9 + 7;
// const int mod = 998244353;

i64 qpow(i64 x, i64 p) {
    x %= mod;
    i64 ret = 1;
    while (p) {
        if (p & 1)ret = ret * x % mod;
        p >>= 1;
        x = x * x % mod;
    }
    return ret;
}

#define inv(x) qpow(x,mod-2)

void solve() {
    int n, q;std::cin >> n >> q;
    std::vector<i64> a(n + 1), presum(n + 1), sufsum(n + 2);
    for (int i = 1;i <= n;++i) std::cin >> a[i];
    ranges::sort(a);
    for (int i = 1;i <= n;++i) presum[i] = (presum[i - 1] + a[i]) % mod;
    for (int i = n;i >= 1;--i) sufsum[i] = (sufsum[i + 1] + a[i]) % mod;
    std::vector PSUM(n + 1, std::vector<i64>(1, 0));
    std::vector SSUM(n + 1, std::vector<i64>(1, 0));
    for (int j = 1; j <= n;++j) {
        for (int i = j;i <= n;i += j) {
            PSUM[j].push_back((PSUM[j].back() + (presum[i] - presum[i - j]) * (presum[i] - presum[i - j]) % mod) % mod);
        }
        for (int i = n + 1 - j;i >= 1;i -= j) {
            SSUM[j].push_back((SSUM[j].back() + (sufsum[i] - sufsum[i + j]) * (sufsum[i] - sufsum[i + j]) % mod) % mod);
            // if (j == 5) std::cout << SSUM[j].back() << '\n';
        }
    }
    // auto cal = [&](int l, int r, int d) {
    //     if (d <= B) return ((SUM[d][r] - SUM[d][l]) % mod + mod) % mod;
    //     i64 res = 0;
    //     for (int i = l + d; i <= r; ++i) {
    //         res = (res + (a[i] - a[i - d]) * (a[i] - a[i - d]) % mod) % mod;
    //     }
    //     return res;
    //     };
    while (q--) {
        i64 l, r;std::cin >> l >> r;
        i64 L = n / l;
        i64 last = n - L * l;
        if (last > (r - l) * L) {
            std::cout << -1 << '\n';
            continue;
        }
        if (l == r) {
            std::cout << SSUM[l][L] * inv(l * l % mod) % mod << '\n';
            continue;
        }
        i64 R = last / (r - l);
        last -= R * (r - l);
        i64 MID = last + (last != 0 ? l : 0);
        L = (n - MID - R * r) / l;
        // std::cout << R << " " << MID << ' ' << L << '\n';
        // std::cout<<R * r + MID<<' ';
        // std::cout<<cal(0, R * r, r) * inv(r * r % mod) % mod<<' ';
        i64 ans = PSUM[r][R] * inv(r * r % mod) % mod
            + (presum[R * r + MID] - presum[R * r]) * (presum[R * r + MID] - presum[R * r]) % mod * inv(MID * MID % mod) % mod
            + SSUM[l][L] * inv(l * l % mod) % mod;
        // std::cout<<R*r<<' '<<R*r+MID<<' '<<n<<'\n';
        // std::cout<<r<<' '<<MID<<' '<<l<<'\n';
        std::cout << (ans % mod + mod) % mod << '\n';
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}