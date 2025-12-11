#include <bits/stdc++.h>

int n;
std::vector<int> a, x;

bool ok(int w) {
    for (int u : x)
        for (int v : x)
            if (abs(u - v) == w) return true;
    return false;
}

bool dfs(int lim) {
    int k = -1;
    for (int i = 0; i < n; ++i) {
        if (!ok(a[i])) {
            k = i;
            break;
        }
    }
    if (k == -1) return true;
    if (x.size() >= lim) return false;

    int sz = x.size();
    for (int i = 0; i < sz; ++i) {
        int cand[] = { x[i] + a[k], x[i] - a[k] };
        for (int u : cand) {
            bool exist = false;
            for (int t : x) if (t == u) exist = true;
            if (!exist) {
                x.push_back(u);
                if (dfs(lim)) return true;
                x.pop_back();
            }
        }
    }
    return false;
}

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    std::cin >> n;
    a.resize(n);
    for (int& i : a)std::cin >> i;
    sort(a.begin(), a.end());

    for (int i = 1; i <= n + 1; ++i) {
        x = { 0 };
        if (dfs(i)) {
            std::cout << i << std::endl;
            break;
        }
    }
    return 0;
}