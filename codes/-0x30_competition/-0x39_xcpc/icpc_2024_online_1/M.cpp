#include<bits/stdc++.h>

void solve() {
    int n;std::cin >> n;
    std::map<std::string, std::set<std::string>> mp;
    for (int i = 0;i < n;++i) {
        std::string name, ID, st;
        std::cin >> name >> ID >> st;
        if (st == "accepted")mp[ID].insert(name);
    }
    std::string s;
    int ans = 0;
    for (auto [id, st] : mp) {
        if (ans < st.size()) {
            s = id;
            ans = st.size();
        }
    }
    std::cout << s;
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