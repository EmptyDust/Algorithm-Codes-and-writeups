#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 500;
int map[MAXN][MAXN], n, m;
using pt = std::pair<int, int>;

int p[3][5][3] = {
    {
        {1,1,1},
        {1,0,1},
        {1,1,1},
        {1,0,0},
        {1,0,0},
    },
    {
        {1,1,1},
        {0,0,1},
        {0,1,1},
        {0,0,1},
        {0,0,1}
    },
    {
        {1,1,1},
        {1,0,1},
        {1,1,1},
        {1,0,1},
        {1,1,1},
    }
};

bool check1(int x, int y) {
    if (x + 5 > n || y + 3 > m)return false;
    for (int i = 0;i < 5;++i)for (int j = 0;j < 3;++j) {
        if (p[0][i][j] && !map[x + i][y + j]) {
            return false;
        }
    }
    return true;
}

bool check2(int x, int y) {
    if (x + 5 > n || y + 3 > m)return false;
    for (int i = 0;i < 5;++i)for (int j = 0;j < 3;++j) {
        if (p[1][i][j] && !map[x + i][y + j])
            return false;
    }
    return true;
}

bool check3(int x, int y) {
    if (x + 5 > n || y + 3 > m)return false;
    for (int i = 0;i < 5;++i)for (int j = 0;j < 3;++j) {
        if (p[2][i][j] && !map[x + i][y + j])
            return false;
    }
    return true;
}

void clear(int x, int y, int pi) {
    pi--;
    for (int i = 0;i < 5;++i)for (int j = 0;j < 3;++j) {
        if (p[pi][i][j])
            map[x + i][y + j] = false;
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m;
    char c;
    for (int i = 0;i < n;++i)for (int j = 0;j < m;++j) {
        std::cin >> c;
        map[i][j] = c == '#';
    }
    int cnt[4]{ 0,0,0,0 };
    for (int j = 0;j < m;++j)for (int i = 0;i < n;++i)if (map[i][j]) {
        if (check3(i, j)) {
            cnt[3]++;
            clear(i, j, 3);
        }
        else if (check1(i, j)) {
            cnt[1]++;
            clear(i, j, 1);
        }
        else if (check2(i, j)) {
            cnt[2]++;
            clear(i, j, 2);
        }
    }
    for (int i = 1;i <= 3;++i)std::cout << cnt[i] << ' ';
    return 0;
}