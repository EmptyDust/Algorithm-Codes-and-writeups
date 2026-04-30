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

struct P {
    i64 a;
    i64 b;
    P operator-(P x) {
        return P(a - x.a, b - x.b);
    }
    P operator+(P x) {
        return P(a + x.a, b + x.b);
    }
};

void solve() {
    int n, m;std::cin >> n >> m;
    std::string s;std::cin >> s;
    std::vector map(n, std::vector<P>(m));
    for (int i = 0;i < n;++i)for (int j = 0;j < m;++j) {
        std::cin >> map[i][j].a;
        map[i][j].b = 0;
    }
    std::vector<pii> pos;
    int curx = 0, cury = 0;
    for (char ch : s) {
        if (ch == 'R')cury++;
        else curx++;
        map[curx][cury] = P(0, -inf);
        pos.push_back({ curx, cury });
    }
    auto [tx, ty] = pos.back();
    auto cal = [&](int x, int y) {
        bool ok = true;
        P sum = P(0, 0);
        for (int i = 0;i < m;++i) if (i != y) {
            if (map[x][i].b == -inf) {
                ok = false;
                break;
            }
            sum = sum + map[x][i];
        }
        // if (x == 0 && y == 1)std::cout << sum.a << ' ' << sum.b << '\n';
        if (ok)return sum;
        sum = P(0, 0);
        for (int i = 0;i < n;++i) if (i != x) {
            assert(map[i][y].b != -inf);
            sum = sum + map[i][y];
        }
        return sum;
        };
    map[0][0] = P(0, 1);
    P X = cal(0, 0) + map[0][0];
    // std::cout << X.a << ' ' << X.b << '\n';
    for (auto [x, y] : pos) {
        // std::cout << x << ' ' << y << ' ' << cal(x, y).a << ' ' << cal(x, y).b << '\n';
        map[x][y] = X - cal(x, y);
        // std::cout << x << ' ' << y << ' ' << map[x][y].a << ' ' << map[x][y].b << '\n';
    }
    P sum = P(0, 0);
    for (int i = 0;i < m;++i) {
        sum = sum + map[tx][i];
    }
    for (int i = 0;i < n;++i) {
        sum = sum - map[i][ty];
    }
    // std::cout << sum.a << ' ' << sum.b << '\n';
    i64 x0 = (sum.b ? sum.a / (-sum.b) : 0);
    std::vector ans(n, std::vector<i64>(m));
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < m;++j) {
            ans[i][j] = map[i][j].a + map[i][j].b * x0;
            std::cout << ans[i][j] << " ";
        }
        std::cout << '\n';
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}