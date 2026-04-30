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
    int n, m;std::cin >> n >> m;
    std::vector<int> a, b(m);
    int kevin;std::cin >> kevin;
    for (int i = 1;i < n;++i) {
        int x;std::cin >> x;
        if (x > kevin)a.push_back(x);
    }
    n = a.size();
    for (int& x : b)std::cin >> x;
    ranges::sort(a);ranges::sort(b);
    std::vector<int> rank(m);
    for (int i = 0, j = 0;i < m;++i) {
        while (j < n && a[j] < b[i])j++;
        rank[i] = n - j + 1;
        if (b[i] <= kevin) rank[i] = 1;
        // std::cout << rank[i] << ' ';
    }
    std::sort(rank.begin(), rank.end());
    for (int i = 1;i <= m;++i) {
        i64 s = 0;
        for (int j = i - 1;j < m;j += i) {
            s += rank[j];
        }
        std::cout << s << " ";
    }
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