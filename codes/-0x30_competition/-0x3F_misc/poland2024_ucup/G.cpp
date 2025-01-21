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

void solve() {
    int n;std::cin >> n;
    std::vector map(n, std::vector<char>(n));
    for (int i = 0;i < n;++i) {
        std::string s;std::cin >> s;
        for (int j = 0;j < n;++j) {
            map[i][j] = s[j];
        }
    }
    std::vector ax = { 1,1,0,-1,-1,-1,0,1 };
    std::vector ay = { 0,1,1,1,0,-1,-1,-1 };
    auto vaild = [&](int x, int y) {return 0 <= x && x < n && 0 <= y && y < n;};
    auto get = [&](int x, int y, char ch) {
        int cnt = 0;
        for (int i = 0;i < 8;++i) {
            int nx = x + ax[i], ny = y + ay[i];
            cnt += vaild(nx, ny) && map[nx][ny] == ch;
        }
        return cnt;
        };
    auto cal = [&]() {
        int ans = 0, ans2 = 0;
        for (int i = 0;i < n;++i) {
            for (int j = 0;j < n;++j) {
                if (map[i][j] == 'O') {
                    ans += get(i, j, 'O');
                    ans2++;
                }
                if (map[i][j] == 'M') {
                    ans += get(i, j, 'P');
                    ans2++;
                }
                if (map[i][j] == 'P') {
                    ans += get(i, j, 'M');
                    ans2++;
                }
            }
        }
        return ans / 2 + ans2;
        };
    std::cout << cal() << ' ';
    auto work = [&]() {
        for (int i = 0;i < n;++i) {
            for (int j = 0;j < n;++j) {
                if (map[i][j] == 'o' && get(i, j, 'O')) {
                    map[i][j] = 'O';
                    return true;
                }
                if (map[i][j] == 'm' && get(i, j, 'P')) {
                    map[i][j] = 'M';
                    return true;
                }
                if (map[i][j] == 'p' && get(i, j, 'M')) {
                    map[i][j] = 'P';
                    return true;
                }
            }
        }
        return false;
        };
    while (work());
    std::cout << cal() << '\n';
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < n;++j) {
            std::cout << map[i][j];
        }
        std::cout << '\n';
    }
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