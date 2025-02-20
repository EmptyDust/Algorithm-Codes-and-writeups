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

int query(int i, int j) {
    std::cout << "1 " << i << ' ' << j << std::endl;
    std::string s;std::cin >> s;
    int x = 0;char ch;std::cin >> ch;
    if (ch == '>')x = 1;
    if (ch == '=')x = 0;
    if (ch == '<')x = -1;
    return x;
}

void solve() {
    int n;std::cin >> n;
    std::vector<pii> res1, res2;
    std::vector<std::vector<int>> vt(30);
    for (int i = 1;i <= n;++i) {
        std::vector<int> cur(1, i);
        for (int t = 0;t < 30;++t) {
            if (vt[t].empty()) {
                vt[t] = cur;
                break;
            }
            int x = query(i, vt[t][0]);
            if (x == 0) {
                for (int x : vt[t])cur.push_back(x);
                vt[t].clear();
                continue;
            }
            if (x > 0)std::swap(cur, vt[t]);
            for (int j = 0;j < cur.size();++j) {
                res1.push_back({ cur[j],vt[t][j] });
            }
            vt[t].clear();
            break;
        }
    }
    int max = 0;
    for (int t = 29;t >= 0;--t)if (vt[t].size()) {
        max = t;
        break;
    }
    // std::cout << max << "max\n";
    auto eq = vt[max];
    for (int t = max - 1;t >= 0;--t)if (vt[t].size()) {
        int x = query(eq[0], vt[t][0]);
        if (x == 0) {
            for (int x : vt[t])eq.push_back(x);
            vt[t].clear();
            continue;
        }
        while (vt[t].size()) {
            if (x > 0) res2.emplace_back(vt[t].back(), eq.back());
            else res2.emplace_back(eq.back(), vt[t].back());
            eq.pop_back(), vt[t].pop_back();
        }
    }
    // std::cout << eq.size() << '\n';
    for (auto [lo, hi] : res1) {
        if (eq.empty()) {
            res2.push_back({ lo,hi });
            continue;
        }
        int x = query(eq[0], lo);
        if (x == 0) {
            res2.push_back({ lo,hi });
            continue;
        }
        if (x < 0) {
            // std::cout << lo << ' ' << hi << '\n';
            res2.push_back({ eq.back(), lo });eq.pop_back();
            res2.push_back({ eq.back(),hi });eq.pop_back();
            continue;
        }
        x = query(eq[0], hi);
        if (x == 0) {
            res2.push_back({ lo,hi });
            continue;
        }
        if (x < 0) {
            res2.push_back({ lo,eq.back() });eq.pop_back();
            res2.push_back({ eq.back(),hi });eq.pop_back();
        }
        else {
            res2.push_back({ lo,eq.back() });eq.pop_back();
            res2.push_back({ hi,eq.back() });eq.pop_back();
        }
    }
    if (eq.size()) {
        std::cout << "0 0" << std::endl;
        std::string s;std::cin >> s;
        return;
    }
    std::cout << "0 1" << std::endl;
    for (auto [lo, hi] : res2) {
        std::cout << lo << ' ' << hi << std::endl;
    }
    std::string s;std::cin >> s;
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