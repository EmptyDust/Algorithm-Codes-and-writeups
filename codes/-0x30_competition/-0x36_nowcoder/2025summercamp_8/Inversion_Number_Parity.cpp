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

void solve() {
    int n, A, B, C;std::cin >> n >> A >> B >> C;
    int U = (1 << 30) - 1;
    A = A & U;
    B = B & U;
    C = C & U;
    int f = 0;
    auto work = [&]() {
        int G = A ^ ((A << 16) & U);
        int H = G ^ (G >> 5);
        int F = H ^ ((H << 1) & U) ^ B ^ C;
        // std::cout << std::bitset<30>(G) << "\n";
        // std::cout << std::bitset<30>(H) << "\n";
        // std::cout << F << "\n";
        // std::cout << '\n';
        A = B;
        B = C;
        C = F;
        };
    for (int i = 0;i < n;++i) {
        work();
        int move = C % (n - i);
        if (move) f = !f;
        // std::cout << move << ' ';
    }
    std::cout << f;
    for (int i = 1;i < n;++i) {
        work();
        work();
        work();

        int l = A % n;
        int r = B % n;
        if (r < l)std::swap(l, r);
        int d = C % n + 1;
        if ((r - l + 1) % 2 == 0 && d % 2) {
            f = !f;
        }
        std::cout << f;
    }
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