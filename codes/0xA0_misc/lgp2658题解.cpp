#include<cstdio>
#include<cstring>
#define id(i,j) ~-i*m+j//即每个点的编号，相当于(i-1)*m+j
using namespace std;
int h[501][501],f[250001],a[250001],len;//h是每个点的高度，f是并查集数组，a是需要保证联通的点，len是a数组长度
int ans,l,r,n,m,mid;
const short dx[4]={-1,0,1,0};
const short dy[4]={0,1,0,-1};
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
void add(int x,int y){f[find(x)]=find(y);return;}
int abs(int x){return x<0?-x:x;}
bool check(int high)
{
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=m;j++)f[id(i,j)]=id(i,j);//初始化
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=m;j++)
	  for(int k=0;k<4;k++)//向周围四个点连边
	  {
	  	int nx=i+dx[k],ny=j+dy[k];
	 	if(nx<1||ny<1||nx>n||ny>m) continue;//爆出范围跳过
	 	if(abs(h[i][j]-h[nx][ny])>high)continue;//超过高度跳过
	 	add(id(i,j),id(nx,ny));//连边
      }
	for(int i=1;i<len;i++) 
	if(find(a[i])!=find(a[i+1])) return false;//判断是否能联通
	return true;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) {scanf("%d",&h[i][j]);if(h[i][j]>r) r=h[i][j];}//保存最大的r
	for(int i=1;i<=n;i++) for(int j=1,t;j<=m;j++) 
	{scanf("%d",&t);if(t) a[++len]=id(i,j);}//保存
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check(mid))//判断
		{
			ans=mid;
			r=mid-1;//调整右边界
		}
		else l=mid+1;//调整左边界
	}
	printf("%d",ans);//输出
}