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

void solve() {
    int n, m;std::cin >> n >> m;
    std::string s;std::cin >> s;
    std::vector cnt(3, std::vector<int>(3));
    int cnt120 = 0, cnt12 = 0, cnt21 = 0, cnt210 = 0;
    for (int i = 0;i < m;++i) {
        char x, y;std::cin >> x >> y;
        x = x - 'a', y = y - 'a';
        cnt[x][y]++;
        if (x == 1 && y == 2)cnt12++;
        if (x == 2 && y == 0 && cnt12) {
            cnt12--;
            cnt120++;
        }
        if (x == 2 && y == 1)cnt21++;
        if (x == 1 && y == 0 && cnt21) {
            cnt21--;
            cnt210++;
        }
    }
    for (char& ch : s) {
        int c = ch - 'a';
        if (c == 0)continue;
        if (c == 1) {
            if (cnt[1][0]) {
                cnt[1][0]--;
                ch = 'a';
                continue;
            }
            if (cnt[1][2] && cnt[2][0] && cnt120) {
                cnt[1][2]--;
                cnt[2][0]--;
                cnt120--;
                ch = 'a';
                continue;
            }
            continue;
        }
        if (cnt[2][0]) {
            cnt[2][0]--;
            ch = 'a';
            continue;
        }
        if (cnt[2][1]) {
            cnt[2][1]--;
            ch = 'b';
            if (cnt[1][0] && cnt210) {
                cnt[1][0]--;
                cnt210--;
                ch = 'a';
            }
            continue;
        }
    }
    std::cout << s;
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