

#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int a[10][7] = {
        {1,1,1,1,1,1,0},
        {0,1,1,0,0,0,0},
        {1,1,0,1,1,0,1},
        {1,1,1,1,0,0,1},
        {0,1,1,0,0,1,1},
        {1,0,1,1,0,1,1},
        {1,0,1,1,1,1,1},
        {1,1,1,0,0,0,0},
        {1,1,1,1,1,1,1},
        {1,1,1,1,0,1,1}
    };
    std::string s, t;
    std::cin >> s >> t;
    int n = s.length();
    int cnt = 0;
    for (int i = 0;i < n;++i) {
        int x = s[i] - '0', y = t[i] - '0';
        for (int j = 0;j < 7;++j) {
            if (a[x][j] != a[y][j])
                cnt++;
        }
    }
    std::cout << cnt;
    return 0;
}