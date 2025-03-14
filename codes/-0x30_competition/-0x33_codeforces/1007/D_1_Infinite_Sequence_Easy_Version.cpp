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

i64 query(std::vector<i64>& a, std::vector<i64>& p, i64 l, i64 r) {

}

void solve() {
    i64 n, l, r;std::cin >> n >> l >> r;
    std::vector<i64> a(n + 1), p(n + 1);
    for (int i = 1;i <= n;++i) {
        std::cin >> a[i];
        p[i] = p[i - 1] ^ a[i];
    }

    std::map<i64, i64> mem;
    auto query = [&](auto&& self, i64 l, i64 r) ->i64 {
        if (l > r)return 0;
        // std::cout << l << ' ' << r << '\n';
        i64 msk = 0;
        if (l == r) {
            if (mem.contains(l))return mem[l];
            msk = l <= n ? a[l] : self(self, 1, l / 2);
            return mem[l] = msk;
        }
        if (l <= n) {
            if (r <= n) {
                return p[r] ^ p[l - 1];
            }
            msk = p[n] ^ p[l - 1];
            l = n + 1;
        }
        if (l % 2 == 1) {
            msk ^= self(self, l, l);
        }
        if (r % 2 == 0) {
            msk ^= self(self, r, r);
        }
        return msk;
        };

    std::cout << query(query, l, r);


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