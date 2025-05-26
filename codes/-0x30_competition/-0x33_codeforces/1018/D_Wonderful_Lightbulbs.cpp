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
    std::vector<a2> a(n);
    std::set<a2> st;
    for (auto& [x, y] : a)std::cin >> x >> y, st.insert({ x,y });
    ranges::sort(a, [&](a2 x, a2 y) {
        if (x[0] + x[1] == y[0] + y[1])return x[1] < y[1];
        return x[0] + x[1] < y[0] + y[1];
        });
    std::map<int, int> mp1, mp2;
    for (auto [x, y] : a) {
        if (mp2[x]) mp1[x + y]--;
        else mp1[x + y]++;
        mp2[x] = !mp2[x];
    }
    int ansx;
    for (auto [x, f] : mp2)if (f) {
        std::cout << x << ' ';
        ansx = x;
        break;
    }
    // std::vector<int> p;
    int cnt = 0;
    for (auto [y, f] : mp1) {
        cnt += f;
        // std::cout << y - ansx << ' ' << cnt << '\n';
        if (cnt % 2 != 0) {
            // p.push_back(y - ansx);
            std::cout << y - ansx;
            break;
        }
        // break;
    }
    // cnt = 0;
    // for (auto [x, y] : a)if (x == ansx && y < p[0])cnt ^= 1;
    // if (cnt)std::cout << p[1];
    // else std::cout << p[0];
    // if (p.size() == 1)std::cout << p[0];
    // else if (st.count({ ansx,p[0] })) {
    //     std::cout << p[1];
    // }
    // else std::cout << p[0];
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