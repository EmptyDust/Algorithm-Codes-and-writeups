#include <bits/stdc++.h>
//#define int long long
using namespace std;
#define x first
#define y second
using pt = pair<int, int>;
constexpr int MAXN = 7, inf = 1e8;
bool mp[MAXN][MAXN], n;

bool isblack(int x, int y) { return 0 <= x && x < 7 && 0 <= y && y < 7 && mp[x][y]; }

pt dir[4] = { {-1,-1},{1,-1},{1,1},{-1,1} };
bool check(int x, int y) {
    if (!isblack(x, y))return false;
    for (int i = 0;i < 4;++i)if (!isblack(x + dir[i].x, y + dir[i].y))
        return false;
    return true;
}

int cal(vector<pt> pts, int odd = -1) {
    int res = inf;
    if (odd == -1)
        odd = (pts[0].x + pts[0].y) % 2;
    int s = pts.size();
    for (int i = 0;i < s;++i)
        mp[pts[i].x][pts[i].y] = !mp[pts[i].x][pts[i].y];
    bool f = true;
    for (int x = 0;x < 7;x++)for (int y = 0;y < 7;y++)if ((x + y) % 2 == odd && check(x, y)) {
        f = false;
        break;
    }
    if (f) res = s;
    for (int i = 0;i < s;++i)
        mp[pts[i].x][pts[i].y] = !mp[pts[i].x][pts[i].y];
    return res;
}

void solve() {
    string s;
    vector<pt> odd, even;
    for (int i = 0;i < 7;++i) {
        cin >> s;
        for (int j = 0;j < 7;++j) {
            mp[i][j] = s[j] == 'B';
            if (mp[i][j]) {
                if ((i + j) % 2)odd.push_back({ i,j });
                else even.push_back({ i,j });
            }
        }
    }
    int m = cal({}, 1), n = cal({}, 0);
    int os = odd.size(), es = even.size();
    for (int a = 0;a < os;++a) {
        m = min(m, cal((vector<pt>) { odd[a] }));
        for (int b = a + 1;b < os;++b) {
            m = min(m, cal((vector<pt>) { odd[a], odd[b] }));
            for (int c = b + 1;c < os;++c) {
                m = min(m, cal((vector<pt>) { odd[a], odd[b], odd[c] }));
                for (int d = c + 1;d < os;++d) {
                    m = min(m, cal((vector<pt>) { odd[a], odd[b], odd[c], odd[d] }));
                }
            }
        }
    }
    for (int a = 0;a < es;++a) {
        n = min(n, cal((vector<pt>) { even[a] }));
        for (int b = a + 1;b < es;++b) {
            n = min(n, cal((vector<pt>) { even[a], even[b] }));
            for (int c = b + 1;c < es;++c) {
                n = min(n, cal((vector<pt>) { even[a], even[b], even[c] }));
                for (int d = c + 1;d < es;++d) {
                    n = min(n, cal((vector<pt>) { even[a], even[b], even[c], even[d] }));
                }
            }
        }
    }
    if (m == inf)m = 0;
    if (n == inf)n = 0;
    int ans = m + n;
    cout << ans;
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