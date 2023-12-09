#include <bits/stdc++.h>
using namespace std;
#define vector point

struct point
{
    double x;
    double y;
    point operator -(point B) {
        return { x - B.x,y - B.y };
    }
};

double cross(point a, point b)
{
    return a.x * b.y - b.x * a.y;
}
//判断相交
bool intersection(point a, point b, point c, point d)
{
    if (max(c.x, d.x) < min(a.x, b.x) || max(a.x, b.x) < min(c.x, d.x) || max(c.y, d.y) < min(a.y, b.y) || max(a.y, b.y) < min(c.y, d.y)) {
        return false;
    }
    if (cross(a - d, c - d) * cross(b - d, c - d) > 0 || cross(d - b, a - b) * cross(c - b, a - b) > 0) {
        return false;
    }
    return true;
}
//计算位置
inline void pos(point a, point b, point c, point d) {
    if (intersection(a, b, c, d)) {
        vector w = c - d;
        vector v = a - b;
        vector u = a - c;
        double t = cross(w, u) / cross(v, w);
        point ans = { a.x + t * v.x,a.y + t * v.y };
        cout << ans.x << ' ' << ans.y << '\n';
    }
    else {
        cout << "qvq" << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;cin >> n;
    while (n--) {
        point a, b, c, d;
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
        pos(a, b, c, d);
    }
    return 0;
}