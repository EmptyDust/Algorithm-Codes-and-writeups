#include<bits/stdc++.h>

void solve() {
    int n;std::cin >> n;
    std::vector<int>a(n);
    for (int& x : a)std::cin >> x;
    std::vector<std::vector<int>> b(n, std::vector<int>(n));
    std::map<int, int> mp;
    for (int i = 0;i < n;++i) {
        std::priority_queue<int> spq;
        std::priority_queue<int, std::vector<int>, std::greater<int>> bpq;
        for (int j = i;j < n;++j) {
            if (spq.empty() || a[j] <= spq.top())spq.push(a[j]);
            else bpq.push(a[j]);
            if (spq.size() > bpq.size() + 1) {
                bpq.push(spq.top());
                spq.pop();
            }
            if (spq.size() < bpq.size()) {
                spq.push(bpq.top());
                bpq.pop();
            }
            b[i][j] = spq.top();
            // std::cout << b[i][j] << ' ';
            mp[spq.top()]++;
        }
        // std::cout << std::endl;
    }
    int cnt = 0, ans;
    for (auto [x, y] : mp) {
        if (y > cnt) {
            cnt = y;
            ans = x;
        }
    }
    std::cout << ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}