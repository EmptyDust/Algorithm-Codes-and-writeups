#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

bool check(std::vector<pii> pts) {
    for (int i = 0;i < pts.size() - 2;++i) {
        auto [x1, y1] = pts[i];
        auto [x2, y2] = pts[i + 1];
        auto [x3, y3] = pts[i + 2];
        int k1x = x1 - x2, k1y = y1 - y2;
        int k2x = x3 - x1, k2y = y3 - y1;
        if (1ll * k1y * k2x != 1ll * k1x * k2y) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n;std::cin >> n;
    std::vector<pii> pts(n), cur;
    for (auto& [x, y] : pts)std::cin >> x >> y;
    std::sort(pts.begin(), pts.end());
    bool f = false;
    for (auto [x, y] : pts) {
        if (cur.size() < 4) { cur.push_back({ x,y });continue; }
        cur.push_back({ x,y });
        if (check(cur)) {
            cur.pop_back();
        }
        if (cur.size() == 5) {
            for (int i = 0;i < 5;++i) {
                std::vector<pii> tmp;
                for (int j = 0;j < 5;++j)if (i != j)tmp.push_back(cur[j]);
                if (check(tmp)) {
                    std::cout << "YES" << '\n';
                    std::cout << cur[i].first << ' ' << cur[i].second << '\n';
                    for (int j = 0;j < 5;++j)if (i != j)
                        std::cout << cur[j].first << ' ' << cur[j].second << '\n';
                    return;
                }
            }
            for (int i = 0;i < 5;++i) {
                for (int j = 0;j < 5;++j)if (i != j) {
                    for (int k = 0;k < 5;++k)if (i != k && j != k) {
                        std::vector<pii> lines{ cur[i],cur[j],cur[k] };
                        if (check(lines)) {
                            std::sort(lines.begin(), lines.end());
                            std::vector<pii> last(1, lines[1]);
                            for (int t = 0;t < 5;++t)if (t != i && t != j && t != k) {
                                last.push_back(cur[t]);
                            }
                            std::sort(last.begin(), last.end());
                            std::cout << "YES" << '\n';
                            std::cout << last[1].first << ' ' << last[1].second << '\n';
                            for (int t = 0;t < 5;++t)if (cur[t] != last[1]) {
                                std::cout << cur[t].first << ' ' << cur[t].second << '\n';
                            }
                            return;
                        }
                    }
                }
            }
            std::cout << "YES\n";
            for (int t = 0;t < 5;++t) {
                std::cout << cur[t].first << ' ' << cur[t].second << '\n';
            }
            return;
        }
    }
    std::cout << "NO\n";
}

// void solve() {
//     int n;std::cin >> n;
//     std::vector<pii> pts(n), cur;
//     for (auto& [x, y] : pts)std::cin >> x >> y;
//     std::sort(pts.begin(), pts.end());
//     for (auto& [x, y] : pts) {
//         if (cur.size() < 3) {
//             cur.push_back({ x,y });
//             continue;
//         }
//         bool f = true;
//         for (int i = 0;i < cur.size();++i) {
//             int cnt = 0;
//             auto [x1, y1] = cur[i];
//             for (int j = 0;j < cur.size();++j)if (i != j) {
//                 auto [x2, y2] = cur[j];
//                 int k1x = x1 - x2, k1y = y1 - y2;
//                 int k2x = x - x1, k2y = y - y1;
//                 if (1ll * k1y * k2x == 1ll * k1x * k2y) {
//                     cnt++;
//                 }
//             }
//             if (cnt >= 2) {
//                 f = false;
//                 break;
//             }
//         }
//         if (f) {
//             cur.push_back({ x,y });
//             if (cur.size() == 5) {
//                 std::vector<pii> lines;
//                 for (int i = 0;i < cur.size();++i) {
//                     auto [x1, y1] = cur[i];
//                     for (int j = 0;j < cur.size();++j)if (i != j) {
//                         auto [x2, y2] = cur[j];
//                         for (int k = 0;k < cur.size();++k)if (i != k && j != k) {
//                             auto [x3, y3] = cur[k];
//                             int k1x = x1 - x2, k1y = y1 - y2;
//                             int k2x = x3 - x1, k2y = y3 - y1;
//                             if (1ll * k1y * k2x == 1ll * k1x * k2y) {
//                                 lines.push_back({ x1,y1 });
//                                 lines.push_back({ x2,y2 });
//                                 lines.push_back({ x3,y3 });
//                                 std::sort(lines.begin(), lines.end());
//                                 std::vector<pii> last;last.push_back(lines[1]);
//                                 for (int t = 0;t < cur.size();++t)if (t != i && t != j && t != k) {
//                                     last.push_back(cur[t]);
//                                 }
//                                 std::sort(last.begin(), last.end());
//                                 std::cout << "YES" << '\n';
//                                 std::cout << last[1].first << ' ' << last[1].second << '\n';
//                                 for (int t = 0;t < cur.size();++t)if (cur[t] != last[1]) {
//                                     std::cout << cur[t].first << ' ' << cur[t].second << '\n';
//                                 }
//                                 return;
//                             }
//                         }
//                     }
//                 }
//                 std::cout << "YES\n";
//                 for (int t = 0;t < cur.size();++t) {
//                     std::cout << cur[t].first << ' ' << cur[t].second << '\n';
//                 }
//                 return;
//             }
//         }
//     }
//     std::cout << "NO\n";
// }

//y1/x1=y2/x2
//y1*x2=x1*y2

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}