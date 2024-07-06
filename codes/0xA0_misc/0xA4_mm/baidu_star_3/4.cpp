#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll inf = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int i = 1;
    map<int, vector<pair<int, int>>> e;
    vector<int> root(n + 1), siz(n + 1);
    function<int(int)> find = [&](int u) -> int {
        while (u != root[u]) u = root[u];
        return root[u];
        };
    iota(root.begin() + 1, root.end(), 1);
    fill(siz.begin() + 1, siz.end(), 1);
    vector<array<int, 2>> bk;
    auto merge = [&](int u, int v) -> void {
        u = find(u);
        v = find(v);
        if (siz[u] > siz[v]) swap(u, v);
        bk.push_back({ u, v });
        siz[v] += siz[u];
        root[u] = v;
        };
    auto back = [&]() -> void {
        auto [u, v] = bk.back();
        bk.pop_back();
        siz[v] -= siz[u];
        root[u] = u;
        };
    while (i <= n) {
        int s = i;
        while (i <= n && a[i] == a[s]) {
            if (i > s) merge(i, i - 1);
            i++;
        }
        if (s > 1 && i <= n && a[s - 1] == a[i]) e[a[s]].push_back({ s - 1, i });
    }
    int ans = *max_element(siz.begin() + 1, siz.end());
    int add = ans;
    for (auto [k, v] : e) {
        for (auto [x, y] : v) {
            merge(x, y);
            add = max(add, siz[find(x)]);
        }

        for (auto [x, y] : v) {
            back();
        }
    }

    cout << add - ans << endl;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }
}