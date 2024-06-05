#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define int long long
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e18;
using pt = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    std::cin.tie(0), cout.tie(0);
    int n, b;cin >> n >> b;
    vector<pt> pts(n);
    for (auto& [p, s] : pts)cin >> p >> s;
    sort(pts.begin(), pts.end(), [&](pt a, pt b) {
        return a.first + a.second < b.first + b.second;
        });
    int mx = 0;
    bool f = false;
    int ans = 0;
    for (int i = 0;i < n;++i) {
        auto [p, s] = pts[i];
        int d = p + s;
        mx = max(mx, p);
        if (d > b) {
            if (f)break;
            f = true;
            b += mx / 2;
            if (d > b)break;
        }
        b -= d;
        ans++;
    }
    std::cout << ans;
    return 0;
}