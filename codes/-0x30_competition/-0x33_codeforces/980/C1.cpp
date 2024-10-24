#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<std::vector<std::array<int, 2>>> adj1(n);
    int m1;
    std::cin >> m1;
    for (int i = 0; i < m1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        adj1[u].push_back({ v, 1 });
        adj1[v].push_back({ u, k - 1 });
    }

    std::vector<int> b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    std::vector<std::vector<std::array<int, 2>>> adj2(n);
    int m2;
    std::cin >> m2;
    for (int i = 0; i < m2; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        adj2[u].push_back({ v, 1 });
        adj2[v].push_back({ u, k - 1 });
    }

    std::vector<int> fa(n, -1), fb(n, -1);
    std::queue<int> q;
    q.push(0);
    fa[0] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (auto [y, w] : adj1[x]) {
            if (fa[y] == -1) {
                fa[y] = (fa[x] + w) % k;
                q.push(y);
            }
        }
    }

    q.push(0);
    fb[0] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (auto [y, w] : adj2[x]) {
            if (fb[y] == -1) {
                fb[y] = (fb[x] + w) % k;
                q.push(y);
            }
        }
    }

    int a0 = std::count(a.begin(), a.end(), 0);
    int b1 = std::count(b.begin(), b.end(), 1);

    if (a0 != b1) {
        std::cout << "NO\n";
        return;
    }

    if (a0 == 0 || a0 == n) {
        std::cout << "YES\n";
        return;
    }

    std::vector<i64> s(k), t(k);
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            fa[i] = (fa[i] + 1) % k;
            s[fa[i]] += n;
        }
        else {
            fa[i] = (fa[i] - 1 + k) % k;
            s[fa[i]] += 1;
        }
        if (b[i] == 0) {
            t[fb[i]] += n;
        }
        else {
            t[fb[i]] += 1;
        }
    }
    std::cout << "s:" << '\n';
    for (int x : s)std::cout << x << " ";std::cout << std::endl;
    std::cout << "t:" << '\n';
    for (int x : t)std::cout << x << " ";std::cout << std::endl;
    s.push_back(-1);
    s.insert(s.end(), t.begin(), t.end());
    s.insert(s.end(), t.begin(), t.end());

    std::vector<int> f(s.size() + 1);
    for (int i = 1, j = 0; i < s.size(); i++) {
        while (j && s[i] != s[j]) {
            j = f[j];
        }
        j += (s[i] == s[j]);
        if (j == k) {
            std::cout << "YES\n";
            return;
        }
        f[i + 1] = j;
    }
    std::cout << "NO\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}