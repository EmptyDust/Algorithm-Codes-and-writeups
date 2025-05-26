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
    int op = std::min(n, m) % 2;
    std::vector ans(n, std::vector<int>(m, -1));
    a2 dir[4] = { {0,-1},{0,1},{1,0},{-1,0} };
    auto check = [&](int x, int y) {return 0 <= x && x < n && 0 <= y && y < m;};
    auto get = [&](int x, int y) {
        std::vector<int> a(26);
        for (int i = 0;i < 4;++i) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (!check(nx, ny))continue;
            if (ans[nx][ny] == -1)continue;
            a[ans[nx][ny]] = 1;
        }
        int mex = 0;
        while (a[mex])mex++;
        return mex;
        };
    auto can = [&](int x, int y, int p) {
        for (int i = 0;i < 4;++i) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (!check(nx, ny))continue;
            if (ans[nx][ny] == -1)continue;
            if (p == ans[nx][ny])return false;
        }
        return true;
        };
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < m;++j) {
            if (ans[i][j] != -1) continue;
            int r = n - i;
            int d = m - j;
            int len = std::min(r, d);
            int cur = get(i, j);
            for (int k = 0;k < len;++k) {
                if (ans[i][j + k] == -1 && get(i, j + k) == cur && can(i + k, j, cur)) {

                }
                else {
                    len = k;
                    break;
                }
            }
            for (int x = i;x < i + len;++x) {
                for (int y = j;y < j + len;++y) {
                    ans[x][y] = cur;
                }
            }
        }
    }
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < m;++j) {
            std::cout << (char)(ans[i][j] + 'A');
        }
        std::cout << '\n';
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

/*

AAAAAAAAAAAAAAAAAAAAAAAAAAABAAAAAAAAAAAAAAAA
AAAAAAAAAAAAAAAAAAAAAAAAAAACAAAAAAAAAAAAAAAA
AAAAAAAAAAAAAAAAAAAAAAAAAAABAAAAAAAAAAAAAAAA
AAAAAAAAAAAAAAAAAAAAAAAAAAACAAAAAAAAAAAAAAAA
AAAAAAAAAAAAAAAAAAAAAAAAAAABAAAAAAAAAAAAAAAA
AAAAAAAAAAAAAAAAAAAAAAAAAAACAAAAAAAAAAAAAAAA
AAAAAAAAAAAAAAAAAAAAAAAAAAABAAAAAAAAAAAAAAAA
AAAAAAAAAAAAAAAAAAAAAAAAAAACAAAAAAAAAAAAAAAA
AAAAAAAAAAAAAAAAAAAAAAAAAAABAAAAAAAAAAAAAAAA
AAAAAAAAAAAAAAAAAAAAAAAAAAACAAAAAAAAAAAAAAAA
AAAAAAAAAAAAAAAAAAAAAAAAAAABAAAAAAAAAAAAAAAA
AAAAAAAAAAAAAAAAAAAAAAAAAAACAAAAAAAAAAAAAAAA
AAAAAAAAAAAAAAAAAAAAAAAAAAABAAAAAAAAAAAAAAAA
AAAAAAAAAAAAAAAAAAAAAAAAAAACAAAAAAAAAAAAAAAA
AAAAAAAAAAAAAAAAAAAAAAAAAAABAAAAAAAAAAAAAAAA
AAAAAAAAAAAAAAAAAAAAAAAAAAACAAAAAAAAAAAAAAAA
AAAAAAAAAAAAAAAAAAAAAAAAAAABBBBBBBBBBBCBBBBB
AAAAAAAAAAAAAAAAAAAAAAAAAAABBBBBBBBBBBABBBBB
AAAAAAAAAAAAAAAAAAAAAAAAAAABBBBBBBBBBBCBBBBB
AAAAAAAAAAAAAAAAAAAAAAAAAAABBBBBBBBBBBABBBBB
AAAAAAAAAAAAAAAAAAAAAAAAAAABBBBBBBBBBBCBBBBB
AAAAAAAAAAAAAAAAAAAAAAAAAAABBBBBBBBBBBAAAAAA
AAAAAAAAAAAAAAAAAAAAAAAAAAABBBBBBBBBBBAAAAAA
AAAAAAAAAAAAAAAAAAAAAAAAAAABBBBBBBBBBBAAAAAA
AAAAAAAAAAAAAAAAAAAAAAAAAAABBBBBBBBBBBAAAAAA
AAAAAAAAAAAAAAAAAAAAAAAAAAABBBBBBBBBBBAAAAAA
AAAAAAAAAAAAAAAAAAAAAAAAAAABBBBBBBBBBBAAAAAA

*/