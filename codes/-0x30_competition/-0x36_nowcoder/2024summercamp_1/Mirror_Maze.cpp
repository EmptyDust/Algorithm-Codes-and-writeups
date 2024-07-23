#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e3, MAXN = 1e3 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

int idx[MAXN][MAXN][4], nxt[MAXN * MAXN * 4], is_cal[MAXN * MAXN * 4];
int ans_t[MAXN * MAXN * 4], color[MAXN * MAXN * 4], pos_color[MAXN * MAXN];

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    memset(idx, -1, sizeof idx);
    memset(pos_color, -1, sizeof pos_color);
    memset(color, -1, sizeof color);
    memset(ans_t, -1, sizeof ans_t);

    int n, m;std::cin >> n >> m;
    int id = 0;
    for (int i = 1;i <= n;++i)
        for (int j = 1;j <= m;++j)
            for (int k = 0;k < 4;++k)
                idx[i][j][k] = id++;
    for (int i = 1;i <= n;++i) {
        std::string s;std::cin >> s;
        for (int j = 1;j <= m;++j) {
            switch (s[j - 1])//u:0 r:1 d:2 l:3
            {
            case '|':
                nxt[idx[i][j][0]] = idx[i + 1][j][0];
                nxt[idx[i][j][1]] = idx[i][j + 1][3];
                nxt[idx[i][j][2]] = idx[i - 1][j][2];
                nxt[idx[i][j][3]] = idx[i][j - 1][1];
                is_cal[idx[i][j][0]] = 0;
                is_cal[idx[i][j][1]] = 1;
                is_cal[idx[i][j][2]] = 0;
                is_cal[idx[i][j][3]] = 1;
                break;
            case '-':
                nxt[idx[i][j][0]] = idx[i - 1][j][2];
                nxt[idx[i][j][1]] = idx[i][j - 1][1];
                nxt[idx[i][j][2]] = idx[i + 1][j][0];
                nxt[idx[i][j][3]] = idx[i][j + 1][3];
                is_cal[idx[i][j][0]] = 1;
                is_cal[idx[i][j][1]] = 0;
                is_cal[idx[i][j][2]] = 1;
                is_cal[idx[i][j][3]] = 0;
                break;
            case '/':
                nxt[idx[i][j][0]] = idx[i][j - 1][1];
                nxt[idx[i][j][1]] = idx[i + 1][j][0];
                nxt[idx[i][j][2]] = idx[i][j + 1][3];
                nxt[idx[i][j][3]] = idx[i - 1][j][2];
                is_cal[idx[i][j][0]] = 1;
                is_cal[idx[i][j][1]] = 1;
                is_cal[idx[i][j][2]] = 1;
                is_cal[idx[i][j][3]] = 1;
                break;
            case '\\':
                nxt[idx[i][j][0]] = idx[i][j + 1][3];
                nxt[idx[i][j][1]] = idx[i - 1][j][2];
                nxt[idx[i][j][2]] = idx[i][j - 1][1];
                nxt[idx[i][j][3]] = idx[i + 1][j][0];
                is_cal[idx[i][j][0]] = 1;
                is_cal[idx[i][j][1]] = 1;
                is_cal[idx[i][j][2]] = 1;
                is_cal[idx[i][j][3]] = 1;
                break;
            }
        }
    }

    auto print = [&](int x) {
        int pos = x / 4;
        int dir = x % 4;
        std::cout << pos / m + 1 << ' ' << pos % m + 1 << ' ' << dir << '\n';
        };

    int q;std::cin >> q;
    std::vector<int> questions;
    while (q--) {
        int x, y;std::cin >> x >> y;
        std::string s;std::cin >> s;
        int dir = -1;
        switch (s[0])
        {
        case 'a':
            x--;
            dir = 2;
            break;
        case 'r':
            y++;
            dir = 3;
            break;
        case 'b':
            x++;
            dir = 0;
            break;
        case 'l':
            y--;
            dir = 1;
            break;
        default:
            break;
        }
        questions.push_back(idx[x][y][dir]);
    }

    int cid = 0;
    auto work = [&](int x) {
        if (color[x] != -1) {
            return;
        }
        std::vector<int> dfs;
        cid++;

        while (1) {
            if (x == -1) {
                int res = 0;
                std::reverse(dfs.begin(), dfs.end());
                for (int x : dfs) {
                    if (is_cal[x] && pos_color[x / 4] != cid) {
                        pos_color[x / 4] = cid;
                        res++;
                    }
                    ans_t[x] = res;
                }
                break;
            }
            if (color[x] == cid) {
                int res = 0;
                for (int x : dfs) {
                    if (is_cal[x] && pos_color[x / 4] != cid) {
                        pos_color[x / 4] = cid;
                        res++;
                    }
                }
                for (int x : dfs)ans_t[x] = res;
                break;
            }
            dfs.push_back(x);
            color[x] = cid;
            x = nxt[x];
        }
        };

    for (int i = 1;i <= n;++i) {
        work(idx[i][1][3]);
        work(idx[i][m][1]);
    }

    for (int i = 1;i <= m;++i) {
        work(idx[1][i][0]);
        work(idx[n][i][2]);
    }

    for (int i = 0;i < n * m * 4;++i) {
        if (ans_t[i] == -1) {
            work(i);
        }
    }

    std::vector<int> ans;
    for (int x : questions) {
        if (x == -1)ans.push_back(0);
        else ans.push_back(ans_t[x]);
    }
    for (int x : ans)std::cout << x << '\n';

    return 0;
}