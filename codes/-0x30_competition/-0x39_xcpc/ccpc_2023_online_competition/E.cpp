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

pii newpos(pii a, char ch) {
    switch (ch)
    {
    case 'L':
        a.first--;
        break;
    case 'R':
        a.first++;
        break;
    case 'D':
        a.second--;
        break;
    case 'U':
        a.second++;
    default:
        break;
    }
    return a;
}

int map[100][100];

const int MID = 50;
pii check(std::string s, int mask) {
    int n = s.length();
    pii pos = { 0,0 };
    std::vector<pii> change;
    map[MID][MID] = 1;
    for (int i = 0;i < n;++i) {
        pii np = newpos(pos, s[i]);
        int& status = map[MID + np.first][MID + np.second];
        if (mask >> i & 1) {
            if (status != 2) {
                status = 1;
                change.push_back({ MID + np.first,MID + np.second });
                pos = np;
            }
        }
        else {
            if (status == 1) {
                for (auto [x, y] : change)map[x][y] = 0;
                return { 0,0 };
            }
            status = 2;
            change.push_back({ MID + np.first,MID + np.second });
        }
        // if (mask == 9)std::cout << pos.first << " " << pos.second << '\n';
        // if (mask == 9)std::cout << status << '\n';
    }
    // if (pos == std::pair{ -1, -1 }) {
    //     std::cout << mask << '\n';
    // }
    //1001
    for (auto [x, y] : change)map[x][y] = 0;
    return pos;
}

void solve() {
    int n;std::cin >> n;
    std::string s;std::cin >> s;
    std::vector<pii> res;
    for (int mask = 0;mask < (1 << n);++mask) {
        res.push_back(check(s, mask));
    }
    ranges::sort(res);
    res.erase(std::unique(res.begin(), res.end()), res.end());
    std::cout << res.size() << '\n';
    for (auto [x, y] : res)std::cout << x << ' ' << y << '\n';
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