#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e5 + 10;
int nums[MAXN];
int zbs[MAXN];
int ans[MAXN];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;cin >> t;
    while (t--) {
        int n;cin >> n;
        for (int i = 0;i < n;++i)
            cin >> nums[i];
        iota(zbs, zbs + n, 0);
        sort(zbs, zbs + n, [&](int a, int b) {return nums[a] < nums[b];});
        int sum = 0;
        priority_queue<int> pq;
        for (int i = 0; i < n; i++)
        {
            while (!pq.empty() && sum < nums[zbs[i]]) {
                ans[pq.top()] = i - 1;
                pq.pop();
            }
            pq.push(zbs[i]);
            sum += nums[zbs[i]];
        }
        while (!pq.empty()) {
            ans[pq.top()] = n - 1;
            pq.pop();
        }
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}