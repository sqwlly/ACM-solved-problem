#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int id[maxn],dep[maxn],cnt;
int top[maxn],size[maxn],f[maxn],son[maxn];
vector<int>G[maxn];
int sum[maxn*4],tag[maxn*4];
void dfs1(int u,int fa,int deep)
{
    size[u]=1;
    dep[u]=deep;
    f[u]=fa;
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(v==fa)continue;
        dfs1(v,u,deep+1);
        size[u]+=size[v];
        if(!son[u]||size[v]>size[son[u]])
        son[u]=v;
    }
}
void dfs2(int u,int root)
{
    top[u]=root;
    id[u]=++cnt;
    if(son[u]) dfs2(son[u],root);
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(v==f[u]||v==son[u])continue;
        dfs2(v,v);
    }
}

void update(int o,int l,int r,int ql,int qr,int v)
{
    int m=(l+r)/2,ls=o*2,rs=o*2+1;
    if(tag[o]!=-1&&l!=r)
    {
        sum[ls]+=(m-l+1)*tag[o];
        sum[rs]+=(r-l)*tag[o];
        tag[ls] += tag[o];
		tag[rs] += tag[o];
        tag[o]=-1;
    }
    if(l>=ql&&r<=qr)
    {
        sum[o] +=v*(r-l+1);
        tag[o] +=v;
        return;
    }
    if(ql<=m)update(ls,l,m,ql,qr,v);
    if(qr>m)update(rs,m+1,r,ql,qr,v);
    sum[o]=sum[ls]+sum[rs];
}
int query(int o,int l,int r,int ql,int qr,int k)
{
    int m=(l+r)/2,ls=o*2,rs=o*2+1,res=0;
    if(tag[o]!=-1&&l!=r)
    {
        sum[ls]+=(m-l+1)*tag[o];
        sum[rs]+=(r-l)*tag[o];
        tag[ls]+=tag[rs]=tag[o];
        tag[o]=-1;
    }
    if(sum[o]==r-l+1)
    return min(r,qr)-max(l,ql)+1;
    if(sum[o]==0)return 0;
    if(l>=ql&&r<=qr)
    return sum[o];
    if(ql<=m)res+=query(ls,l,m,ql,qr);
    if(qr>m)res+=query(rs,m+1,r,ql,qr);
    return res;
}
int qu_path(int x,int y,int k)
{
    int res=0;
    while(top[x]!=top[y])
    {
        if(dep[top[x]]<dep[top[y]])swap(x,y);
        res+=query(1,1,cnt,id[top[x]],id[x],k);
        x=f[top[x]];
    }
    if(id[x]>id[y])swap(x,y);
    res+=query(1,1,cnt,id[x],id[y],k);
    return res;
}
void up_path(int x,int y,int z)
{
    while(top[x]!=top[y])
    {
        if(dep[top[x]]<dep[top[y]])swap(x,y);
        update(1,1,cnt,id[top[x]],id[x],z);
        x=f[top[x]];
    }
    if(id[x]>id[y])swap(x,y);
    update(1,1,cnt,id[x],id[y],z);
}

vector<pair<int,int>> p;

int main()
{
	freopen("input.in","r",stdin);
    int n,u,v,a,b,c,d,q,T,k,w = 0;
	scanf("%d",&T);
	while(T--) {
		cnt = 0;
		for(int i = 1; i <= n; ++i) G[i].clear();
		memset(sum,0,sizeof sum);
		memset(top,0,sizeof top);
		memset(size,0,sizeof size);
		memset(id,0,sizeof id);
		memset(dep,0,sizeof dep);
		memset(f,0,sizeof f);
		memset(son,0,sizeof son);
		scanf("%d",&n);
	    for(int i=1;i<n;i++)
		{
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
	    }
		scanf("%d",&q);
		memset(tag,-1,sizeof(tag));
		dfs1(1,0,1);
		dfs2(1,1);
		printf("Case %d:\n",++w);
		while(q--)
		{
			scanf("%d",&k);
			for(int i = 0; i < k; ++i) {
				scanf("%d%d",&a,&b);
				p.push_back(make_pair(a,b));
				up_path(a,b,1);
			}
			printf("%d\n",qu_path(a,b));
			for(int i = 0; i < p.size(); ++i) {
				up_path(p[i].first,p[i].second,-1);
			}
			p.clear();
		}
	}
}
