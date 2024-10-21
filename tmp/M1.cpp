#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

namespace computation_geometry {
    using namespace std;
    //计算几何
    //点
    struct Point {
        i64 x, y;
        Point() {};
        Point(i64 x, i64 y) :x(x), y(y) {};

        //减法(a-b)
        Point operator-(Point& b) {
            return { this->x - b.x,this->y - b.y };
        }
        //数乘
        Point operator*(i64 t) const {
            return { this->x * t,this->y * t };
        }
        //向量加法
        Point operator+(Point& b) {
            return Point{ this->x + b.x,this->y + b.y };
        }
        Point operator/(i64 t) {
            return { this->x / t,this->y / t };
        }
        bool operator==(const Point& b)const{
            return this->x == b.x && this->y == b.y;
        }
        bool operator<(const Point& b)const{
            if (this->x == b.x)return this->y < b.y;
            return this->x < b.x;
        }
        void print(){
            std::cout << "Point:" << x << ' ' << y << '\n';
        }
    };

    struct Edge
    {
        Point a, b;

        bool operator==(const Edge& y)const{
            return this->a == y.a && this->b == y.b;
        }
        bool operator<(const Edge& y)const{
            if (this->a == y.a)return this->b < y.b;
            return this->a < y.a;
        }
    };


    //求点积(x1*x2+y1*y2)
    i64 dot(Point a, Point b) {
        return a.x * b.x + a.y * b.y;
    }
    //求模长
    i64 len(Point a) {
        return sqrt(a.x * a.x + a.y * a.y);
    }
    //求夹角
    i64 angle(Point a, Point b) {
        return acos(dot(a, b) / len(a) / len(b));
    }
    //求叉积(a*b==x1*y2-x2*y1),b在a的逆时针方向值为正，否则为负
    i64 cross(Point b, Point a, Point c = { 0,0 }) {
        return ((a - c).x * (b - c).y) - ((a - c).y * (b - c).x);
    }
    i64 get_dir(Point c, Point m){
        c = c - m;
        if (c.x > 0 && c.y == 0)return 0;
        if (c.x > 0 && c.y > 0)return 1;
        if (c.x == 0 && c.y > 0)return 2;
        if (c.x < 0 && c.y > 0)return 3;
        if (c.x < 0 && c.y == 0)return 4;
        if (c.x < 0 && c.y < 0)return 5;
        if (c.x == 0 && c.y < 0)return 6;
        if (c.x > 0 && c.y < 0)return 7;
        return 8;
    }
    //两点之间的距离
    i64 dis(Point a, Point b) {
        return sqrt(1.0 * (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    }
    //判断线线的位置关系
    //1.直线ab与线段cd无交点：cross(a,b,c)*cross(a,b,d)>0
    //2.直线ab与线段cd有交点：cross(a,b,c)*cross(a,b,d)<= 0
    //计算直线交点au与bv
    Point getNode(Point a, Point u, Point b, Point v) {
        i64 t = cross((a - b), v) / cross(v, u);
        u.x *= t, u.y *= t;
        return a + u;
    }
    i64 eps = 1e-6;Point o = { 0,0 };
    i64 PI = acos(-1), R;
    Point p[4];
    //三角剖分，计算多边形与圆的相交面积
    Point rotate(Point a, i64 b) {//将线段旋转一定的角度
        return Point(a.x * cos(b) - a.y * sin(b), a.x * sin(b) + a.y * cos(b));
    }
    Point norm(Point a) {//单位向量
        return a / len(a);
    }
    bool onSegment(Point p, Point a, Point b) {//p在ab线段上
        return fabs(cross(a - p, b - p) < eps) && (dot(a - p, b - p) <= 0);
    }
    i64 getDP2(Point a, Point b, Point& pa, Point& pb) {
        Point e = getNode(a, b - a, o, rotate(b - a, PI / 2));//找到圆心与ab的垂足
        i64 d = dis(o, e);
        if (!onSegment(e, a, b)) d = std::min(dis(o, a), dis(o, b));
        if (R <= d) return d;
        i64 len = sqrt(R * R - dis(o, e) * dis(o, e));

        pa = (norm(a - b) * len) + e;
        pb = (norm(b - a) * len) + e;
        return d;//d:线段到圆心的距离；pa,pb:直线与圆的交点
    }
    i64 sector(Point a, Point b) {//扇形面积
        i64 angle = acos(dot(a, b) / len(a) / len(b));//[0,pi]
        if (cross(a, b) < 0) angle = -angle;
        return R * R * angle / 2;
    }

    i64 getArea(Point a, Point b) {//面积的交
        if (fabs(cross(a, b)) < eps) return 0;//ab与圆心共线
        i64 da = dis(o, a), db = dis(o, b);
        if (R >= da && R >= db) return cross(a, b) / 2;//ab在圆内，R为直径
        Point pa, pb;
        i64 d = getDP2(a, b, pa, pb);
        if (R <= d) return sector(a, b);//ab在圆外
        if (R >= da) return cross(a, pb) / 2 + sector(pb, b);//a在圆外
        if (R >= db) return sector(a, pa) + cross(pa, b) / 2;//b在圆内
        return sector(a, pa) + cross(pa, pb) / 2 + sector(pb, b);//ab是割线
    }

    std::vector<Point> points;
    void addPoint(Point& p){
        points.push_back(p);
    }
    std::vector<Point> convex;
    std::vector<int> pos;
    //凸包算法:Andrew算法
    void Andrew() {
        int n = points.size();
        sort(points.begin(), points.end(), [&](const Point& a, const Point& b) {
            return a.x != b.x ? a.x < b.x : a.y < b.y;
            });
        for (int i = 0;i < n;i++) {//下凸包
            while (convex.size() > 1 && cross(convex.back(), points[i], convex[convex.size() - 2]) <= 0) convex.pop_back(), pos.pop_back();
            convex.push_back(points[i]);
            pos.push_back(i);
        }
        int t = convex.size();
        for (int i = n - 2;i >= 0;i--) {//上凸包
            while (convex.size() > t && cross(convex.back(), points[i], convex[convex.size() - 2]) <= 0) convex.pop_back(), pos.pop_back();
            convex.push_back(points[i]);
            pos.push_back(i);
        }
        // i64 res = 0;//周长
        // for (int i = 0;i < convex.size() - 1;i++) {
        //     res += dis(points[i], points[i + 1]);
        // }
        // return res;
    }
}

void solve() {
    using namespace computation_geometry;

    int n;std::cin >> n;
    for (int i = 0;i < n;++i){
        Point p;std::cin >> p.x >> p.y;
        addPoint(p);
    }
    Andrew();
    std::vector<int> vis(n);
    for (int p : pos)vis[p] = 1;
    std::vector<Point> in;
    for (int i = 0;i < n;++i)
        if (!vis[i])
            in.push_back(points[i]);
    std::set<Edge> st;
    for (int i = 0;i < convex.size() - 1;++i){
        st.insert(Edge{ convex[i],convex[i + 1] });
    }
    i64 ans = 1;
    for (auto& p : in){
        std::vector<Point> np;np.reserve(n - 1);
        for (auto& x : points)if (p != x)np.push_back(x);
        auto first = np[0];
        sort(np.begin(), np.end(), [&](const Point& a, const Point& b){
            if (get_dir(a, p) != get_dir(b, p))return get_dir(a, p) > get_dir(b, p);
            return cross(a, b, p) > 0;
            });
        for (int i = 0;i < n - 1;++i){
            if (st.count({ np[i],np[(i + 1) % (n - 1)] })){
                ans++;
            }
        }
    }
    std::cout << ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}