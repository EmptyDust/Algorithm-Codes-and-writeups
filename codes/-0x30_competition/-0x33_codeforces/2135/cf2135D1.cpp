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
    int n = 100'000;
    std::cout << "? " << n << ' ';
    for (int i = 0;i < n;++i)std::cout << 1 << " ";
    std::cout << std::endl;
    int length;std::cin >> length;
    if (length == 1) {
        std::cout << "! 100000" << std::endl;
        return;
    }
    int start, end;
    for (int i = 0;i < positions.size() - 1;++i) {
        if ((100000 - 1) / positions[i] + 1 == length) {
            start = positions[i];
            end = positions[i + 1] - 1;
        }
    }
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
    for (int x : ask)std::cout << x << ' ';
    std::cout << std::endl;
    std::cin >> length;
    int c = length - (end - start);
    // std::cout << end << " " << start << ' ';
    // std::cout << c << ' ';
    std::cout << "! " << end - c << std::endl;
}

signed main() {
    for (int i = 1;i <= 1e5;++i) {
        divi[i] = (100000 - 1) / i + 1;
        if (divi[i] != divi[i - 1]) positions.push_back(i);
    }
    // for (auto x : positions)std::cout << x << ' ';
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}