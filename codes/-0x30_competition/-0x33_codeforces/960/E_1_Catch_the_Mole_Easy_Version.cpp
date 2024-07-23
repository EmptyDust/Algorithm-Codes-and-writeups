#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;
std::vector<int> adj[MAXN];
bool vis[MAXN];
int F[MAXN];
std::vector<int> line;

int visit_size = 0;
void visit(int x) {
    vis[x] = 0;
    visit_size--;
}

void init(int n) {
    line.clear();
    line.push_back(1);
    visit_size = n;
    for (int i = 1;i <= n;++i) {
        adj[i].clear();
        vis[i] = 1;
        F[i] = 0;
    }
}

void initdfs(int x) {
    for (auto y : adj[x])if (y != F[x]) {
        F[y] = x;
        initdfs(y);
    }
}

int cj, id_c;
int dfs(int x) {
    int cnt = 1;
    for (auto y : adj[x])if (y != F[x] && vis[y]) {
        cnt += dfs(y);
    }
    // std::cout << x << ' ' << cnt << '\n';
    if (cj > std::abs(cnt - visit_size / 2) && visit_size != cnt) {
        cj = std::abs(cnt - visit_size / 2);
        id_c = x;
    }
    return cnt;
}

int root = 1;
void work() {
    cj = inf;
    id_c = -1;
    dfs(root);
}

void clear1(int x) {
    while (x) {
        int Fa = F[x];
        for (auto y : adj[Fa])if (y != x && y != F[Fa]) {
            visit(y);
        }
        x = F[x];
    }
}

std::vector<int> leaves;
void dfsleave(int x) {
    int cnt = 0;
    for (auto y : adj[x])if (y != F[x] && vis[y]) {
        dfsleave(y);
        cnt++;
    }
    if (cnt == 0 && x != 1) {
        leaves.push_back(x);
    }
}

void clear0(int x) {
    visit(x);
    leaves.clear();
    dfsleave(root);
    for (int x : leaves) {
        // std::cout << x << ' ';
        visit(x);
    }
}

int question(int x) {
    std::cout << "? " << x << std::endl;
    int ret;std::cin >> ret;
    return ret;
}

void answer(int x) {
    std::cout << "! " << x << std::endl;
}

bool dfsline(int x) {
    int cnt = 0;
    for (auto y : adj[x])if (y != F[x] && vis[y]) {
        cnt++;
    }
    if (cnt >= 2)return false;
    if (x != root)
        line.push_back(x);
    for (auto y : adj[x])if (y != F[x] && vis[y]) {
        if (!dfsline(y))return false;
    }
    return true;
}

bool isaline() {
    bool ret = dfsline(root);
    root = line.back();
    visit(F[root]);
    return ret;
}

void solve() {
    int n;std::cin >> n;
    init(n);
    for (int i = 1;i < n;++i) {
        int u, v;std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    initdfs(1);

    // std::cout << isaline();
    // clear0(2);
    // if (!isaline()) {
    //     work();
    //     if (question(id_c))clear1(id_c);
    //     else clear0(id_c);
    // }

    while (!isaline()) {
        work();
        if (question(id_c))clear1(id_c);
        else clear0(id_c);
    }
    int l = 0, r = line.size() - 1;
    int ans = 0;
    while (l <= r) {
        auto mid = l + r >> 1;
        int res = question(line[mid]);
        if (res) {
            l = mid + 1;
            ans = mid;
        }
        else {
            r = mid - 2;
            l = std::max(l - 1, 0);
        }
    }
    answer(line[ans]);
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}