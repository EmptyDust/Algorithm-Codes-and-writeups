#include <bits/stdc++.h>
using namespace std;

using point_t = long double;  //全局数据类型，可修改为 long long 等

constexpr point_t eps = 1e-8;
constexpr long double PI = 3.1415926535897932384l;

// 点与向量
template<typename T> struct point
{
    T x, y;

    bool operator==(const point& a) const { return (abs(x - a.x) <= eps && abs(y - a.y) <= eps); }
    bool operator<(const point& a) const { if (abs(x - a.x) <= eps) return y < a.y - eps; return x < a.x - eps; }
    bool operator>(const point& a) const { return !(*this < a || *this == a); }
    point operator+(const point& a) const { return { x + a.x,y + a.y }; }
    point operator-(const point& a) const { return { x - a.x,y - a.y }; }
    point operator-() const { return { -x,-y }; }
    point operator*(const T k) const { return { k * x,k * y }; }
    point operator/(const T k) const { return { x / k,y / k }; }
    T operator*(const point& a) const { return x * a.x + y * a.y; }  // 点积
    T operator^(const point& a) const { return x * a.y - y * a.x; }  // 叉积，注意优先级
    int toleft(const point& a) const { const auto t = (*this) ^ a; return (t > eps) - (t < -eps); }  // to-left 测试
    T len2() const { return (*this) * (*this); }  // 向量长度的平方
    T dis2(const point& a) const { return (a - (*this)).len2(); }  // 两点距离的平方

    // 涉及浮点数
    long double len() const { return sqrtl(len2()); }  // 向量长度
    long double dis(const point& a) const { return sqrtl(dis2(a)); }  // 两点距离
    long double ang(const point& a) const { return acosl(max(-1.0l, min(1.0l, ((*this) * a) / (len() * a.len())))); }  // 向量夹角
    point rot(const long double rad) const { return { x * cos(rad) - y * sin(rad),x * sin(rad) + y * cos(rad) }; }  // 逆时针旋转（给定角度）
    point rot(const long double cosr, const long double sinr) const { return { x * cosr - y * sinr,x * sinr + y * cosr }; }  // 逆时针旋转（给定角度的正弦与余弦）
};

using Point = point<point_t>;

template<typename T> struct line
{
    point<T> p, v;  // p 为直线上一点，v 为方向向量

    bool operator==(const line& a) const { return v.toleft(a.v) == 0 && v.toleft(p - a.p) == 0; }
    int toleft(const point<T>& a) const { return v.toleft(a - p); }  // to-left 测试

    // 涉及浮点数
    point<T> inter(const line& a) const { return p + v * ((a.v ^ (p - a.p)) / (v ^ a.v)); }  // 直线交点
    long double dis(const point<T>& a) const { return abs(v ^ (a - p)) / v.len(); }  // 点到直线距离
    point<T> proj(const point<T>& a) const { return p + v * ((v * (a - p)) / (v * v)); }  // 点在直线上的投影
};

using Line = line<point_t>;

struct Circle
{
    Point c;
    long double r;

    bool operator==(const Circle& a) const { return c == a.c && abs(r - a.r) <= eps; }
    long double circ() const { return 2 * PI * r; }  // 周长
    long double area() const { return PI * r * r; }  // 面积

    // 点与圆的关系
    // -1 圆上 | 0 圆外 | 1 圆内
    int is_in(const Point& p) const { const long double d = p.dis(c); return abs(d - r) <= eps ? -1 : d < r - eps; }

    // 过圆外一点圆的切线
    vector<Line> tangent(const Point& a) const
    {
        const int t = is_in(a);
        if (t == 1) return vector<Line>();
        if (t == -1)
        {
            const Point v = { -(a - c).y,(a - c).x };
            return vector<Line>{{a, v}};
        }
        Point e = a - c; e = e / e.len() * r;
        const long double costh = r / c.dis(a), sinth = sqrt(1 - costh * costh);
        const Point t1 = c + e.rot(costh, -sinth), t2 = c + e.rot(costh, sinth);
        return vector<Line>{{a, t1 - a}, { a,t2 - a }};
    }
};

long double du(Line& a) {
    Point t = a.v + a.p;
    long double ans = atan2(t.y, t.x);
    if (ans < 0) {
        ans += 2 * PI;
    }
    return ans;
}

long double du(Point& t) {
    long double ans = atan2(t.y, t.x);
    if (ans < 0) {
        ans += 2 * PI;
    }
    return ans;
}

int sgn(double x){
    if (fabs(x) < eps) return 0;//判断x是否等于0
    else return x < 0 ? -1 : 1;     //判断x是正数还是负数
}

void solve() {
    int n, x0, y0;
    long double d, t;
    Point O = { 0, 0 };
    cin >> n >> x0 >> y0;
    Point st = { (point_t)x0, (point_t)y0 };
    cin >> d >> t;
    vector<Point> tubao;
    for (int i = 1; i <= n; i++) {
        int x, y;   cin >> x >> y;
        tubao.push_back({ (point_t)x, (point_t)y });
    }
    vector<long double> dushu;
    for (int i = 0; i < n; i++) {
        Circle C = { tubao[i], d };
        auto line = C.tangent(O);
        dushu.push_back(du(line[0]));
        dushu.push_back(du(line[1]));
    }

    long double max = 0, ld = 0, rd = 0;
    for (int i = 0; i < dushu.size(); i++) {
        for (int j = i + 1; j < dushu.size(); j++) {
            long double d1 = dushu[i], d2 = dushu[j];
            long double d = abs(d1 - d2);
            if (d >= PI) {
                if (d1 < d2)    swap(d1, d2);
                d = 2 * PI - d1 + d2;
            }
            else {
                if (d1 > d2)    swap(d1, d2);
                d = d2 - d1;
            }
            if (d > max) {
                ld = d1, rd = d2;
                max = d;
            }
        }
    }
    long double ans = 0, v = max;
    ans += floor(t / (2 * PI)) * v;
    while (t >= 2 * PI) {
        t -= 2 * PI;
    }
    long double now = du(st);
    if (ld < rd) {
        while (t > 0) {
            if (t > 0 && sgn(now - ld) <= 0) {
                double need_t = ld - now;
                now = ld;
                t -= need_t;
            }

            if (t > 0 && sgn(now - ld) >= 0 && sgn(now - rd) <= 0) {
                long double s = min(rd - now, t);
                ans += s;
                t -= rd - now;
                now = rd;
            }

            if (t > 0) {
                long double s = 2 * PI - now;
                t -= s;
                now = 0;
            }
        }

    }
    else {
        while (t > 0) {
            if (t > 0 && sgn(now - rd) <= 0) {
                double s = min(rd - now, t);
                ans += s;
                t -= rd - now;
                now = rd;
            }
            if (t > 0 && sgn(now - ld) <= 0) {
                double need_t = ld - now;
                now = ld;
                t -= need_t;
            }
            if (t > 0 && sgn(now - ld) >= 0) {
                long double s = min(2 * PI - now, t);
                ans += s;
                t -= 2 * PI - now;
                now = 0;
            }
        }
    }
    cout << fixed << setprecision(12) << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}