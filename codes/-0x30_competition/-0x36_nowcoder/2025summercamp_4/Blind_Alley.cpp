//
//   ____      _                           _          _    __     ____     ___    ____    _____ 
//  |  _ \    (_)   __ _   _ __     __ _  | |   ___  / |  / /_   |___ \   ( _ )  | ___|  |___  |
//  | | | |   | |  / _` | | '_ \   / _` | | |  / _ \ | | | '_ \    __) |  / _ \  |___ \     / / 
//  | |_| |   | | | (_| | | | | | | (_| | | | |  __/ | | | (_) |  / __/  | (_) |  ___) |   / /  
//  |____/   _/ |  \__,_| |_| |_|  \__, | |_|  \___| |_|  \___/  |_____|  \___/  |____/   /_/   
//          |__/                   |___/                                                        
//
//  [题目链接] ： 
//
//  [题目名称] ： 
//
//  [  做法  ] ： 
//
#include <bits/stdc++.h>
#define fir first
#define sec second
#define el '\n'
#define all(x) (x).begin(), (x).end()
#define FINISH cout << "FINISH" << endl;
#define debug(x) cout << #x << " :== " << x << endl;
#define debugv(x)\
    cout << #x << " :: ";\
    for (auto v : x) cout << v << " ";\
    cout << endl;

using namespace std;
typedef long long ll;
typedef pair<int, int> PII;

const int mod = 998244353;
const int inf32 = 0x3f3f3f3f;
const ll inf64 = 0x3f3f3f3f3f3f3f3f;

int dx[3] = { 0, 1, -1 };
int dy[3] = { -1, 0, 0 };

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    auto id = [&](int x, int y) -> int
        {
            return (x - 1) * m + y;
        };
    auto get = [&](int v) -> PII
        {
            if (v % m == 0) {
                return { v / m, m };
            }
            return { v / m + 1, v % m };
        };
    vector<string> s(n + 1);
    vector<vector<int>> col(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] = " " + s[i];
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == '1')
                col[i][j] = 1;
        }
    }

    queue<int> q;
    q.push(id(n, m));
    col[n][m] = 3;

    while (!q.empty()) {
        auto [x, y] = get(q.front());
        q.pop();
        for (int i = 0; i < 3; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m)
                continue;
            if (col[nx][ny] != 0)
                continue;
            q.push(id(nx, ny));
            col[nx][ny] = 3;
        }
    }


    // for (int i = 1;i <= n;++i) {
    //     for (int j = 1;j <= m;++j) {
    //         std::cout << col[i][j] << ' ';
    //     }
    //     std::cout << std::endl;
    // }

    q.push(id(1, 1));
    col[1][1] = 2;

    dy[0] = 1;
    while (!q.empty()) {
        auto [x, y] = get(q.front());
        q.pop();
        for (int i = 0; i < 3; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m)
                continue;
            if (col[nx][ny] != 3)
                continue;
            q.push(id(nx, ny));
            col[nx][ny] = 2;
        }
    }
    dy[0] = -1;

    int cnt = 3;

    auto bfs = [&](int stx, int sty, int c) -> void
        {
            int dx[3] = { 0, 1, -1 };
            int dy[3] = { 1, 0, 0 };
            queue<int> q;
            q.push(id(stx, sty));
            col[stx][sty] = c;
            // cout << "bfs" << stx <<" " << sty << endl;
            while (!q.empty()) {
                auto [x, y] = get(q.front());
                q.pop();
                for (int i = 0; i < 3; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    // cout << nx << " " << ny << endl;
                    if (nx < 1 || nx > n || ny < 1 || ny > m)
                        continue;
                    if (s[nx][ny] == '1' || col[nx][ny])
                        continue;
                    // cout << nx << " " << ny << " Yes" << endl;
                    q.push(id(nx, ny));
                    col[nx][ny] = c;
                }
            }
        };

    for (int i = 2; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (col[j][i] == 0 && col[j][i - 1] == 2) {
                bfs(j, i, ++cnt);
            }
            // cout << col[i][j] << " ";
        }
        // cout << endl;
    }


    // for (int i = 1;i <= n;++i) {
    //     for (int j = 1;j <= m;++j) {
    //         std::cout << col[i][j] << ' ';
    //     }
    //     std::cout << std::endl;
    // }


    vector<int> mx(cnt + 1, 0);
    vector<int> mn(cnt + 1, m + 2);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (col[i][j] >= 4) {
                int c = col[i][j];
                mx[c] = max(mx[c], j);
                mn[c] = min(mn[c], j);
            }
        }
    }
    for (int i = 4; i <= cnt; i++) {
        if (mx[i] - mn[i] >= k - 1) {
            cout << "Yes" << el;
            return;
        }
    }
    cout << "No" << el;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

