#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 2e6;
int nums[MAXN];
using pt = pair<int, int>;

void solve() {
    int n;cin >> n;
    for (int i = 0;i < n;++i)cin >> nums[i];
    int pre = nums[0];
    int cnt = 0, sum = 0;
    deque<pt> dq;
    vector<bool> has(n + 1, false);
    for (int i = 0;i < n;++i) {
        has[nums[i]] = true;
        while (has[cnt])cnt++;
        dq.push_back({ cnt,1 });
        sum += cnt;
    }
    int ret = sum;
    for (int i = 0;i < n;++i) {
        pt cut = { nums[i],0 };
        sum -= dq.front().first;
        dq.front().second--;
        if (!dq.front().second)dq.pop_front();
        while (!dq.empty() && dq.back().first >= nums[i]) {
            sum -= dq.back().first * dq.back().second;
            cut.second += dq.back().second;
            dq.pop_back();
        }
        sum += cut.first * cut.second;
        sum += n;
        dq.push_back(cut);
        dq.push_back({ n,1 });
        ret = max(sum, ret);
    }
    cout << ret;
}

signed main() {
    ios::sync_with_stdio(false);
    int t;cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
    return 0;
}