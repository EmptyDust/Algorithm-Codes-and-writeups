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

bool solve() {
    int n;std::cin >> n;
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    i64 sum = std::accumulate(a.begin(), a.end(), 0ll);
    i64 m = sum / n;
    i64 sume = 0, cnte = 0;
    i64 sumo = 0, cnto = 0;
    for (int i = 0;i < n;++i) {
        if (i & 1) {
            sume += a[i];
            cnte += 1;
        }
        else {
            sumo += a[i];
            cnto += 1;
        }
    }
    return m * n == sum && m * cnto == sumo && m * cnte == sume;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        std::cout << (solve() ? "YES" : "NO");
        std::cout << '\n';
    }
    return 0;
}