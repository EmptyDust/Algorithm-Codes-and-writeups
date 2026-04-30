#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, d;
    std::cin >> n >> d;

    std::vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i];
    }

    int I = 0, J = 0, K = 0;
    auto work = [&]() {
        std::vector<std::array<int, 3>> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = { x[i] + y[i], x[i], i };
        }
        std::sort(a.begin(), a.end());

        std::vector<std::array<int, 4>> b;
        for (auto [s, x, i] : a) {
            auto it = std::lower_bound(a.begin(), a.end(), std::array{ s, x + d / 2, 0 });
            if (it != a.end() && (*it)[0] == s && (*it)[1] == x + d / 2) {
                b.push_back({ s, x, i, (*it)[2] });
            }
        }
        for (auto [s, x, i] : a) {
            auto it = std::lower_bound(b.begin(), b.end(), std::array{ s + d, x, 0, 0 });
            if (it != b.end() && (*it)[0] == s + d && (*it)[1] <= x + d / 2) {
                I = i + 1;
                J = (*it)[2] + 1;
                K = (*it)[3] + 1;
                return;
            }
        }
        };

    for (int t = 0; t < 4; t++) {
        work();
        if (I > 0) {
            break;
        }
        for (int i = 0; i < n; i++) {
            std::swap(x[i], y[i]);
            x[i] *= -1;
        }
    }
    std::cout << I << " " << J << " " << K << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}