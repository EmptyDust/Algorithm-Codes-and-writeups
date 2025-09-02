#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<i64, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const i64 inf = (i64)2e18 + 10;
// const int mod = 1e9 + 7;
const int mod = 998244353;

i64 ceilDiv(i64 n, i64 m) {
    if (n >= 0) {
        return (n + m - 1) / m;
    }
    else {
        return n / m;
    }
}

i64 floorDiv(i64 n, i64 m) { // m > 0
    if (n >= 0) {
        return n / m;
    }
    else {
        return (n - m + 1) / m;
    }
}

i64 cal(i64 a, i64 b, i64 y) { // y >= a * x + b
    if (a == 0) return 0;
    if (a > 0) {
        return ceilDiv(y - b, a);
    }
    else {
        return floorDiv(b - y, -a);
    }
}

void solve() {
    int n;std::cin >> n;
    std::vector<a2> red(n);
    std::vector<i64> blue(n);
    for (auto& [a, b] : red)std::cin >> a;
    for (auto& [a, b] : red)std::cin >> b;
    for (auto& x : blue)std::cin >> x;
    ranges::sort(red);
    ranges::sort(blue);
    i64 l = -inf, r = inf;
    auto check = [&](auto x)->bool {
        std::vector<i64> L, R;
        int cnt = 0; // >= x
        for (auto [a, b] : red) {
            i64 p = cal(a, b, x);
            if (a > 0) {
                R.push_back(p);
            }
            else if (a == 0) {
                if (b >= x) cnt++;
            }
            else {
                L.push_back(p);
            }
        }
        ranges::sort(L);
        ranges::sort(R, std::greater<i64>());
        std::vector<int> used(n);
        for (int i = 0, j = 0;i < n;++i) if (!used[i]) {
            while (j < L.size() && blue[i] > L[j])j++;
            if (j < L.size()) {
                used[i] = 1;
                cnt++;
                j++;
            }
        }
        for (int i = n - 1, j = 0;i >= 0;--i) if (!used[i]) {
            while (j < R.size() && blue[i] < R[j])j++;
            if (j < R.size()) {
                used[i] = 1;
                cnt++;
                j++;
            }
        }
        return cnt < (n + 1) / 2;
        };
    while (l < r) {
        auto mid = l + r >> 1;
        if (check(mid))r = mid;
        else l = mid + 1;
    }
    std::cout << l - 1;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    // std::cout << cal(-3, 2, 6);
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}