#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN];
using pt = std::pair<int, int>;
int n, m;
bool valid(int x, int y) { return 0 <= x && x < n && 0 <= y && y < m; }

int query(int x, int y) {
    std::cout << '?' << ' ' << x + 1 << ' ' << y + 1 << std::endl;
    int ret;
    std::cin >> ret;
    return ret;
}

void print(int x, int y) {
    std::cout << '!' << ' ' << x + 1 << ' ' << y + 1 << std::endl;
}

void solve() {
    std::cin >> n >> m;
    int a = query(0, 0);
    //y=-x+a
    int b = query(n - 1, 0);
    //y=x-n+1+b
    int c = query(0, m - 1);
    //y=x+m-1+c

    int x1 = (a + n - 1 - b) / 2;
    int y1 = -x1 + a;
    int x2 = (a - m + 1 + c) / 2;
    int y2 = -x2 + a;
    assert(valid(x1, y1) || valid(x2, y2));
    if (valid(x1, y1) && !valid(x2, y2)) {
        print(x1, y1);
        return;
    }
    if (!valid(x1, y1) && valid(x2, y2)) {
        print(x2, y2);
        return;
    }

    int ret = query(x1, y1);
    if (ret == 0)
        print(x1, y1);
    else
        print(x2, y2);
}

signed main() {
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}