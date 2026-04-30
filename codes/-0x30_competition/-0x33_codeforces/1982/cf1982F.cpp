#include<bits/stdc++.h>

constexpr int MAXN = 1e6 + 7, inf = 1e9 + 7;
using pii = std::pair<int,int>;

struct info{
	int min;
	int max;
	info(){
		min = inf;
		max = -inf;
	}
	info(int x,int y){
		min = x;
		max = y;
	}
	info operator+ (const info& x){
		return {std::min(min,x.min),std::max(max,x.max)};
	}
}tree[MAXN << 2];

int n;
void update(int p,int x,int l = 1,int r = n,int i = 1){
	if(l > r) return;
	if(p < l || r < p) return;
	if(l == r){
		tree[i] = {x, x};
		return;
	}
	int mid = l + r >> 1;
	update(p,x,l,mid,i << 1);
	update(p,x,mid + 1,r,i << 1 | 1);
	tree[i] = tree[i << 1] + tree[i << 1 | 1];
}

info query(int ql, int qr, int l = 1, int r = n, int i = 1){
	if(l > r) return info();
	if(qr < l || r < ql)return info();
	if(ql <= l && r <= qr)return tree[i];
	int mid = l + r >> 1;
	return query(ql,qr,l,mid,i << 1) + query(ql,qr,mid + 1,r,i << 1 | 1);
}

pii cal(std::set<int> &st,std::vector<int> &vt){
	if(st.size() == 0)return {-1,-1};
	int pre = *st.begin();
	int suf = *(--st.end()) - 1;
	
}

void solve(){
	std::cin>>n;
	std::vector<int> a(n + 1);
	for(int i = 1;i <= n;++i){
		std::cin >> a[i];
		update(i, a[i]);
	}
	std::set<int> st;
	for(int i = 1;i < n;++i){
		if(a[i] < a[i - 1]){
			st.insert(i);
		}
	}
	int q;std::cin >> q;
	while(q--){
		int pos, val;
		std::cin >> pos >> val;
		update(pos, val);

	}
}

signed main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);std::cout.tie(0);
	int t;std::cin>>t;
	while(t--){
		solve();
	}
	return 0;
}