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

int cal(std::string& s) {
    int n = s.length();
    int res = 0;
    for (int i = 0;i < n;++i) {
        res <<= 1;
        if (s[i] == '1')res++;
    }
    return res;
}

void solve() {
    int n, m, q;std::cin >> n >> m >> q;
    std::vector<int> w(n);
    for (int& x : w)std::cin >> x;
    std::vector<int> wei(1 << n);
    for (int i = 1;i < 1 << n;++i) {
        wei[i] = wei[i - (i & -i)] + w[n - 1 - std::__lg(i & -i)];
    }
    // std::cout << std::__lg(4) << ' ';
    std::vector<int> c(1 << n);
    for (int i = 0;i < m;++i) {
        std::string s;std::cin >> s;
        c[cal(s)]++;
        // std::cout << cal(s) << ' ' << c[cal(s)] << '\n';
    }
    std::vector<std::vector<int>> ans(101, std::vector<int>(1 << n));
    int tot = (1 << n) - 1;
    for (int i = 0;i < 1 << n;++i) {
        for (int j = 0;j < 1 << n;++j) {
            if (wei[tot - (i ^ j)] <= 100) {
                ans[wei[tot - (i ^ j)]][i] += c[j];
                // if (i == 0 && c[j]) {
                //     std::cout << j << ' ' << c[j] << ' ' << wei[tot - (i ^ j)] << '\n';
                // }
            }
        }
        for (int j = 1;j <= 100;++j) {
            ans[j][i] += ans[j - 1][i];
        }
    }
    for (int i = 0;i < q;++i) {
        std::string s;int k;
        std::cin >> s >> k;
        std::cout << ans[k][cal(s)] << '\n';
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}