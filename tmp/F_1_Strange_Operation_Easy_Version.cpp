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
    std::vector<int> a(n), b(n, 1), pos(n);
    for (auto& x : a)std::cin >> x, x--;
    for (int i = 0;i < n;++i) pos[a[i]] = i;
    auto work = [&](int x) {
        int pos1 = pos[x];
        int pos2 = pos[x - 1];
        int pos3 = pos[x - 2];
        pos[x] = pos2;
        pos[x - 1] = pos3;
        pos[x - 2] = pos1;
        a[pos1] = x - 2;
        a[pos2] = x;
        a[pos3] = x - 1;
        for (auto x : a)std::cout << x << ' ';std::cout << '\n';
        };
    // bool f = true;
    // while (f) {
    //     f = false;
    for (int j = n - 1;j >= 0;--j) {
        while (a[j] < n - 2 && pos[a[j] + 2] < pos[a[j] + 1] && pos[a[j] + 1] < j ||
            0 < a[j] && a[j] < n - 1 && pos[a[j] + 1] < pos[a[j] - 1] && pos[a[j] - 1] < j) {
            // if (j == n - 1)std::cout << a[j] << ' ';
            if (a[j] < n - 2 && pos[a[j] + 2] < pos[a[j] + 1] && pos[a[j] + 1] < j) work(a[j] + 2);
            else work(a[j] + 1);
            break;
        }
    }
    // }
    // for (int i = 0;i < n;++i) {
    //     while (a[i] >= 2 && b[a[i]] && b[a[i] - 1] && b[a[i] - 2]) {
    //         work(a[i]);
    //     }
    //     // if (a[i] % 2 != i % 2) {
    //     //     if (0 < a[i] && a[i] + 2 < n && b[a[i] + 1] && b[a[i] + 2] && b[a[i]] && b[a[i] - 1]) {
    //     //         work(a[i] + 2);
    //     //         work(a[i]);
    //     //     }
    //     // }
    //     b[a[i]] = 0;
    // }
    for (auto x : a)std::cout << x + 1 << " ";
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


