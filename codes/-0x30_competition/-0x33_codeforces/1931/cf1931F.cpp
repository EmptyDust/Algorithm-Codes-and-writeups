#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6 + 10;
int n, k;
using pt = pair<int, int>;

bool query(vector<vector<int>>& nums, int x) {
    vector<int> ans(nums[x]);
    int f = ans[0];
    for (int i = 0;i < k;++i) {
        for (int j = 1, cut = 1;j < n && cut < n;++j, ++cut)if (ans[cut] != nums[i][j]) {
            if (nums[i][j] == f) {
                cut--;
            }
            else if (ans[cut] == nums[i][0]) {
                j--;
            }
            else
                return false;
        }
    }
    return true;
}

bool solve() {
    cin >> n >> k;
    vector<vector<int>> nums(k, vector<int>(n));
    for (int i = 0;i < k;++i)for (int j = 0;j < n;++j)cin >> nums[i][j];
    if (k == 1)return true;
    if (!(query(nums, 0) && query(nums, 1)))
        return false;
    if (k == 2)return true;
    bool f;
    for (int j = 1;j < n;++j) {
        if (nums[2][j] == nums[0][0]) {
            f = 0;
            break;
        }
        if (nums[2][j] == nums[1][0]) {
            f = 1;
            break;
        }
    }
    //cout << nums[f][0] << endl;
    for (int i = 1, j = 1;nums[!f][i] != nums[f][0];++i, ++j)if (nums[f][j] != nums[!f][i]) {
        //cout << nums[f][j] << nums[!f][i] << endl;
        return false;
    }
    return query(nums, 2);
}

signed main() {
    ios::sync_with_stdio(false);
    int t;cin >> t;
    while (t--) {
        cout << (solve() ? "YES" : "NO");
        cout << '\n';
    }
    return 0;
}