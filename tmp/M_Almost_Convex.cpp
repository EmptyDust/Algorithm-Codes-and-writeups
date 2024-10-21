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

// using double = __int128;

// std::istream& operator>>(std::istream& is, double& n) {
//     std::string s;is >> s;
//     n = 0;
//     for (char i : s) n = n * 10 + i - '0';
//     return is;
// }
// std::ostream& operator<<(std::ostream& os, double n) {
//     if (n == 0) {
//         return os << 0;
//     }
//     std::string s;
//     while (n) {
//         s += '0' + n % 10;
//         n /= 10;
//     }
//     std::reverse(s.begin(), s.end());
//     return os << s;
// }

namespace computation_geometry {
    using namespace std;
    //计算几何
    //点
    struct Point {
        double x, y;
        Point() {};
        Point(double x, double y) :x(x), y(y) {};

        //减法(a-b)
        Point operator-(Point& b) {
            return { this->x - b.x,this->y - b.y };
        }
        //数乘
        Point operator*(double t) const {
            return { this->x * t,this->y * t };
        }
        //向量加法
        Point operator+(Point& b) {
            return Point{ this->x + b.x,this->y + b.y };
        }
        Point operator/(double t) {
            return { this->x / t,this->y / t };
        }
    };

    //求点积(x1*x2+y1*y2)
    double dot(Point a, Point b) {
        return a.x * b.x + a.y * b.y;
    }
    //求模长
    // double len(Point a) {
    //     return sqrt(a.x * a.x + a.y * a.y);
    // }
    // //求夹角
    // double angle(Point a, Point b) {
    //     return acos(dot(a, b) / len(a) / len(b));
    // }
    //求叉积(a*b==x1*y2-x2*y1),b在a的逆时针方向值为正，否则为负
    double cross(Point b, Point a, Point c = { 0,0 }) {
        return ((a - c).x * (b - c).y) - ((a - c).y * (b - c).x);
    }
    //两点之间的距离
    double dis(Point a, Point b) {
        return sqrt(1.0 * (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    }
    //判断线线的位置关系
    //1.直线ab与线段cd无交点：cross(a,b,c)*cross(a,b,d)>0
    //2.直线ab与线段cd有交点：cross(a,b,c)*cross(a,b,d)<= 0
    //计算直线交点au与bv
    Point getNode(Point a, Point u, Point b, Point v) {
        double t = cross((a - b), v) / cross(v, u);
        u.x *= t, u.y *= t;
        return a + u;
    }
    double eps = 1e-6;Point o = { 0,0 };
    double PI = acos(-1), R;
    Point p[4];
    //三角剖分，计算多边形与圆的相交面积
    // Point rotate(Point a, double b) {//将线段旋转一定的角度
    //     return Point(a.x * cos(b) - a.y * sin(b), a.x * sin(b) + a.y * cos(b));
    // }
    // Point norm(Point a) {//单位向量
    //     return a / len(a);
    // }
    // bool onSegment(Point p, Point a, Point b) {//p在ab线段上
    //     return fabs(cross(a - p, b - p) < eps) && (dot(a - p, b - p) <= 0);
    // }
    // double getDP2(Point a, Point b, Point& pa, Point& pb) {
    //     Point e = getNode(a, b - a, o, rotate(b - a, PI / 2));//找到圆心与ab的垂足
    //     double d = dis(o, e);
    //     if (!onSegment(e, a, b)) d = std::min(dis(o, a), dis(o, b));
    //     if (R <= d) return d;
    //     double len = sqrt(R * R - dis(o, e) * dis(o, e));

    //     pa = (norm(a - b) * len) + e;
    //     pb = (norm(b - a) * len) + e;
    //     return d;//d:线段到圆心的距离；pa,pb:直线与圆的交点
    // }
    // double sector(Point a, Point b) {//扇形面积
    //     double angle = acos(dot(a, b) / len(a) / len(b));//[0,pi]
    //     if (cross(a, b) < 0) angle = -angle;
    //     return R * R * angle / 2;
    // }

    // double getArea(Point a, Point b) {//面积的交
    //     if (fabs(cross(a, b)) < eps) return 0;//ab与圆心共线
    //     double da = dis(o, a), db = dis(o, b);
    //     if (R >= da && R >= db) return cross(a, b) / 2;//ab在圆内，R为直径
    //     Point pa, pb;
    //     double d = getDP2(a, b, pa, pb);
    //     if (R <= d) return sector(a, b);//ab在圆外
    //     if (R >= da) return cross(a, pb) / 2 + sector(pb, b);//a在圆外
    //     if (R >= db) return sector(a, pa) + cross(pa, b) / 2;//b在圆内
    //     return sector(a, pa) + cross(pa, pb) / 2 + sector(pb, b);//ab是割线
    // }


    //凸包算法:Andrew算法
    Point st[N], s[N];
    std::vector<int> tubao;
    int n;
    int top;
    double Andrew() {
        sort(s + 1, s + n + 1, [&](Point a, Point b) {
            return a.x != b.x ? a.x < b.x : a.y < b.y;
            });
        for (int i = 1;i <= n;i++) {//下凸包
            while (top > 1 && cross(st[top], s[i], st[top - 1]) <= 0) top--, tubao.pop_back();
            st[++top] = s[i];
            tubao.push_back(i);
        }
        int t = top;
        for (int i = n - 1;i >= 1;i--) {//上凸包
            while (top > t && cross(st[top], s[i], st[top - 1]) <= 0) top--, tubao.pop_back();
            st[++top] = s[i];
            tubao.push_back(i);
        }
        double res = 0;//周长
        for (int i = 1;i < top;i++) {
            res += dis(st[i], st[i + 1]);
        }
        // n = top - 1;//为了配合下面的旋转卡壳，只求凸包不用加
        return res;
    }

    //旋转卡壳问题实例
    //1.给定个点，求最远点对的距离
    //先用Androw算法，求出凸包上的点数即n=top-1;
    double rotating_calipers() {//旋转卡壳
        double res = 0;
        for (int i = 1, j = 2;i <= n;i++) {
            while (cross(st[i + 1], st[j], st[i]) < cross(st[i + 1], st[j + 1], st[i])) j = j % n + 1;
            res = max(res, max(dis(st[i], st[j]), dis(st[i + 1], s[j])));
        }
        return res;
    }
    double rotating_calipers2() {//求最大四边行的面积
        double ans = 0;
        for (int i = 1;i <= n;i++) {
            int a = i, b = i + 1;//a为i到j之间的点，b为j到i之间的点
            for (int j = i + 1;j <= n;j++) {
                while (cross(st[j], st[a + 1], st[i]) < cross(st[j], st[a], st[i])) a = a % n + 1;
                while (cross(st[j], st[b + 1], st[i]) > cross(st[j], st[b], st[i])) b = b % n + 1;
                ans = max(ans, -cross(st[j], st[a], st[i]) + cross(st[j], st[b], st[i]));
            }
        }
        return ans / 2;
    }
}

void solve() {
    using namespace computation_geometry;
    std::cin >> n;int _n = n;
    std::vector<Point> pts(_n);
    for (int i = 1;i <= n;++i){
        std::cin >> s[i].x >> s[i].y;
        pts[i - 1] = s[i];
    }
    Andrew();
    {
        std::sort(pts.begin(), pts.end(), [&](auto a, auto b){
            return a.x != b.x ? a.x < b.x : a.y < b.y;
            });
        std::vector<int> vis(_n);
        for (auto& p : tubao)vis[p - 1] = 1;
        std::vector<Point> npts;
        for (int i = 0;i < _n;++i)if (!vis[i])npts.push_back(pts[i]);
        pts = npts;
    }
    // std::cout << pts.size() << '\n';
    // for (auto [l, r] : pts)std::cout << l << ' ' << r << "\n";
    std::reverse(st + 1, st + top + 1);
    // std::cout << top << '\n';
    // for (int i = 1;i <= top;++i)std::cout << st[i].x << ' ' << st[i].y << '\n';
    i64 ans = 1;
    if (pts.size()) for (int i = 1;i < top;++i){
        int j = i + 1;
        auto A = st[i], B = st[j];
        // std::cout << "####" << i << ' ' << A.x << ' ' << A.y << ' ' << ans << '\n';
        std::sort(pts.begin(), pts.end(), [&](auto a, auto b){
            return (B.x - A.x) * a.x + (B.y - A.y) * a.y < (B.x - A.x) * b.x + (B.y - A.y) * b.y;
            });
        std::vector<int> J1(pts.size()), J2(pts.size());
        J1[0] = 1;
        auto now = pts[0];
        for (int j = 1;j < pts.size();++j){
            if (cross(now, pts[j], A) > 0){
                now = pts[j];
                J1[j] = 1;
            }
        }
        J2.back() = 1;
        now = pts.back();
        for (int j = (int)pts.size() - 2;j >= 0;--j){
            if (cross(now, pts[j], B) < 0){
                now = pts[j];
                J2[j] = 1;
            }
        }
        for (int j = 0;j < pts.size();++j)if (J1[j] && J2[j]){
            // if (i == 1)std::cout << pts[j].x << ' ' << pts[j].y << '\n';
            ans++;
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
        std::cout << '\n';
    }
    return 0;
}