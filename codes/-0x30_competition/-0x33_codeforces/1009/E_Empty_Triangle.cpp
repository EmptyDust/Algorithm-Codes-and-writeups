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

int ask(std::vector<int> vt) {
    std::cout << "? " << vt[0] << ' ' << vt[1] << ' ' << vt[2] << std::endl;
    int x;std::cin >> x;
    return x;
}

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
//1/4
//1/2
void solve() {
    int n;std::cin >> n;
    std::vector<int> tag(n + 1, 0);tag[0] = 1;
    std::vector<int> vt(3, 0);
    for (auto& x : vt) {
        while (tag[x]) {
            x = rng() % n + 1;
        }
        tag[x] = 1;
    }
    int y = ask(vt);
    while (y) {
        int t = rng() % 3;
        vt[t] = y;
        y = ask(vt);
    }
    std::cout << "! " << vt[0] << ' ' << vt[1] << ' ' << vt[2] << std::endl;
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