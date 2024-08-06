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

int sg[101][101][101];

bool get(int a, int b, int c) {
    for (int x = 1;x < a;++x) {
        int y = a - x;
        if (y <= 0)break;
        if (!sg[x][y][c])return true;
        if (!sg[x][b][y])return true;
    }
    for (int x = 1;x < b;++x) {
        int y = b - x;
        if (y <= 0)break;
        // if (a == 1 && b == 2 && c == 1)
            // std::cout << x << " " << y << " " << c << "\n";
        if (!sg[x][y][c])return true;
        if (!sg[a][x][y])return true;
    }
    // std::cout << "a" << '\n';
    for (int x = 1;x < c;++x) {
        int y = c - x;
        if (y <= 0)break;
        if (!sg[a][x][y])return true;
        if (!sg[x][b][y])return true;
    }
    return false;
}

void solve() {
    for (int i = 1;i < 100;++i)for (int j = 1;j < 100;++j)for (int k = 1;k < 100;++k)
        if (!sg[i][j][k] && i % 2 == 0)
            std::cout << i << ' ' << j << ' ' << k << '\n';
    // int x, y, z;std::cin >> x >> y >> z;
    // std::cout << (get(x, y, z) ? "YES" : "NO");
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    sg[0][0][0] = 0;
    int n = 100;
    for (int sum = 1;sum <= 300;++sum) {
        for (int a = 1;a <= 100;++a) {
            if (a > sum)break;
            for (int b = 1;b <= 100;++b) {
                int c = sum - a - b;
                if (c <= 0 || c > 100)continue;
                sg[a][b][c] = get(a, b, c);
            }
        }
    }
    int t = 1;;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}