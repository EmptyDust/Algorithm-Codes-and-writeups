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

#define lowbit(x) (x&-x)

char ch[8];
std::string ans[201][201][22][2];
std::set<int> set[201][201][4][2][15];
std::string past;
int cnt = 0;

void work(a2 score, int step, int color, int red, bool op) {
    int bc = red + __builtin_popcount(color);
    if (ans[score[0]][score[1]][bc][op] == "NA")
        if (!(past.size() && past.back() == '/' && bc == 0))
            ans[score[0]][score[1]][bc][op] = past;
    if (red == 0 && step == 1) {
        work(score, 3, color, red, op);
        return;
    }
    if (set[score[0]][score[1]][step][op][red].contains(color)) {
        return;
    }
    cnt++;
    set[score[0]][score[1]][step][op][red].insert(color);
    if (step == 1) {
        past += ch[1];
        score[op]++;
        work(score, 2, color, red - 1, op);
        score[op]--;
        past.pop_back();

        past += '/';
        work(score, 1, color, red, !op);
        past.pop_back();
    }
    if (step == 2) {
        for (int i = 0;i < 6;++i) if (color >> i & 1) {
            past += ch[i + 2];
            score[op] += i + 2;
            work(score, 1, color, red, op);
            score[op] -= i + 2;
            past.pop_back();
        }

        past += '/';
        work(score, 1, color, red, !op);
        past.pop_back();
    }
    if (step == 3) {
        if (color != 0) {
            int i = std::__lg(lowbit(color));
            past += ch[i + 2];
            score[op] += i + 2;
            work(score, 3, color ^ (1 << i), red, op);
            score[op] -= i + 2;
            past.pop_back();
        }

        past += '/';
        work(score, 3, color, red, !op);
        past.pop_back();
    }
};

void solve() {
    for (int i = 0;i < 8;++i) ch[i] = '0' + i;
    for (int a = 0;a <= 200;++a) for (int b = 0;b <= 200;++b) for (int n = 0;n <= 21;++n) for (int i = 0;i < 2;++i)
        ans[a][b][n][i] = "NA";
    work(a2{ 0, 0 }, 1, (1 << 6) - 1, 15, 0);
    int q;std::cin >> q;
    while (q--) {
        int a, b, n, p;std::cin >> a >> b >> n >> p;
        std::cout << ans[a][b][n][p] << '\n';
    }
    // std::cout << cnt;
    // assert(0);
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}