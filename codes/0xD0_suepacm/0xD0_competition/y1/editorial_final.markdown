# 上海电力大学程序设计迎新赛题解 by suepacm

## T1 First Meet

### 题目信息

written by [StarryKiller](https://www.luogu.com.cn/user/235125)

tested by [Empty_Dust](https://www.luogu.com.cn/user/1132118)，[loveyileina](https://www.luogu.com.cn/user/1216353)

难度：$\mathsf{\textcolor{red}{入门}}$

### 题目内容
[题目链接（洛谷）](https://www.luogu.com.cn/problem/T404594)

给定正整数 $v_1$，请找到 $1\leq v_2\leq v_1$，最小化 $\gcd(v_1,v_2)$，若有多解则最大化 $v_2$。输出 $v_2$。

多组数据。$T\leq 10^6,1\leq v_1\leq 10^{18}$。

### 题解

#### 算法 1

我会暴力！

由 $v_1$ 从大到小找，利用辗转相除法寻找最大公约数。

#### 算法 2

我们有如下的性质。

$\forall n\in \mathbb{Z}, n\geq 2$，$\gcd(n,n-1)=1$。

于是直接输出 $n-1$ 即可。注意特判 $n=1$ 的情况。


## T2 Stars in the sky
### 题目信息

written by [StarryKiller](https://www.luogu.com.cn/user/235125)

tested by [Empty_Dust](https://www.luogu.com.cn/user/1132118)

难度：$\mathsf{\textcolor{orange}{普及-}}$

### 题目内容

给定数列 $a$。

设 $cnt_0(l,r)$ 为 $a$ 中 $[l,r]$ 内 $0$ 的个数，$cnt_1(l,r)$ 同理。

给定 $p,q$，求出 $r-l+1$ 最大的区间 $[l,r]$（$p\leq l\leq r\leq q$），使得 $cnt_0(l,r)=cnt_1(l,r)$。

多组数据，$T\leq 5$，$n\leq 5\times 10^5$。

### 题解

#### 算法 1

我会暴力！

枚举下标 $i,j$，再枚举一次统计 $0/1$ 数量即可。可以通过子任务 $1$，期望得分 $5$。

时间复杂度 $\mathcal{O}(n^3)$

### 算法 2

我会前缀和！

我们记 $sum[0/1,i]$ 表示 $1\sim i$ 中 $0$ 或 $1$ 的数量。

于是 $cnt_0(l,r)=sum[0,r]-sum[0,l-1]$，对于 $1$ 同理。

时间复杂度 $\mathcal{O}(n^2)$，可以通过子任务 $1,2$，期望得分 25。

#### 算法 3

我们不妨把 $0$ 改成 $-1$，这样我们注意到 $[l,r]$ 内 $1$ 和 $-1$ 个数相等 $\iff$ $[l,r]$ 区间和为 $0$。

求出改动后对应的前缀和数组 $s$，从小到大扫描 $i$。我们扫描到 $i$ 时，若发现 $s_i$ 已经出现过了，且 $s_i$ 对应的下标为 $j$，则 $[j+1,i]$ 是一个符合答案的区间。（思考：为什么是 $j+1$？）

然后就做完了。注意前缀和可以有负数，可以开一个桶或者用 map 存。

## T3 NNEZ

### 题目信息

written by [StarryKiller](https://www.luogu.com.cn/user/235125)

tested by [Empty_Dust](https://www.luogu.com.cn/user/1132118),[loveyileina](https://www.luogu.com.cn/user/1216353)

难度：$\mathsf{\textcolor{orange}{普及}}$

### 题目内容
[题目链接（洛谷）](https://www.luogu.com.cn/problem/T404302)

给定长度为 $n$ 的数列 $a$ 和长度为 $m$ 的数列 $b$。将 $a$ 中的元素 与 $b$ 中的元素两两相加可以组成 $nm$ 个数，求出按降序排列后前 $k$ 个数的和模 $114514191$。

$n,m,k\leq 10^6$，$k\leq n\times m$。

### 题解

#### 算法 1

我会暴力！

求出这 $nm$ 个数，sort 之后统计前 $k$ 个的和即可。

#### 算法 2：堆排
设 $i$ 为数组 $a$ 的下标，$j$ 为数组 $b$ 的下标，$sum_{i,j}=a_i+b_j$ 。

显而易见的，每一个 $sum$ 都可以与唯一的二元组 $(i,j)$ 组成一个三元组 $(i,j,sum_{i,j})$ ,因此，我们只需要将它们以 $sum$ 的大小关系排序即可。

堆/优先队列是一个能在 $O(n \log n)$ 时间复杂度内完成这一目标的数据结构。

因此，我们可以：
1. 边计算边取模，防止在计算过程中越界。
2. 使用结构体简化思考。
3. 先对两个数组**由大到小排序**。

朴素地思考到，对每个 $sum_{i,j}$ ,略小的必然是 $sum_{i+1,j}$ 或 $sum_{i,j+1}$ 。

此时，显然 $sum_{max} = sum_{0,0}$ ，次大的显然是 $max\{sum_{0,1},sum_{1,0}\}$ ,不妨设 $sum_{0,1}>sum_{1,0}$ ,则第三大的是 $max\{sum_{1,1},sum_{1,0},sum_{0,2}\}$ 。

我们注意到，如果此时 $sum_{1,0}$ 是最大值，那么简单地将 $sum_{1,1}$ 和 $sum_{2,0}$ 放入堆中，会造成重复的问题。

因此我们需要
1. 将所有 $(a_i,0)$ 数对都先加入堆。(来自 $StarryKiller$ 的思路)
2. 维护一个 $j$ 指针记录当前已经加入堆的 $b$ 数组下表。

```cpp
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e6+7;
const int mod =114514191;//9810好臭
int a[MAXN];
int b[MAXN];
struct Node
{
    int i;
    int j;
    int value;
    bool operator()(Node x,Node y){
        return x.value<y.value;
    }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    signed n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<m;++i)cin>>b[i];
    sort(a,a+n);
    sort(b,b+m);
    reverse(a,a+n);
    reverse(b,b+m);
    priority_queue<Node,vector<Node>,Node> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push({i,0,a[i]+b[0]});
    }
    int sum = 0;
    for(signed i=0;i<k;++i){
        Node cut = pq.top();
        pq.pop();
        sum+=cut.value%mod;
        sum%=mod;
        if(cut.j<m-1){
            pq.push({cut.i,cut.j+1,a[cut.i]+b[cut.j+1]});
        }
    }
    cout<<sum;
    return 0;
}
//by Empty_Dust 得分：100
```

#### 算法 3：记录下标的堆排
针对操作1进行修改。
对每个 $a_i,b_j$ 多记录一个值 $nxt$ ，存放已经遍历到的对方数组下标。
这里有一道类似题目和它使用该方法的题解。
[[atcoder abc311] E Meal](https://atcoder.jp/contests/abc331/tasks/abc331_e)
```cpp
#include <bits/stdc++.h>
//#define int long long
using namespace std;
const int MAXN = 100010;

int n, m, l;

struct meal
{
    int index;
    int v;
    int nxt = 0;
}a[MAXN], b[MAXN];

struct query {
    int ai;
    int bi;
    int sum;
    bool operator()(query a, query b) {
        return a.sum < b.sum;
    }
};

priority_queue < query, vector<query>, query> pq;
vector<int> ph[MAXN];

void pt(int x, int y) {
    if (x >= n || y >= m || x < b[y].nxt || y < a[x].nxt)
        return;
    query tmp;
    tmp.ai = x;
    tmp.bi = y;
    tmp.sum = a[x].v + b[y].v;
    pq.push(tmp);
    a[x].nxt++;
    b[y].nxt++;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> l;
    for (int i = 0;i < n;++i) {
        a[i].index = i;
        cin >> a[i].v;
    }
    for (int i = 0;i < m;++i) {
        b[i].index = i;
        cin >> b[i].v;
    }
    while (l--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        ph[x].push_back(y);
    }
    sort(a, a + n, [&](meal a, meal b) {return a.v > b.v;});
    sort(b, b + m, [&](meal a, meal b) {return a.v > b.v;});
    for (int i = 0;i < n;++i)
        sort(ph[i].begin(), ph[i].end());
    pt(0, 0);
    while (!pq.empty()) {
        int cai = pq.top().ai;
        int cbi = pq.top().bi;
        int ca = a[cai].index;
        int cb = b[cbi].index;
        auto lb = lower_bound(ph[ca].begin(), ph[ca].end(), cb);
        if (lb == ph[ca].end() || *lb != cb) {
            cout << pq.top().sum;
            return 0;
        }
        pt(cai, cbi + 1);
        pt(cai + 1, cbi);
        pq.pop();
    }
    return 0;
};
//by Empty_Dust AC
```

## T4 Life, the Universe, and Everything

### 题目信息

written by [StarryKiller](https://www.luogu.com.cn/user/235125)

tested by [Empty_Dust](https://www.luogu.com.cn/user/1132118)

难度：$\mathsf{\textcolor{green}{提高}}$


### 题目内容
[题目链接(洛谷)](https://www.luogu.com.cn/problem/T404381)

维护一个序列，支持区间覆盖和区间颜色段查询。

颜色段的定义：极长的连续相同色彩。

例如 `AABBBDB` 中有 $4$ 个颜色段。

### 题解

#### 算法 1

我会暴力！

暴力复杂度是 $\mathcal{O}(nm)$ 的，可以通过子任务 $1$，期望得分 $25$。

#### 算法 2

我会线段树！

我们对于每个节点，维护 $lc$、$rc$ 为当前节点最左边和最右边的颜色，$cnt$ 表示当前节点内有几段颜色。

作为递归边界，在叶子上时 $lc=rc=a_i$，$cnt=1$。

对于合并，我们只需要简单将两个子节点的 $cnt$ 相加。如果左儿子的 $rc$ 和右儿子的 $lc$ 相等，将 $cnt$ 减去 $1$。

查询类似地特判即可。

可通过子任务 $2$，结合算法 1 期望得分 $50$。

#### 算法 3

我会 lazy-tag！

我们对于每个节点维护一个覆盖标记。

然后记得 pushdown。就做完了。



## T5 游戏

### 题目信息

written by [StarryKiller](https://www.luogu.com.cn/user/235125)

难度：$\mathsf{\textcolor{green}{提高}}$

分类：模拟

### 题目内容
[题目链接(洛谷)](https://www.luogu.com.cn/problem/T404393)
你已经解决了四道题目了。接下来的问题关于一个游戏。

这个游戏在一个 $n$ 行 $m$ 列的方格上进行。方格有三种类型，分别为硬地，软地和禁地。

有一个长和宽都为 $1$、高为 $2$ 的箱子，起初**可能立在或躺在**起点上。

我们定义箱子的状态：

- 立着：箱子以 $1\times 1$ 的接触面接触地面。

- 躺着：箱子以 $1\times 2$（或者 $2\times 1$）的接触面接触地面。

箱子不能立在软地上；箱子的任何部分不能接触禁地，也不能超出格子边界。

每次操作，箱子可以向上、下、左、右沿着对应的棱滚动 $90$ 度，目标是用最少的操作次数，让箱子**立在**终点上。

请你帮助 **Empty_Dust** 求出这个最少的操作次数，让她赢下和 **Starrykiller** 的对局。

#### 输入格式
本题有不定组数据，当出现 $n=m=0$ 时代表输入结束。这组数据无需被处理。

第一行为 $n,m$，含义见题面。

接下来 $n$ 行，第 $i$ 行第 $j$ 个字符描述格子 $(i,j)$：

- $\texttt{.}$ 代表硬地。

- $\texttt{E}$ 代表软地。

- $\texttt{\#}$ 代表禁地。

- $\texttt{X}$ 代表起点。

- $\texttt{O}$ 代表终点。

地图上可能出现一个 $\texttt{X}$ 或者两个相邻的 $\texttt{X}$，分别表示箱子立着或者躺着。

起点和终点均可视为硬地。

#### 输出格式
对于每组数据，如果有解，输出一行一个整数，表示最小步数。

否则输出 `Impossible`。

### 题解

#### 算法 1：bfs
难点在于如何记录已经走过的位置。

```cpp
#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e2+10;
char a[MAXN][MAXN]; int n, m;

// cur=0 箱子立在(x,y)上
// cur=1 箱子躺在(x,y)上，另一格在(x,y+1)
// cur=2 箱子躺在(x,y)上，另一格在(x+1,y)

int atx[]={0,0,1};
int aty[]={0,1,0}; // 另一个格子在哪

// 四个方向分别是：上、右、下、左（按照数学中笛卡尔坐标系的坐标轴方向）

int dx[][4]={
    {0,1,0,-2},
    {0,1,0,-1}, // cur=1
    {0,2,0,-1}  // cur=2
};
int dy[][4]={
    {1,0,-2,0},
    {2,0,-1,0},
    {1,0,-1,0}
};
int dcur[][4]={
    {1,2,1,2},
    {0,1,0,1},
    {2,0,2,0}
};

struct node {
    int x, y;
    int cur, step;
    node(int a, int b, int c, int d=0): x(a), y(b), cur(c), step(d) {}
};

int tx, ty;

bool operator ==(node a, node b) {
    return a.x==b.x && a.y==b.y && a.cur==b.cur;
}


int vis[MAXN][MAXN][5];

int bfs(node s) {
    queue<node> q; q.push(s); vis[s.x][s.y][s.cur]=1;
    while (q.size()) {
        auto u=q.front(); q.pop();
        for (int i=0; i<4; ++i) {
            int c=u.cur, x=u.x, y=u.y;
            int nx=x+dx[c][i], ny=y+dy[c][i], nc=dcur[c][i];
            int nx2=nx+atx[nc], ny2=ny+aty[nc];
            if (a[nx][ny]=='#' || a[nx2][ny2]=='#') continue;
            if (nx<1 || nx>n || nx2<1 || nx2>n) continue;
            if (ny<1 || ny>m || ny2<1 || ny2>m) continue;
            if (nc==0&&a[nx][ny]=='E') continue;
            if (vis[nx][ny][nc]) continue;
        	vis[nx][ny][nc]=1;    
            node v={nx,ny,nc,int(u.step+1)};
            q.push(v);
            if (v==node(tx,ty,0)) {
                return v.step;
            }
        }
    }
    return -1;
}

signed main() {    
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
    int x[3], y[3], tot;
    while (cin>>n>>m && n && m) {
        memset(vis,0,sizeof vis);
        tot=0;
        for (int i=1; i<=n; ++i)
            for (int j=1; j<=m; ++j) {
                cin>>a[i][j];
                if (a[i][j]=='X') {
                    x[++tot]=i, y[tot]=j;
                    a[i][j]='.';
                }
                else if (a[i][j]=='O') {
                    tx=i, ty=j;
                    a[i][j]='.';
                }
            }
        node u={0,0,0};
        if (tot==1) u={x[1],y[1],0};
        else {
            if (x[1]==x[2]) u={x[1],y[1],1};
            else u={x[1],y[1],2};
        }
        int res=bfs(u);
        if (res!=-1) cout<<res<<'\n';
        else cout<<"Impossible\n";
    }
}   
//by StarryKiller 得分：100
```