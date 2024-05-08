#include<bits/stdc++.h>
#include<bits/extc++.h>
#define int long long

using namespace std;
using namespace __gnu_pbds;

#define x first
#define y second
#define ls(i) i<<1
#define rs(i) (i<<1)|1
#define lowbit(i) (i&(-i))

constexpr int MAXN = 1e6;
unordered_map<int, int> nums, u;

using pt = pair<int, int>;
using pat = pair<pt, int>;
using int_rb_tree = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

vector<int> lj[MAXN];

bool solve() {
    int n, k;cin >> n >> k;
    if (n == 1)return true;
    for (int i = 0;i < n;++i)nums[i] = 0, u[i] = 0, lj[i].clear();
    while (k--) {
        int a, b;cin >> a >> b;
        lj[a].push_back(b);
        lj[b].push_back(a);
        nums[a]++, nums[b]++;
    }
    vector<int> leaves;
    for (int i = 0;i < n;++i)if (nums[i] == 1)
        leaves.push_back(i);
    for (int i = 0;i < leaves.size();++i) {
        int num = leaves[i];
        u[num] = 1;
        for (int nxt : lj[num])if (!u[nxt]) {
            nums[nxt]--;
            if (nums[nxt] == 1)leaves.push_back(nxt);
        }
    }
    for (int i = 0;i < n;++i)if (!u[i]) {
        int cnt = 1;
        int x = i;
        int cut = -1;
        for (int nxt : lj[x])if (!u[nxt])cut = nxt;
        if (cut == -1)return false;
        x = cut;
        u[x] = 1;
        while (x != i) {
            int cut = -1;
            for (int nxt : lj[x])if (!u[nxt])cut = nxt;
            if (cut == -1)return false;
            x = cut;
            u[x] = 1;
            cnt++;
        }
        if (cnt & 1)return false;
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << (solve() ? "true" : "false");
    return 0;
}