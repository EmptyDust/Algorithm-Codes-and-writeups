#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e3 + 10, inf = 1e9, mod = 1e9 + 7;
int map[MAXN][MAXN], row_cnt[MAXN], colomn_cnt[MAXN], row_res[MAXN], colomn_res[MAXN], n;
using pt = std::pair<int, int>;

bool work() {
    bool ok = false;
    while (!ok) {
        ok = true;
        for (int i = 0;i < n;++i)if (row_cnt[i] == 1) {
            int pos, x = 0;
            for (int j = 0;j < n;++j) {
                if (map[i][j] == -1) {
                    pos = j;
                }
                else x ^= map[i][j];
            }
            if (x == row_res[i])map[i][pos] = 0;
            else map[i][pos] = 1;
            row_cnt[i]--;
            colomn_cnt[pos]--;
            ok = false;
        }
        for (int j = 0;j < n;++j)if (colomn_cnt[j] == 1) {
            int pos, x = 0;
            for (int i = 0;i < n;++i) {
                if (map[i][j] == -1) {
                    pos = i;
                }
                else x ^= map[i][j];
            }
            if (x == colomn_res[j])map[pos][j] = 0;
            else map[pos][j] = 1;
            colomn_cnt[j]--;
            row_cnt[pos]--;
            ok = false;
        }
    }
    for (int i = 0;i < n;++i)if (row_cnt[i] || colomn_cnt[i])
        return false;
    for (int i = 0;i < n;++i) {
        int x = 0;
        for (int j = 0;j < n;++j) {
            x ^= map[i][j];
        }
        if (x != row_res[i])
            return false;
    }
    for (int j = 0;j < n;++j) {
        int x = 0;
        for (int i = 0;i < n;++i) {
            x ^= map[i][j];
        }
        if (x != colomn_res[j])
            return false;
    }
    return true;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    for (int i = 0;i < n;++i)for (int j = 0;j < n;++j) {
        std::cin >> map[i][j];
        if (map[i][j] == -1) {
            row_cnt[i]++;
            colomn_cnt[j]++;
        }
    }
    for (int i = 0;i < n;++i)std::cin >> row_res[i];
    for (int i = 0;i < n;++i)std::cin >> colomn_res[i];
    if (work())
        for (int i = 0;i < n;++i) {
            for (int j = 0;j < n;++j) {
                std::cout << map[i][j] << ' ';
            }
            std::cout << '\n';
        }
    else std::cout << -1;
    return 0;
}