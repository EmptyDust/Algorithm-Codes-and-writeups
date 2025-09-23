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

std::vector<int> positions, divi(100001);

void solve() {
    const int N = 11343, B = 116;
    std::cout << "? " << N << ' ';
    for (int i = 0;i < N;++i)std::cout << B << " ";
    std::cout << std::endl;
    int r;std::cin >> r;

    int start, end;

    if (r == 0) {
        std::cout << "? " << B * B << ' ';
        for (int i = 0;i < B * B;++i) std::cout << 1 << ' ';
        std::cout << std::endl;
        std::cin >> r;
        start = (B * B - 1) / r + 1, end = (B * B - 1) / (r - 1);
        // std::cout << start << ' ' << end << '\n';
        assert(start == end);
    }
    else start = ((N - 1) / r + 1) * B, end = std::min(((N - 1) / (r - 1) + 1) * B - 1, 100000);
    // std::cout << start << ' ' << end << '\n';

    if (start == end) {
        std::cout << "! " << start << std::endl;
        return;
    }

    std::vector<int> ask;
    for (int i = end;i > start;--i) {
        ask.push_back(start);
        ask.push_back(i - start);
    }
    std::cout << "? " << ask.size() << ' ';
    for (int x : ask) std::cout << x << ' ';
    std::cout << std::endl;
    std::cin >> r;
    int c = r - (end - start);
    std::cout << "! " << end - c << std::endl;
}

signed main() {
    // int start, end;
    // for (int i = 1;i <= 100;++i) {
    //     start = 100000 / i / 2 * i + 1, end = 100000 / i / (2 - 1) * i;
    //     std::cout << start << ' ' << end << ' ' << end - start + 1 << '\n';
    //     // divi[i] = (10000 - 1) / i + 1;
    //     // if (divi[i] != divi[i - 1]) positions.push_back(i);
    // }
    // for (auto x : positions)std::cout << x << ' ';
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}