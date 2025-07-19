
//
//   ____      _                           _          _    __     ____     ___    ____    _____ 
//  |  _ \    (_)   __ _   _ __     __ _  | |   ___  / |  / /_   |___ \   ( _ )  | ___|  |___  |
//  | | | |   | |  / _` | | '_ \   / _` | | |  / _ \ | | | '_ \    __) |  / _ \  |___ \     / / 
//  | |_| |   | | | (_| | | | | | | (_| | | | |  __/ | | | (_) |  / __/  | (_) |  ___) |   / /  
//  |____/   _/ |  \__,_| |_| |_|  \__, | |_|  \___| |_|  \___/  |_____|  \___/  |____/   /_/   
//          |__/                   |___/                                                        
//
//  [题目链接] ： 
//
//  [题目名称] ： 
//
//  [  做法  ] ： 
//
#include <bits/stdc++.h>

#define int __int128_t
#define fir first
#define sec second
#define el '\n'
#define all(x) (x).begin(), (x).end()
#define FINISH cout << "FINISH" << endl;
#define debug(x) cout << #x << " :== " << x << endl;
#define debugv(x)\
    cout << #x << " :: ";\
    for (auto v : x) cout << v << " ";\
    cout << endl;

using namespace std;
typedef long long ll;
typedef pair<int, int> PII;

const int mod = 998244353;
const int inf32 = 0x3f3f3f3f;
const ll inf64 = 0x3f3f3f3f3f3f3f3f;

using ld = long double;
const ld PI = 3.14159265358979323846L;

struct point {
    int x, y;
};


int cross_product(point O, point A, point B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

bool is_inside_hull(point p, const vector<point>& hull) {
    if (hull.size() < 3) {
        return false;
    }

    int n = hull.size();
    for (int i = 0; i < n; ++i) {
        point p1 = hull[i];
        point p2 = hull[(i + 1) % n];

        if (cross_product(p1, p2, p) < 0) {
            return false;
        }
    }

    return true;
}

ld dis(int x, int y)
{
    return sqrtl(x * x + y * y);
}

ld getangle(point A, point B)
{
    int x1 = A.x, y1 = A.y;
    int x2 = B.x, y2 = B.y;

    int dot = x1 * x2 + y1 * y2;
    int cross = x1 * y2 - y1 * x2;

    ld COS = dot / (dis(x1, y1) * dis(x2, y2));

    COS = min(COS, 1.000L);
    COS = max(COS, -1.000L);

    ld theta = acosl(COS);

    if (cross < 0)
        theta = 2 * PI - theta;

    // cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    // cout << theta << endl; 
    return theta;
}

void solve()
{

    ll n, x, y;
    cin >> n >> x >> y;
    vector<point> a(n);
    int mx = -1;

    auto sqr = [&](int r) -> ll
        {
            return 1ll * r * r;
        };

    for (int i = 0; i < n; i++) {
        ll X, Y;
        cin >> X >> Y;
        a[i].x = X, a[i].y = Y;
        a[i].x -= x, a[i].y -= y;
        if (sqr(a[i].x) + sqr(a[i].y) > mx) {
            mx = sqr(a[i].x) + sqr(a[i].y);
        }
    }
    vector<int> v;
    for (int i = 0; i < n; i++) {
        if (sqr(a[i].x) + sqr(a[i].y) == mx) {
            v.push_back(i);
        }
    }
    // debugv(v);
    // std::cout << is_inside_hull(point(0, 0), a) << '\n';
    if (v.size() == 1 || !is_inside_hull(point(0, 0), a)) {
        cout << fixed << setprecision(15) << PI * 2 << endl;
        return;
    }
    ld ans = 0;
    for (int i = 0; i < v.size(); i++) {
        int nxt = i == (v.size() - 1) ? 0 : i + 1;
        // debug(i);
        // debug(nxt);
        ans = max(ans, getangle(a[v[i]], a[v[nxt]]));
    }

    cout << fixed << setprecision(15) << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

