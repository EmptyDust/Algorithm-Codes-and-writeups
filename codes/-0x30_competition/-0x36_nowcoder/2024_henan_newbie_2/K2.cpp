//      _/_/_/              _/                     _/_/_/                                               
//   _/           _/_/_/                        _/         _/    _/    _/_/_/   _/_/_/       _/_/_/   
//  _/         _/    _/   _/                   _/  _/_/   _/    _/  _/    _/   _/    _/   _/    _/    
// _/         _/    _/   _/                   _/    _/   _/    _/  _/    _/   _/    _/   _/    _/     
//  _/_/_/     _/_/_/   _/                     _/_/_/     _/_/_/    _/_/_/   _/    _/     _/_/_/      
//                             _/_/_/_/_/                                                    _/       
//                                                                                      _/_/_/
// Problem: 绝对不模拟的简单魔方
// Contest: HDOJ
// URL: https://acm.hdu.edu.cn/contest/problem?cid=1125&pid=1103
// Memory Limit: 262144 MB
// Time Limit: 1100 ms
// Editor: Cai_Guang
// Time: 2024-07-22 13:16:28

#include <bits/stdc++.h>

using namespace std;

#define int long long
#ifndef Cai_Guang
#define debug //
#define test //
#endif

int dx[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dy[] = { -1, 0, 1, 1, 1, 0, -1, -1 };

vector<string> model{
    "",
    " ***OOO******",
    " ***OOO******",
    " ***OOO******",
    " BBBYYYGGGWWW",
    " BBBYYYGGGWWW",
    " BBBYYYGGGWWW",
    " ***RRR******",
    " ***RRR******",
    " ***RRR******"
};

void solve() {
    int n = 9, m = 12;
    vector<string> s(n + 1);

    for (int i = 1; i <= 3; i++) {
        s[i] = " ***";
        for (int j = 1; j <= 3; j++) {
            string t;
            cin >> t;
            s[i] += t[0];
        }
        s[i] += "******";
    }

    for (int i = 4; i <= 6; i++) {
        s[i] = " ";
        for (int j = 1; j <= 12; j++) {
            string t;
            cin >> t;
            s[i] += t[0];
        }
    }

    for (int i = 7; i <= 9; i++) {
        s[i] = " ***";
        for (int j = 1; j <= 3; j++) {
            string t;
            cin >> t;
            s[i] += t[0];
        }
        s[i] += "******";
    }

    // for (int i = 1; i <= n; i++) {
        // cout << s[i] << '\n';
    // }
    // return;

    auto surfaceRotate = [&](vector<string> t, int l, int r, int rev) {
        int L = l + 1, R = r + 1;
        auto re = t;
        if (rev) {
            for (int k = 0; k < 8; k++) {
                re[L + dx[k]][R + dy[k]] = t[L + dx[(k + 2) % 8]][R + dy[(k + 2) % 8]];
            }
        }
        else {
            for (int k = 0; k < 8; k++) {
                re[L + dx[(k + 2) % 8]][R + dy[(k + 2) % 8]] = t[L + dx[k]][R + dy[k]];
            }
        }
        return re;
        };

    auto moveX = [&](vector<string> t, int x) {
        auto r = t;
        r[x] = ' ' + t[x].substr(4) + t[x].substr(1, 3);
        return r;
        };

    auto moveXp = [&](vector<string> t, int x) {
        auto r = t;
        r[x] = ' ' + t[x].substr(10) + t[x].substr(1, 9);
        return r;
        };

    auto U = [&](vector<string> t) {
        auto r = surfaceRotate(t, 1, 4, 0);
        return moveX(r, 4);
        };

    auto Up = [&](vector<string> t) {
        auto r = surfaceRotate(t, 1, 4, 1);
        return moveXp(r, 4);
        };

    auto MX = [&](vector<string> t) {
        return moveX(t, 5);
        };

    auto MXp = [&](vector<string> t) {
        return moveXp(t, 5);
        };

    auto D = [&](vector<string> t) {
        auto r = surfaceRotate(t, 7, 4, 1);
        return moveX(r, 6);
        };

    auto Dp = [&](vector<string> t) {
        auto r = surfaceRotate(t, 7, 4, 0);
        return moveXp(r, 6);
        };

    auto moveY = [&](vector<string> t, int x) {
        auto r = t;
        for (int i = 1; i <= 6; i++) {
            r[i][x] = t[i + 3][x];
        }
        for (int i = 7; i <= 9; i++) {
            r[i][x] = t[13 - i][16 - x];
        }
        for (int i = 7; i <= 9; i++) {
            r[13 - i][16 - x] = t[i - 6][x];
        }
        return r;
        };

    auto moveYp = [&](vector<string> t, int x) {
        auto r = t;
        for (int i = 1; i <= 6; i++) {
            r[i + 3][x] = t[i][x];
        }
        for (int i = 7; i <= 9; i++) {
            r[13 - i][16 - x] = t[i][x];
        }
        for (int i = 7; i <= 9; i++) {
            r[i - 6][x] = t[13 - i][16 - x];
        }
        return r;
        };

    auto L = [&](vector<string> t) {
        auto r = surfaceRotate(t, 4, 1, 1);
        return moveY(r, 4);
        };

    auto Lp = [&](vector<string> t) {
        auto r = surfaceRotate(t, 4, 1, 0);
        return moveYp(r, 4);
        };

    auto MY = [&](vector<string> t) {
        return moveY(t, 5);
        };

    auto MYp = [&](vector<string> t) {
        return moveYp(t, 5);
        };

    auto R = [&](vector<string> t) {
        auto r = surfaceRotate(t, 4, 7, 0);
        return moveY(r, 6);
        };

    auto Rp = [&](vector<string> t) {
        auto r = surfaceRotate(t, 4, 7, 1);
        return moveYp(r, 6);
        };

    auto moveZ = [&](vector<string> t, int x) {
        auto r = t;
        for (int i = 4; i <= 6; i++) {
            r[x][i] = t[10 - i][x];
            r[10 - x][i] = t[10 - i][10 - x];
            r[i][x] = t[10 - x][i];
            r[i][10 - x] = t[x][i];
        }
        return r;
        };

    auto moveZp = [&](vector<string> t, int x) {
        auto r = t;
        for (int i = 4; i <= 6; i++) {
            r[10 - i][x] = t[x][i];
            r[10 - i][10 - x] = t[10 - x][i];
            r[10 - x][i] = t[i][x];
            r[x][i] = t[i][10 - x];
        }
        return r;
        };

    auto F = [&](vector<string> t) {
        auto r = surfaceRotate(t, 4, 4, 0);
        return moveZ(r, 3);
        };

    auto Fp = [&](vector<string> t) {
        auto r = surfaceRotate(t, 4, 4, 1);
        return moveZp(r, 3);
        };

    auto MZ = [&](vector<string> t) {
        return moveZ(t, 2);
        };

    auto MZp = [&](vector<string> t) {
        return moveZp(t, 2);
        };

    auto B = [&](vector<string> t) {
        auto r = surfaceRotate(t, 4, 10, 1);
        return moveZ(r, 1);
        };

    auto Bp = [&](vector<string> t) {
        auto r = surfaceRotate(t, 4, 10, 0);
        return moveZp(r, 1);
        };

    int is = 0;

    auto check = [&]() {
        int diff = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                diff += s[i][j] != model[i][j];
            }
        }
        return diff == 0;
        };

    stack<string> stk;
    int ans = 1e18;
    function<void(int, int)> dfs = [&](int dep, int out) {
        if (is) {
            return;
        }
        if (dep <= 8) {
            if (check()) {
                ans = min(ans, (int)stk.size());
                if (out && ans == stk.size()) {
                    cout << ans << '\n';
                    vector<string> st;
                    while (stk.size()) {
                        st.push_back(stk.top());
                        stk.pop();
                    }
                    for (int i = st.size() - 1; i >= 0; i--) {
                        cout << st[i] << '\n';
                    }
                    exit(0);
                }
            }
        }
        if (dep == 8 || is) {
            return;
        }

        auto t = s;
        s = F(t);
        stk.push("U1");
        dfs(dep + 1, out);
        stk.pop();
        s = Fp(t);
        stk.push("U2");
        dfs(dep + 1, out);
        stk.pop();
        s = R(t);
        stk.push("R1");
        dfs(dep + 1, out);
        stk.pop();
        s = Rp(t);
        stk.push("R2");
        dfs(dep + 1, out);
        stk.pop();
        s = D(t);
        stk.push("F2");
        dfs(dep + 1, out);
        stk.pop();
        s = Dp(t);
        stk.push("F1");
        dfs(dep + 1, out);
        stk.pop();
        };

    dfs(0, 0);
    dfs(0, 1);

    // auto t = F(s);
// 	
    // for (int i = 1; i <= 9; i++) {
        // cout << t[i] << '\n';
    // }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

#ifdef Cai_Guang
    //freopen("1.in", "r", stdin);
    localTest = true;
#endif

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }
}