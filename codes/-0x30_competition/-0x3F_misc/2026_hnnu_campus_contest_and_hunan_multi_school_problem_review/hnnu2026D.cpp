#include <bits/stdc++.h>
using namespace std;
#define vec point

struct Rnd {
    mt19937_64 eng;
    Rnd() : eng((uint64_t)chrono::steady_clock::now().time_since_epoch().count()) {}
    long long next(long long l, long long r) {
        uniform_int_distribution<long long> dist(l, r);
        return dist(eng);
    }
} rnd;

int sgn(long long x) {
    if (x < 0)
        return -1;
    else if (x > 0)
        return 1;
    else
        return 0;
}
struct point {
    int x, y;
    point() {}
    point(int x2, int y2) {
        x = x2, y = y2;
    }
    point operator+(const point &s) const {
        return (point){x + s.x, y + s.y};
    }
    point operator-(const point &s) const {
        return (point){x - s.x, y - s.y};
    }
    bool operator<(point b) const {
        return sgn(x - b.x) == 0 ? sgn(y - b.y) < 0 : x < b.x;
    }
};
inline long long cross(vec s, vec t) {
    return 1ll * s.x * t.y - 1ll * s.y * t.x;
}
void Convex_Hull(vector<point> P, vector<point> &res, int flag = 1) {
    int n = P.size();
    res.resize(0);
    res.resize(n * 2);
    sort(P.begin(), P.end());
    int now = -1;
    for (int i = 0; i < (int)P.size(); i++) {
        while (now > 0 && sgn(cross(res[now] - res[now - 1], P[i] - res[now - 1])) < flag)
            now--;
        res[++now] = P[i];
    }
    int pre = now;
    for (int i = n - 2; i >= 0; i--) {
        while (now > pre && sgn(cross(res[now] - res[now - 1], P[i] - res[now - 1])) < flag)
            now--;
        res[++now] = P[i];
    }
    res.resize(now);
}

static vector<point> gen_points(int n, long long r) {
    vector<point> pts;
    pts.reserve(n);
    set<pair<int, int>> used;
    while ((int)pts.size() < n) {
        int x = rnd.next(-r, r);
        int y = rnd.next(-r, r);
        if (x * x + y * y > r * r)
            continue;
        if (used.insert({x, y}).second)
            pts.push_back(point{x, y});
    }
    shuffle(pts.begin(), pts.end(), rnd.eng);
    return pts;
}

void solve() {
    int n = 200000;
    int r = 1000000000;
    vector<point> p = gen_points(n, r);
    vector<point> res;
    Convex_Hull(p, res);
    vector<long long> ans;
    ans.resize(n);
    std::cout << res.size() << '\n';
    // assert(res.size() < std::sqrt(n));
    for (int i = 0; i < n; i++) {
        long long mx = 0;
        for (int j = 0; j < (int)res.size(); j++) {
            for (int k = j + 1; k < (int)res.size(); k++) {
                mx = max(mx, abs(cross(res[j] - p[i], res[k] - p[i])));
            }
        }
        ans[i] = mx;
    }
    // std::cout<<ans[0]<<'\n';
    for (auto x : ans)
        std::cout << x << ' ';
}

int main() {
    solve();
}

/*

000
001
010
011
100
101


*/