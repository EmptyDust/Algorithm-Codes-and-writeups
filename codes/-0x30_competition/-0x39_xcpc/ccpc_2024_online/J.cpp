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

template<class T>
std::vector<T> get_linear_basis(std::vector<T>& nums, int N = 63) {
    std::vector<T> p(N + 1);
    auto insert = [&](T x) {
        for (int s = N;s >= 0;--s)if (x >> s & 1) {
            if (!p[s]) {
                p[s] = x;
                break;
            }
            x ^= p[s];
        }
        };
    for (auto& x : nums) insert(x);
    return p;
}

void solve() {
    int n;std::cin >> n;
    std::vector<int> a(n), b(n), c(n);
    for (int& x : a)std::cin >> x;
    for (int& x : b)std::cin >> x;
    for (int i = 0;i < n;++i)c[i] = a[i] ^ b[i];
    auto p = get_linear_basis(c, 31);
    int suma = 0, sumb = 0;
    for (int x : a)suma ^= x;
    for (int x : b)sumb ^= x;
    int r = 0;
    bool f = 0;
    for (int i = 31;i >= 0;--i) {
        int a = suma >> i & 1;
        int b = sumb >> i & 1;
        int x = r >> i & 1;
        if (a == 0 && b == 0) {
            if (x) {
                r ^= p[i];
            }
        }
        else if (a == 1 && b == 1) {
            if (!x) {
                r ^= p[i];
            }
        }
        else if (a == 1 && b == 0) {
            if (!f) {
                if (x) {
                    std::swap(suma, sumb);
                }
                f = 1;
                continue;
            }
            if (!x)
                r ^= p[i];
        }
        else {
            if (!f) {
                if (!x) {
                    std::swap(suma, sumb);
                }
                f = 1;
                continue;
            }
            if (x)
                r ^= p[i];
        }
    }
    // std::cout << suma << ' ' << sumb << ' ' << r << '\n';
    std::cout << std::max(suma ^ r, sumb ^ r);
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