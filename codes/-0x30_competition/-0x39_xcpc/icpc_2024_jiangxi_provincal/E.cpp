#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;

void solve() {
    int n;std::cin >> n;
    std::vector<int> v(n);
    for (int& x : v)std::cin >> x;
    n = std::min(30, n);
    int m = n / 2;
    std::vector<a3> p{ { 0,0,0 } }, q(p);
    for (int i = 0;i < m;++i) {
        int s = p.size();
        p.resize(s * 3);
        for (int j = 0;j < s;++j) {
            auto [value, l, r] = p[j];
            p[s + j] = { value + v[i],l | 1 << i,r };
            p[s * 2 + j] = { value - v[i] ,l,r | 1 << i };
        }
        std::inplace_merge(p.begin(), p.begin() + s, p.begin() + 2 * s);
        std::inplace_merge(p.begin(), p.begin() + 2 * s, p.end());
    }
    for (int i = m;i < n;++i) {
        int s = q.size();
        q.resize(s * 3);
        for (int j = 0;j < s;++j) {
            auto [value, l, r] = q[j];
            q[s + j] = { value + v[i],l | 1 << i,r };
            q[s * 2 + j] = { value - v[i] ,l,r | 1 << i };
        }
        std::inplace_merge(q.begin(), q.begin() + s, q.begin() + 2 * s);
        std::inplace_merge(q.begin(), q.begin() + 2 * s, q.end());
    }
    int S1 = -1, S2 = -1;
    for (int i = 0;i < p.size();++i) {
        if (p[i][0] == 0 && (p[i][1] | p[i][2])) {
            S1 = p[i][1];
            S2 = p[i][2];
        }
    }
    for (int i = 0;i < q.size();++i) {
        if (q[i][0] == 0 && (q[i][1] | q[i][2])) {
            S1 = q[i][1];
            S2 = q[i][2];
        }
    }
    for (int i = p.size() - 1, j = 0;i >= 0;--i) {
        if (!p[i][0])continue;
        while (j < q.size() && q[j][0] < -p[i][0])j++;
        if (j < q.size() && q[j][0] + p[i][0] == 0) {
            S1 = p[i][1] | q[j][1];
            S2 = p[i][2] | q[j][2];
        }
    }
    if (S1 == -1) {
        std::cout << -1;
        return;
    }
    std::vector<int> ans1, ans2;
    for (int i = 0;i < 30;++i)if (S1 >> i & 1) {
        ans1.push_back(i + 1);
    }
    for (int i = 0;i < 30;++i)if (S2 >> i & 1) {
        ans2.push_back(i + 1);
    }
    std::cout << ans1.size() << ' ';
    for (int x : ans1)std::cout << x << ' ';std::cout << '\n';
    std::cout << ans2.size() << ' ';
    for (int x : ans2)std::cout << x << ' ';
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