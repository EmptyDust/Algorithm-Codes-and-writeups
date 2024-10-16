#include <bits/stdc++.h>

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
    int n, k;std::cin >> n >> k;
    k *= 2;
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    std::vector<int> mod(k);
    for (int x : a)mod[x % k]++;
    for (int i = 1;i < k;++i)
        mod[i] += mod[i - 1];
    int max = *std::max_element(a.begin(), a.end());
    for (int i = 0;i < k / 2;++i) {
        int nx = (max + i) % k;
        int ny = nx - k / 2;
        if (ny >= 0) {
            if (mod[nx] - mod[ny] == n) {
                std::cout << max + i;
                return;
            }
        }
        else {
            ny += k;
            if (mod[nx] + (mod[k - 1] - mod[ny]) == n) {
                // std::cout << nx << ' ' << k - 1 << ' ' << ny << '\n';
                std::cout << max + i;
                return;
            }
        }
    }
    std::cout << -1;
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