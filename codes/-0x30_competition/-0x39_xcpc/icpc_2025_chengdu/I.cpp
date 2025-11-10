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
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n;std::cin >> n;
    std::vector<a2> outside(n);
    for (auto& [a, b] : outside) std::cin >> a >> b;
    int m;std::cin >> m;
    std::vector<a2> inside(m);
    for (auto& [a, b] : inside) std::cin >> a >> b;
    outside.insert(outside.end(), outside.begin(), outside.end());
    outside.insert(outside.end(), outside.begin(), outside.end());
    inside.insert(inside.end(), inside.begin(), inside.end());
    inside.insert(inside.end(), inside.begin(), inside.end());
    auto add = [&](a2 a, a2 b) {
        return a2{ a[0] + b[0], a[1] + b[1] };
        };
    auto sub = [&](a2 a, a2 b) {
        return a2{ a[0] - b[0], a[1] - b[1] };
        };
#define dir(x, y) sub(y, x)
    auto dot = [&](a2 a, a2 b) {
        return a[0] * b[0] + a[1] * b[1];
        };
    auto cross = [&](a2 a, a2 b) {
        return a[0] * b[1] - a[1] * b[0];
        };
    // assert(0);
    std::vector<int> p(4 * n), r(4 * n, -1), l(4 * n, -1);
    for (int i = 0, j = 0, k = 1;i < 2 * n;++i) {
        while (cross(dir(outside[i], inside[j]), dir(outside[i], inside[j + 1])) <= 0) j++;
        p[i] = j;
        while (cross(dir(outside[i], outside[k + 1]), dir(outside[i], inside[p[i]])) >= 0) {
            k++;
            l[k] = i;
        }
        r[i] = k;
    }
    i64 sum = 0, cur = 0, ad = 0;
    std::vector<i64> d(4 * n);
    for (int i = 0, L = 0, R = 0;i < 2 * n;++i) {
        while (L < l[i]) {
            if (l[L] != -1) {
                if (R - n - l[L] > 0) {
                    ad--;
                    cur -= R - n - l[L];
                }
                d[l[L] % n]--;
            }
            L++;
        }
        while (R <= r[i]) {
            ad += d[R % n];
            cur += ad;
            R++;
        }
        if (i >= n) sum += cur;
        if (l[i] != -1) d[l[i] % n]++;
    }
    std::cout << sum / 3;
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