#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6;
int nums[MAXN];
using pt = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int w, h, k;cin >> h >> w >> k;
    vector<string> ss(h);
    for (int i = 0;i < h;++i)cin >> ss[i];

    int ans = INT_MAX;
    for (string s : ss) {
        queue<char> q;
        int cnt = 0;
        for (int i = 0;i < w;++i) {
            if (s[i] == 'x') {
                cnt = 0;
                while (!q.empty())q.pop();
                continue;
            }
            q.push(s[i]);
            if (s[i] == '.')cnt++;
            if (q.size() > k) {
                char f = q.front();q.pop();
                if (f == '.')cnt--;
            }
            if (q.size() == k)ans = min(ans, cnt);
        }
    }

    for (int j = 0; j < w;++j) {
        queue<char> q;
        int cnt = 0;
        for (int i = 0;i < h;++i) {
            if (ss[i][j] == 'x') {
                cnt = 0;
                while (!q.empty())q.pop();
                continue;
            }
            q.push(ss[i][j]);
            if (ss[i][j] == '.')cnt++;
            if (q.size() > k) {
                char f = q.front();q.pop();
                if (f == '.')cnt--;
            }
            if (q.size() == k)ans = min(ans, cnt);
        }
    }


    cout << (ans == INT_MAX ? -1 : ans);
    return 0;
}