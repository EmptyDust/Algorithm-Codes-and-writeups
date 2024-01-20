#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], nxt[MAXN], lst[MAXN];
using pt = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m, k;cin >> n >> m >> k;
    unordered_map<int, int> mp;
    for (int i = 0;i < n;++i)
        cin >> nums[i];
    for (int suf = 0, pre = 0, cnt = 0;suf < 2 * n && pre < n;++suf) {
        int& cut = mp[nums[suf % n]];
        cut++;
        if (cut % k == 1)cnt++;
        while (cnt == m) {
            int& pr = mp[nums[pre]];
            pr--, pre++;
            if (pr % k == 0)cnt--;
            cout << (suf - pre + 1) << '\n';
        }
    }

    return 0;
}