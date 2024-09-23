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

int vis[501][5001], link[501][5001], size[501][5001];
int d;
void dfs(int yu, int s) {
    if (vis[yu][s])return;
    // std::cout << yu << ' ' << s << "\n";
    if (yu == 0 && s == 0)
        return;
    vis[yu][s] = 1;
    int lim = std::min(s, 9);
    for (int i = lim;i >= 0;--i) {
        int nyu = (yu * 10 + i) % d;
        int ns = s - i;
        dfs(nyu, ns);
        // if (yu == 5 && s == 17)std::cout << nyu << ' ' << nyu << ' ' << vis[nyu][ns] << '\n';
        if (~link[nyu][ns] || ns == 0 && nyu == 0) {
            int sz = size[nyu][ns] + 1;
            if (size[yu][s] == 0 || sz <= size[yu][s]) {
                link[yu][s] = i;
                size[yu][s] = sz;
            }
        }
    }
}

void solve() {
    int s;
    std::cin >> d >> s;
    dfs(0, s);
    // std::cout << link[5][17] << " ";
    // std::cout << 59 % 13 << '\n';
    auto u = link[0][s];
    if (~u) {
        int nowyu = 0, nows = s;
        while (nowyu || nows) {
            std::cout << u;
            nowyu = (nowyu * 10 + u) % d;
            nows -= u;
            u = link[nowyu][nows];
        }
    }
    else std::cout << -1;
}

signed main() {
    memset(link, -1, sizeof link);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}