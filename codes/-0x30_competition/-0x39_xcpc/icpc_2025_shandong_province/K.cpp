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
    int n, m;std::cin >> n >> m;
    std::vector a(n, std::vector<int>(m)), vis(n, std::vector<int>(m));
    auto vaild = [&](int x, int y) {return 0 <= x && x < n && 0 <= y && y < m;};
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < m;++j) {
            std::cin >> a[i][j];
        }
    }
    std::map<int, int> lastpos;
    std::set<int> notans;
    std::vector down(n, std::vector<int>(m));
    for (int j = 0;j < m;++j) lastpos[a[n - 1][j]] = j, down[n - 1][j] = 1;
    for (int i = n - 2;i >= 0;--i) {
        std::map<int, int> nlp;
        for (int j = 0;j < m;++j) {
            if (vaild(i, j - 1) && a[i][j - 1] == a[i][j] && down[i][j - 1] == 1) down[i][j] = 1;
            if (lastpos.count(a[i][j]) && lastpos[a[i][j]] >= j - 1) down[i][j] = 1;
            if (j == 0) down[i][j] = 1;
            if (down[i][j]) nlp[a[i][j]] = j;
        }
        lastpos = nlp;
    }
    // for (auto [a, _] : lastpos) notans.insert(a);
    lastpos.clear();
    std::vector right(n, std::vector<int>(m));
    for (int i = 0;i < n;++i) lastpos[a[i][m - 1]] = i, right[i][m - 1] = 1;
    for (int j = m - 2;j >= 0;--j) {
        std::map<int, int> nlp;
        for (int i = 0;i < n;++i) {
            if (vaild(i - 1, j) && a[i - 1][j] == a[i][j] && down[i - 1][j] == 1) right[i][j] = 1;
            if (lastpos.count(a[i][j]) && lastpos[a[i][j]] >= i - 1) right[i][j] = 1;
            // if (i == 6 && j == 2) std::cout << lastpos[a[i][j]] << ' ' << right[i][j] << '\n';
            if (i == 0) right[i][j] = 1;
            if (right[i][j]) nlp[a[i][j]] = i;
        }
        lastpos = nlp;
    }
    // for (auto [a, _] : lastpos) notans.insert(a);
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < m;++j) {
            // if (a[i][j] == 7)std::cout << right[i][j] << ' ' << down[i][j] << ' ' << a[i][j] << ' ' << i << ' ' << j << '\n';
            // if (i == 5 && j == 4)std::cout << right[i][j] << ' ' << down[i][j] << ' ' << a[i][j] << '\n';
            if (right[i][j] && down[i][j]) {
                notans.insert(a[i][j]);
            }
        }
    }
    for (int i = 0;i <= n * m;++i) if (!notans.contains(i)) {
        std::cout << i;
        return;
    }
    assert(0);
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