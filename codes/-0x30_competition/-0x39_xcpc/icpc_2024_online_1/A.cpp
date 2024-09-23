#include<bits/stdc++.h>

void solve() {
    std::vector<int> a(32);
    int cnt = 0;
    int china;
    for (int i = 0;i < 32;++i) {
        if (!i)std::cin >> china;
        else {
            int x;std::cin >> x;
            if (x < china)cnt++;
        }
    }
    if (cnt < 2)std::cout << 32;
    else if (cnt < 6)std::cout << 16;
    else if (cnt < 13)std::cout << 8;
    else if (cnt < 27)std::cout << 4;
    else if (cnt < 31)std::cout << 2;
    else std::cout << 1;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}