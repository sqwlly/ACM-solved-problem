#include <bits/stdc++.h>
using namespace std;
const int Maxn = 10010, INF = 1e9+7;
struct node {
        int to,val;
        node() {
        }
        node(int a,int b)
        {
                to = a; val = b;
        }
};

vector<node> adj[Maxn],_adj[Maxn];

bool vis[Maxn];
int dis[Maxn],Y[Maxn],n,m,k;

void AddEdge(int x,int y,int val)
{
        adj[x].push_back(node(y,val));
        _adj[y].push_back(node(x,val));//把图反向
}
void Dijkstra(int s,int t)
{
        priority_queue<int, vector<int>, greater<int> > q;
        while(!q.empty()) q.pop();

        for(int i=1; i<=n; i++) vis[i] = false,dis[i] = INF;
        vis[t] = true; dis[t] = 0; q.push(t);

        int u,len;
        while(!q.empty())
        {
                u = q.top();  q.pop();
                len = _adj[u].size();
                for(int i=0; i<len; i++)
                {
                        node v = _adj[u][i];
                        if(dis[v.to] > dis[u] + v.val)
                        {
                                dis[v.to] = dis[u] + v.val;
                                if(!vis[v.to])
                                {
                                        q.push(v.to);
                                        vis[v.to] = true;
                                }
                        }
                }
                vis[u] = false;
        }
}

struct Anode {
        int h,g,id,get;
        Anode(int a,int b,int c,int d) {
                h=a; g=b; id=c; get = d;
        }
        bool operator < (Anode a) const
        {
                return h+g > a.h+a.g;
        }
};

priority_queue<Anode> pq;

int BFS(int s,int t)
{
        while(!pq.empty()) pq.pop();
        pq.push(Anode(0,dis[s],s,Y[s]));
		cout << 1 << endl;
        int len,num;
        while(!pq.empty())
        {
                Anode u = pq.top(); pq.pop();
              //  if(u.id==t) ++num;
              //  if(u.h > limit)
                //        return -1;
                if(u.id == t) return u.h;

                len = adj[u.id].size();
                for(int i=0; i<len; i++)
                {
                        node v = adj[u.id][i];
						if(u.get + Y[v.to] > k) continue;
                       // if(dis[v.to] > limit) //本题核心所在
                        pq.push(Anode(u.h+v.val,dis[v.to],v.to,u.get + Y[v.to]));
                }
        }
		cout << 0 << endl;
        return -1;
}

int main()
{
        while(~scanf("%d%d%d",&n,&m,&k))
        {

                int x,y,v,s,t,o;
                for(int i=0; i<Maxn; i++) adj[i].clear(),_adj[i].clear();
				s = 1, t = n;
				for(int i = 1; i <= n; ++i) {
					scanf("%d",&o);
					Y[i] = o;
				}
             //   scanf("%d%d%d%d",&s,&t,&k,&limit);
                for(int i=1; i<=m; i++)
                {
                        scanf("%d%d%d",&x,&y,&v);
                        AddEdge(x,y,v);
						AddEdge(y,x,v);
                }
				cout << 1 << endl;
                Dijkstra(s,t);
				cout << 2 << endl;
                int ans = BFS(s,t);
                if(ans == -1)
                        printf("-1\n");
                else{
                        printf("%d\n",ans);
                }
        }
        return 0;
}
