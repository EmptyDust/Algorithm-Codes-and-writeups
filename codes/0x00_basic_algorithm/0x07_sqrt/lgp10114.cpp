#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 2e6;
int nums[MAXN], nmi = 0;
unordered_map<int, int> cnt;

int cal(int x) {
    int ret = 0;
    while (x) { ++ret; x -= x & -x; }
    return ret;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, tmp;cin >> n;
    for (int i = 0;i < n;++i) {
        cin >> tmp;
        cnt[tmp]++;
        if (cnt[tmp] == 1)nums[nmi++] = tmp;
    }
    int res = 0;
    for (int i = 0;i < nmi;++i)
        for (int j = 0;j < nmi;++j)
            res += cnt[nums[i]] * cnt[nums[j]] * (cal(nums[i] + nums[j]) + cal(abs(nums[i] - nums[j])));
    cout << res;
    return 0;
}