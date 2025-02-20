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

void solve() {
    int n, A, B;std::cin >> n >> A >> B;
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    if (A > B)std::swap(A, B);
    int a1 = 0, a2 = 0;
    for (int& x : a) {
        if (x <= A)a1++;
        if (x <= B)a2++;
    }
    std::cout << std::min(a1, a2 / 2) * 2;
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