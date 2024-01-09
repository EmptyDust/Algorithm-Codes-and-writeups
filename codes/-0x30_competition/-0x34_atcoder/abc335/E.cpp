#include<bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 6e6;
vector<int> lj[MAXN];
int nums[MAXN], f[MAXN];

struct cmp
{
    bool operator()(int a, int b) {
        if (nums[a] == nums[b])return f[a] < f[b];
        return nums[a] > nums[b];
    }
};


signed main() {
    ios::sync_with_stdio(false);
    int n, m;cin >> n >> m;
    int u, v;
    for (int i = 0;i < n;++i)cin >> nums[i], f[i] = 0;
    while (m--) {
        cin >> u >> v;
        u--, v--;
        lj[u].push_back(v);
        lj[v].push_back(u);
    }
    f[0] = 1;
    priority_queue<int, vector<int>, cmp> que;que.push(0);
    while (!que.empty()) {
        int cut = que.top();
        que.pop();
        for (int nxt : lj[cut])if (nums[nxt] >= nums[cut] && f[nxt] < f[cut] + (nums[nxt] != nums[cut])) {
            f[nxt] = f[cut] + (nums[nxt] != nums[cut]);
            que.push(nxt);
        }
    }
    cout << f[n - 1];
    return 0;
}