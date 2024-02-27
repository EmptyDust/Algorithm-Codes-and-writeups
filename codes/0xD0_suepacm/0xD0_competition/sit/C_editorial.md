
## T3 NNEZ

### 题目信息

write by [StarryKiller](https://www.luogu.com.cn/user/235125)

test by [Empty_Dust](https://www.luogu.com.cn/user/1132118),[loveyileina](https://www.luogu.com.cn/user/1216353)

难度：$\mathsf{\textcolor{orange}{普及}}$

### 题目内容
[题目链接（洛谷）](https://www.luogu.com.cn/problem/T404302)
南宁二中的社团会不定期举办随机宅舞活动。（$\mathsf{E\textcolor{red}{mpty\_Dust}}$：好看爱看）

有两支不同的宅舞，宅舞 A 有 $n$ 人会跳，宅舞 $B$ 有 $m$ 人会跳。由于一个人只会跳一支舞，所以一共有 $(n+m)$ 个人。

观众会给这 $(n+m)$ 个人的舞蹈评分。宅舞 A 的评分分别为 $a_1,a_2,\cdots,a_n$，宅舞 B 的评分分别为 $b_1,b_2,\cdots,b_m$。

$\mathsf{E\textcolor{red}{mpty\_Dust}}$ 想要邀请会跳宅舞 A 的 $i$ 和会跳宅舞 B 的 $j$ 来一起跳舞。这场舞蹈的精彩程度是 $a_i+b_j$。她想要知道，前 $k$ 大的精彩程度的和是多少。

由于答案可能很大，输出答案模 $114514191$ 之后的结果。

#### 输入格式
共 $3$ 行。

第 $1$ 行，三个整数 $n,m,k$。

第 $2$ 行，$n$ 个整数 $a_1,a_2,\cdots,a_n$。

第 $3$ 行，$m$ 个整数 $b_1,b_2,\cdots,b_m$。
#### 输出格式
共一行一个数，代表前 $k$ 大的精彩程度的和模 $114514191$ 后的结果。

### 题解
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

针对操作1进行修改。
解法2：
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
