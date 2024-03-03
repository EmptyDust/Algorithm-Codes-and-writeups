#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 2e5 + 10;
int nums[MAXN], n;
using pt = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    vector<int> sqs;
    int n;cin >> n;
    int num;
    int ans = 0, cnt = 0;
    for (int i = 0;i < n;++i) {
        cin >> num;
        if (num == 0) {
            ans += n - 1 - cnt;
            cnt++;
            continue;
        }
        int tmp = 1;
        for (int i = 2;i <= sqrt(num);++i)if (num % i == 0) {
            int cnt = 0;
            while (num % i == 0) {
                cnt++;
                num /= i;
            }
            if (cnt & 1)tmp *= i;
        }
        if (num >= 2)tmp *= num;
        //cout << tmp << ' ';
        nums[tmp]++;
    }
    for (int num : nums) {
        ans += num * (num - 1) / 2;
    }
    cout << ans;
    return 0;
}