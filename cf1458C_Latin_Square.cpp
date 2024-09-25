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

struct Point
{
    int x, y, z;
    Point(int x, int y, int z) :x(x), y(y), z(z) {}
    Point operator+(const Point& p) {
        return Point(x + p.x, y + p.y, z + p.z);
    }
    Point operator-(const Point& p) {
        return Point(x - p.x, y - p.y, z - p.z);
    }
    Point remake(int n, const Point& vx, const Point& vy, const Point& vz) {
        x = (x % n + n) % n;
        y = (y % n + n) % n;
        z = (z % n + n) % n;
        int nx, ny, nz;
        if (vx.x)nx = x;
        else if (vx.y)nx = y;
        else nx = z;
        if (vy.x)ny = x;
        else if (vy.y)ny = y;
        else ny = z;
        if (vz.x)nz = x;
        else if (vz.y)nz = y;
        else nz = z;
        return Point(nx, ny, nz);
    }
    void display() {
        std::cout << x << ' ' << y << ' ' << z << "\n";
    }
};

void solve() {
    int n, m;std::cin >> n >> m;
    std::vector<Point> ps;ps.reserve(n * n);
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < n;++j) {
            int x;std::cin >> x;x--;
            ps.push_back(Point(i, j, x));
        }
    }
    Point vx(1, 0, 0), vy(0, 1, 0), vz(0, 0, 1);
    Point v0(0, 0, 0);
    std::string s;std::cin >> s;
    for (char ch : s) {
        switch (ch)
        {
        case 'R':
            v0 = v0 + vy;
            break;
        case 'L':
            v0 = v0 - vy;
            break;
        case 'D':
            v0 = v0 + vx;
            break;
        case 'U':
            v0 = v0 - vx;
            break;
        case 'I':
            std::swap(vy, vz);
            break;
        case 'C':
            std::swap(vx, vz);
            break;
        }
    }
    std::vector b(n, std::vector<int>(n));
    for (auto& p : ps) {
        p = (p + v0).remake(n, vx, vy, vz);
        b[p.x][p.y] = p.z;
    }
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < n;++j) {
            std::cout << b[i][j] + 1 << ' ';
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