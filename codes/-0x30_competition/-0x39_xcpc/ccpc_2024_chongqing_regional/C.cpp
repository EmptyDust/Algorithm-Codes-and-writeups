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
    int n;std::cin >> n;
    std::vector map(7, std::string(n, '.'));
    std::cin >> map[0] >> map[6];
    if (ranges::count(map[0], '#') == n || ranges::count(map[6], '#') == n) {
        if (ranges::count(map[0], '#') == n && ranges::count(map[6], '#') == n) {
            std::cout << "Yes\n";
            for (int i = 0;i < 7;++i)std::cout << map[0] << '\n';
        }
        else {
            std::cout << "No\n";
        }
        return;
    }

    int pos1 = -1, pos2 = -1;
    for (int i = 0;i < n;++i) {
        if (map[0][i] != '#') {
            map[1][i] = '#';
        }
    }
    bool f = 1;
    for (int i = 1;i < n && f;++i) {
        if (map[1][i] == '#' && map[1][i - 1] != '#') {
            pos1 = i - 1;
            f = 0;
        }
    }
    for (int i = n - 2;i >= 0 && f;--i) {
        if (map[1][i] == '#' && map[1][i + 1] != '#') {
            pos1 = i + 1;
            f = 0;
        }
    }
    // std::cout << pos1 << ' ';
    map[2][pos1] = '#';

    for (int i = 0;i < n;++i) {
        if (map[6][i] != '#') {
            map[5][i] = '#';
        }
    }
    f = 1;
    for (int i = 1;i < n && f;++i) {
        if (map[5][i] == '#' && map[5][i - 1] != '#') {
            pos2 = i - 1;
            f = 0;
        }
    }
    for (int i = n - 2;i >= 0 && f;--i) {
        if (map[5][i] == '#' && map[5][i + 1] != '#') {
            pos2 = i + 1;
            f = 0;
        }
    }
    map[4][pos2] = '#';

    if (std::abs(pos1 - pos2) <= 1) {
        map[3][pos1] = '#';
    }
    else {
        for (int i = 0;i < n;++i) {
            if (map[2][i] != '#' && map[4][i] != '#') {
                map[3][i] = '#';
            }
        }
    }
    std::cout << "Yes\n";
    for (auto& str : map)std::cout << str << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}