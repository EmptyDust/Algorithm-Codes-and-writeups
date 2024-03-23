#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 2e5 + 10, inf = 1e8;
using pt = std::pair<int, int>;

struct ANS
{
    int ans;
    std::vector<pt> sides;
};

struct Node
{
    int min, max;
    int mex = 1;
    std::set<int> nums;
    Node() {
        min = inf;
        max = -inf;
    }
    Node(int x) {
        min = max = x;
        nums.insert(x);
        while (nums.count(mex))mex++;
    }
    int size() { return nums.size(); }
    bool empty() { return nums.empty(); }
    int count(int x) { return nums.count(x); }
};

void add(struct Node& A, struct Node& B) {
    A.min = std::min(A.min, B.min);
    A.max = std::max(A.max, B.max);
    A.mex = std::max(A.mex, B.mex);
    if (A.size() < B.size())swap(A.nums, B.nums);
    for (int num : B.nums)A.nums.insert(num);
    B.nums.clear();
    while (A.count(A.mex))A.mex++;
}

int n;
std::vector<int> adj[MAXN];
struct ANS res[MAXN];
struct Node info[MAXN];
void dfs(int x, int par) {
    int& ans = res[x].ans = adj[x].size() - 1;
    auto& sides = res[x].sides;
    info[x] = Node(x);
    std::vector<pt> tmp;
    for (int nxt : adj[x])if (nxt != par) {
        dfs(nxt, x);
        tmp.push_back({ info[nxt].min,nxt });
    }
    std::sort(tmp.begin(), tmp.end());
    struct Node A, B;
    for (auto [min, nxt] : tmp) {
        if (min == 1)add(A, info[nxt]);
        else if (min == x + 1)add(B, info[nxt]);
        else {
            sides.push_back({ min,min - 1 });
            if (A.count(min - 1))add(A, info[nxt]);
            else if (B.count(min - 1))add(B, info[nxt]);
            else add(info[x], info[nxt]);
        }
    }
    if (x == n)return;
    if (!B.empty()) {
        sides.push_back({ B.max,B.max + 1 });
        add(info[x], B);
    }
    if (!A.empty()) {
        if (A.max != x - 1)sides.push_back({ A.max,A.max + 1 });
        else if (A.mex == x && A.size() == x - 1)sides.push_back({ x - 1,x + 1 }), ans++;
        else sides.push_back({ A.mex,A.mex - 1 });
        add(info[x], A);
    }
};

void solve() {
    std::cin >> n;
    for (int i = 1;i <= n;++i) {
        adj[i].clear();
        res[i] = {};
        info[i] = {};
    }
    for (int i = 1;i < n;++i) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(n, -1);
    for (int i = 1;i <= n;++i) {
        std::cout << res[i].ans << ' ' << res[i].sides.size() << '\n';
        for (auto [u, v] : res[i].sides) {
            std::cout << u << ' ' << v << '\n';
        }
        std::cout << '\n';
    }
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