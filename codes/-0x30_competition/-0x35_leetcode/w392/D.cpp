#include<bits/stdc++.h>
using namespace std;
constexpr int S = 30;

struct dsu {
    vector<int> d;
    vector<int> st;
    dsu(int n) {
        d.assign(n, 0);
        st.assign(n, ((int)1 << 30) - 1);
        iota(d.begin(), d.end(), 0);
    }
    int get_root(int x) { return d[x] = (x == d[x] ? x : get_root(d[x])); };
    void merge(int u, int v, int w) {
        if (get_root(u) != get_root(v)) {
            st[get_root(v)] &= st[get_root(u)];
            d[get_root(u)] = get_root(v);
        }
        int rt = get_root(u);
        st[rt] &= w;
    }
    int solve(int x) {
        return st[get_root(x)];
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        dsu* d = new dsu(n);
        for (auto edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            d->merge(u, v, w);
        }
        vector<int> ans;
        for (auto q : query) {
            int s = q[0], t = q[1];
            if (s == t)ans.push_back(0);
            else if (d->get_root(s) != d->get_root(t))ans.push_back(-1);
            else ans.push_back(d->solve(s));
        }
        return ans;
    }
};