#include <bits/stdc++.h>
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
using ull = unsigned long long;

const int mod = 998244353;
const int inf = 0x3f3f3f3f;
const int p1 = 998244353;
const int p2 = 1e9 + 9;

struct pii{
    ll x, y;
    bool operator == (const pii &b) {
        return x == b.x && y == b.y;
    }
    pii operator + (const pii &b) {
        return {(x + b.x) % p1, (y + b.y) % p2};
    }
    pii operator * (const pii &b) {
        return {x * b.x % p1, y * b.y % p2};
    }
    pii operator - (const pii &b) {
        return {(x - b.x + p1) % p1, (y - b.y + p2) % p2};
    }
    pii operator + (ll t) {
        return {(x + t) % p1, (y + t) % p2};
    }
    bool operator < (const pii &r) {
        if(x == r.x)
            return y < r.y;
        return x < r.x;
    }
}B={233,1331};

const ull mask = 1145141919810;

ull shift(ull x) {
  x ^= mask;
  x ^= x << 13;
  x ^= x >> 7;
  x ^= x << 17;
  x ^= mask;
  return x;
}

void solve() 
{
    int n;
    cin >> n;
    vector<vector<int>>edge(n + 1);
    vector<int> siz(n + 1, 0), parent(n + 1, 0);
    for (int i = 1; i < n; i++) {
    	int x, y;
    	cin >> x >> y;
    	edge[x].push_back(y);
    	edge[y].push_back(x);
    }
    int mnval = n + 1;
    auto getroot = [&] (auto &self, int x, int fa) -> void
    {
        parent[x] = fa;
    	siz[x] = 1;
    	int nowmx = 0;
    	for (auto to : edge[x]) {
    		if (to == fa)
    			continue;
    		self(self, to, x);
    		siz[x] += siz[to];
    		nowmx = max(nowmx, siz[to]);
    	}
        if (x != 1)
    	   nowmx = max(nowmx, n - siz[x]);

    	mnval = min(mnval, nowmx);
    };
    getroot(getroot, 1, 0);
    vector<int> rt;
    for (int x = 1; x <= n; x++) {
        int nowmx = 0;
        pii nowhash = {0, 0};
        for (auto to : edge[x]) {
            if (to == parent[x])
                continue;
            nowmx = max(nowmx, siz[to]);
        }
        nowmx = max(nowmx, n - siz[x]);
        if (nowmx == mnval) {
            rt.push_back(x);
        }
    }
    
    // debugv(rt);
    vector<ull> hs(n + 1);
    auto gethash = [&] (auto &self, int x, int fa) -> ull {
        hs[x] = 1;
        for (auto to : edge[x]) {
            if (to == fa)
                continue;
            self(self, to, x);
            hs[x] += hs[to];
        }
        return hs[x];
    };


    int root = rt[0];
    if (rt.size() == 2) {
        ull hash1 = gethash(gethash, rt[0], 0);
        ull hash2 = gethash(gethash, rt[1], 0);

        if (hash1 < hash2) {
            root = rt[1];
        }
    }

    // debug(root);

    gethash(gethash, root, 0);
    vector<pii> pw(n + 1);

    vector<pii> val(n + 1, {0, 0});
    auto getval = [&] (auto &self, int x, int fa) -> void {
        pii res = {hs[x] % p1, hs[x] % p2};
        val[x] = val[fa] * B + res;
        for (auto to : edge[x]) {
            if (to == fa)
                continue;
            self(self, to, x);
        }
    };
    getval(getval, root, 0);
    // for (int i = 1; i <= n; i++) {
    //     debug(i);
    //     cout << hs[i].x << " " << hs[i].y << endl;
    // }
    // for (int i = 1; i <= n; i++) {
    //     debug(i);
    //     cout << val[i].x << " " << val[i].y << endl;
    // }

    auto getans = [&] (auto &self, int x, int fa) -> void {
        cout << x << " " ;
        vector<int> v;
        for (auto to : edge[x]) {
            if (to == fa)
                continue;
            v.push_back(to);
        }
        sort(v.begin(), v.end(), [&] (int x, int y) {
            if(val[x].x == val[y].x)
                return val[x].y < val[y].y;
            return val[x].x < val[y].x;
        });
        for (auto to : v) {
            self(self, to, x);
        }
    };
    getans(getans, root, 0);
    cout << el;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
