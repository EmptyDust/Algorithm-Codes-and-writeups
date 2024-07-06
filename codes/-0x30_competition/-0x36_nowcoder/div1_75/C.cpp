#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e4 + 10, inf = 1e9, mod = 1e9 + 7;
int n;
using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
std::vector<pii> columns[MAXN];
std::vector<pii> rows[MAXN];

void solve() {
    int n, m;std::cin >> n >> m;
    std::string s;std::cin >> s;
    std::vector<pii> pts(n);
    std::set<int> st;
    for (auto& [x, y] : pts) {
        std::cin >> x >> y;
        st.insert(x);
        st.insert(y);
    }
    std::map<int, int> mp;
    int lsi = 0;
    for (int x : st) {
        mp[x] = lsi++;
    }

    for (int i = 0;i < n;++i) {
        auto& [x, y] = pts[i];
        x = mp[x];
        y = mp[y];
        rows[x].push_back({ y,i });
        columns[y].push_back({ x,i });
    }

    for (int x = 0;x < lsi;++x) {
        std::sort(rows[x].begin(), rows[x].end());
        std::sort(columns[x].begin(), columns[x].end());
    }

    std::vector<bool> canreach(n, 1);
    for (char ch : s) {
        std::vector<bool> new_canreach(n, 0);
        for (int i = 0;i < n;++i)if (canreach[i]) {
            auto [x, y] = pts[i];
            switch (ch)
            {
            case 'L': {
                int pos = std::lower_bound(columns[y].begin(), columns[y].end(), std::pair{ x,i }) - columns[y].begin();
                for (int j = pos - 1;j >= 0;--j) {
                    auto [x, num] = columns[y][j];
                    if (new_canreach[num])break;
                    new_canreach[num] = true;
                }
                break;
            }
            case 'R': {
                int sz = columns[y].size();
                int pos = std::lower_bound(columns[y].begin(), columns[y].end(), std::pair{ x,i }) - columns[y].begin();
                for (int j = pos + 1;j < sz;++j) {
                    auto [x, num] = columns[y][j];
                    if (new_canreach[num])break;
                    new_canreach[num] = true;
                }
                break;
            }
            case 'D': {
                int pos = std::lower_bound(rows[x].begin(), rows[x].end(), std::pair{ y,i }) - rows[x].begin();
                for (int j = pos - 1;j >= 0;--j) {
                    auto [y, num] = rows[x][j];
                    if (new_canreach[num])break;
                    new_canreach[num] = true;
                }
                break;
            }
            case 'U': {
                int sz = rows[x].size();
                int pos = std::lower_bound(rows[x].begin(), rows[x].end(), std::pair{ y,i }) - rows[x].begin();
                for (int j = pos + 1;j < sz;++j) {
                    auto [y, num] = rows[x][j];
                    if (new_canreach[num])break;
                    new_canreach[num] = true;
                }
                break;
            }
            }
        }
        canreach = new_canreach;
    }
    bool f = false;
    for (int i = 0;i < n;++i)if (canreach[i]) {
        f = true;
        break;
    }
    std::cout << (f ? "YES" : "NO");

    for (int x = 0;x < lsi;++x) {
        rows[x].clear();
        columns[x].clear();
    }
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