

#include <bits/stdc++.h>

#define out(x) cout << #x << '=' << (x) << endl
#define out2(x, y) cout << #x << '=' << (x) << ',' << #y << '=' << (y) << endl 
#define no do { cout << "No" << endl; return; } while(0)
#define yes do { cout << "Yes" << endl; return; } while (0)
#define lowbit(x) ((x) & -(x))

using namespace std;

using ll = long long;

const ll inf = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;

template<typename T> ostream& operator << (ostream& out, const set<T>& obj) { out << "set(";for (auto it = obj.begin();it != obj.end();it++) out << (it == obj.begin() ? "" : ", ") << *it;out << ")";return out; }
template<typename T1, typename T2> ostream& operator << (ostream& out, const map<T1, T2>& obj) { out << "map(";for (auto it = obj.begin();it != obj.end();it++) out << (it == obj.begin() ? "" : ", ") << it->first << ": " << it->second;out << ")";return out; }
template<typename T1, typename T2> ostream& operator << (ostream& out, const pair<T1, T2>& obj) { out << "<" << obj.first << ", " << obj.second << ">";return out; }
template<typename T> ostream& operator << (ostream& out, const vector<T>& obj) { out << "vector(";for (auto it = obj.begin();it != obj.end();it++) out << (it == obj.begin() ? "" : ", ") << *it;out << ")";return out; }


void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> root(n + 1), dist(n + 1);
    vector<vector<vector<int>>> dep(n + 1);
    int c = 0;
    function<void(int, int)> dfs0 = [&](int u, int fa) -> void {
        for (int v : g[u]) {
            if (v == fa) continue;
            dist[v] = dist[u] + 1;
            if (dist[v] > dist[c]) c = v;
            dfs0(v, u);
        }
        };
    function<void(int, int, int)> dfs1 = [&](int u, int r, int d) -> void {
        if (root[u]) return;
        root[u] = r;
        while (dep[r].size() <= d) dep[r].emplace_back();
        dep[r][d].push_back(u);
        for (int v : g[u]) dfs1(v, r, d + 1);
        };
    for (int i = 1; i <= n; i++) {
        if (root[i]) continue;
        c = i;
        dfs0(i, 0);
        dfs1(c, c, 0);
    }

    vector<int> ext1, ext2;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (root[i] == i) {
            if (dep[i].size() == 2) {
                for (int val : dep[i][0]) ext1.push_back(val);
                for (int val : dep[i][1]) ext2.push_back(val);
                cnt++;
            }
            if (dep[i].size() == 3) {
                for (int val : dep[i][0]) ext1.push_back(val);
                for (int val : dep[i][1]) ext2.push_back(val);
                for (int val : dep[i][2]) ext1.push_back(val);
                cnt++;
            }
        }
    }
    auto output = [&](int u) -> void {
        if (root[u] != u || dep[u].size() == 2 || dep[u].size() == 3) return;
        int t = dep[u].size();
        vector<int> output1, output2;
        for (int i = t - 1; i >= 0; i--) {
            if (i % 2) {
                for (int val : dep[u][i]) output1.push_back(val);
            }
            else {
                for (int val : dep[u][i]) output2.push_back(val);
            }
        }
        for (int val : output1) cout << val << ' ';
        for (int val : output2) cout << val << ' ';
        };
    if (cnt != 1) {
        for (int val : ext1) cout << val << ' ';
        for (int val : ext2) cout << val << ' ';
        for (int i = 1; i <= n; i++) output(i);
        cout << endl;
        return;
    }
    else {
        int ext = -1;
        for (int i = 1; i <= n; i++) {
            if (root[i] == i && dep[i].size() != 2 && dep[i].size() != 3) {
                ext = i;
            }
        }
        if (ext == -1) {
            cout << -1 << endl;
            return;
        }
        for (int val : ext1) cout << val << ' ';
        for (int i = 1; i <= n; i++) output(i);
        for (int val : ext2) cout << val << ' ';
        cout << endl;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
}