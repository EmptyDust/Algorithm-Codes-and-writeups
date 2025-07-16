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
    int n, m, v;std::cin >> n >> m >> v;
    std::vector<a3> p(n);
    for (auto& [type, x, y] : p) {
        std::cin >> type >> x;
        if (!type)std::cin >> y;
    }
    std::deque<int> admin_c(m), ss_c(m);
    std::vector<a3> admin_h, ss_h;
    int admin_b = v, ss_b = v;
    for (auto& x : admin_c)std::cin >> x, x--;
    for (auto& x : ss_c)std::cin >> x, x--;
    // for (auto x : admin_c)std::cout << x << " ";
    auto action = [&](std::vector<a3>& vt, std::deque<int>& c, int& blood, int x) {
        if (vt.empty()) {
            blood -= x;
            return;
        }
        std::vector<a3> nvt;
        for (auto& [id, h, _] : vt) {
            h -= x;
            if (h > 0)nvt.push_back({ id,h,_ });
            else c.push_back(id);
        }
        vt = nvt;
        };
    int k;std::cin >> k;
    bool now = 1;
    while (k--) {
        int op;std::cin >> op;
        if (now == 1) {
            if (op == 2) {
                auto id = admin_c.front();
                auto [op, x, y] = p[id];
                admin_c.pop_front();
                if (op == 1) {
                    action(ss_h, ss_c, ss_b, x);
                    admin_c.push_back(id);
                }
                else {
                    admin_h.push_back({ id, x, y });
                }
            }
            else {
                int x;std::cin >> x;
                action(ss_h, ss_c, ss_b, x);
            }
            for (auto [_, __, att] : admin_h) {
                bool f = 0;
                for (auto& [_, heal, __] : ss_h) {
                    if (heal > 0) {
                        f = 1;
                        heal -= att;
                        break;
                    }
                }
                if (!f) ss_b -= att;
            }
            action(ss_h, ss_c, ss_b, 0);
            if (ss_b <= 0) {
                std::cout << "Administrator";
                return;
            }
        }
        else {
            if (op == 2) {
                auto id = ss_c.front();
                auto [op, x, y] = p[id];
                ss_c.pop_front();
                if (op == 1) {
                    action(admin_h, admin_c, admin_b, x);
                    ss_c.push_back(id);
                }
                else {
                    ss_h.push_back({ id, x, y });
                }
            }
            else {
                int x;std::cin >> x;
                action(admin_h, admin_c, admin_b, x);
            }
            for (auto [_, __, att] : ss_h) {
                bool f = 0;
                for (auto& [_, heal, __] : admin_h) {
                    if (heal > 0) {
                        f = 1;
                        heal -= att;
                        break;
                    }
                }
                if (!f) admin_b -= att;
            }
            action(admin_h, admin_c, admin_b, 0);
            if (admin_b <= 0) {
                std::cout << "S.S.";
                return;
            }
        }
        now ^= 1;
        // std::cout << "###\n";
        // std::cout << admin_b << ' ' << ss_b << '\n';
        // for (auto x : admin_c)std::cout << x << ' ';std::cout << '\n';
        // for (auto x : ss_c)std::cout << x << ' ';std::cout << '\n';
        // for (auto [id, x, y] : admin_h)std::cout << x << ' ' << y << ' ';std::cout << '\n';
        // for (auto [id, x, y] : ss_h)std::cout << x << ' ' << y << ' ';std::cout << '\n';
    }
    std::cout << "Draw";
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