#include<bits/stdc++.h>

#define ranges std::ranges

using pii = std::pair<int, int>;

using i64 = long long;

void solve() {
    int n;std::cin >> n;
    std::vector<pii> info(n);
    char st = 0;
    for (auto& [dir, dis] : info) {
        char ch;std::cin >> ch >> dis;
        switch (ch)
        {
        case 'S':
            dir = 0;
            break;
        case 'E':
            dir = 1;
            break;
        case 'N':
            dir = 2;
            break;
        case 'W':
            dir = 3;
            break;
        }
        if (!st) st = ch;
    }
    std::vector<int> ans;ans.push_back(info[0].second);
    for (int i = 1;i < n;++i) {
        if ((info[i].first - info[i - 1].first + 4) % 4 == 1)ans.push_back(-1);
        else ans.push_back(-2);
        ans.push_back(info[i].second);
    }
    std::cout << ans.size() << ' ' << st << '\n';
    for (int x : ans) {
        if (x == -1)std::cout << 'L' << '\n';
        else if (x == -2)std::cout << 'R' << '\n';
        else std::cout << "Z " << x << '\n';
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}