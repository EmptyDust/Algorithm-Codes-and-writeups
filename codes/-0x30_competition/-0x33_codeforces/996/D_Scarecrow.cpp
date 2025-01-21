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
const double eps = 1e-6;

void solve() {
    int n, k, L;std::cin >> n >> k >> L;
    k *= 2, L *= 2;
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x, x *= 2;
    // a.push_back(3e8);n++;
    // std::priority_queue<a3, std::vector<a3>, std::greater<a3>> pq;// time pos pos_a
    int time = a[0];
    int pos = k;
    for (int i = 1;i < n;++i) {
        int l = a[i] - time, r = a[i] + time;
        if (pos < l) {
            time += (l - pos) / 2;
            pos = (l + pos) / 2 + k;
        }
        else if (pos < r) {
            pos += k;
        }
        else {
            pos = std::max(pos, r + k);
        }
        // std::cout << time << ' ';
        if (pos >= L)break;
    }
    if (pos < L)
        time += L - pos;
    std::cout << time;
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