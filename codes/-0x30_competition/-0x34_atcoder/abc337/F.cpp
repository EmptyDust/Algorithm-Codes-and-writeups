#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], cnt[MAXN], alcnt[MAXN], ans[MAXN];
using pt = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m, k;cin >> n >> m >> k;
    memset(alcnt, 0, sizeof alcnt);
    memset(cnt, 0, sizeof cnt);
    for (int i = 0;i < n;++i)cin >> nums[i], nums[i]--, alcnt[nums[i]]++;
    for (int i = n;i < 2 * n;++i)nums[i] = nums[i - n];
    int sum = 0, x = 0, p = 0;
    for (int pos = 0;pos < n;++pos) {
        while ((cnt[nums[p]] % k || x < m) && p < n + pos) {
            if (cnt[nums[p]] % k == 0) {
                sum += min(alcnt[nums[p]] - cnt[nums[p]], k);
                x++;
            }
            cnt[nums[p]]++;
            p++;
        }
        ans[pos] = sum;
        cnt[nums[pos]]--;
        if (cnt[nums[pos]] % k == 0) {
            sum -= min(alcnt[nums[pos]] - cnt[nums[pos]], k);
            x--;
        }
    }
    cout << endl;
    for (int i = 0;i < n;++i)cout << ans[i] << '\n';
    return 0;
}